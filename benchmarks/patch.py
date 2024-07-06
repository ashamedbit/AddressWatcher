import os
import pathlib
import re
import subprocess
import sys
from lxml import etree as et
from lxml.etree import Element, XMLParser, parse

ns = {"src": "http://www.srcML.org/srcML/src", "cpp": "http://www.srcML.org/srcML/cpp"}

def run_srcml(target, out, lib_src=None):
    path_output = pathlib.Path(out)
    
    result = subprocess.run(
        ["srcml", target, "--position", "-o", out], stderr=subprocess.PIPE
    )

def get_pos_row_col(element: et.Element, event: str):
    """Returns [row,col] from srcML position start attribute or [-1,-1] if the
    attribute is not present"""

    row_num = -1
    col_num = -1
    if (
        event == "start"
        and "{http://www.srcML.org/srcML/position}start" in element.attrib
    ):
        srcml_pos = element.attrib["{http://www.srcML.org/srcML/position}start"].split(
            ":"
        )
        row_num = int(srcml_pos[0])
        col_num = int(srcml_pos[1])
    elif (
        event == "end" and "{http://www.srcML.org/srcML/position}end" in element.attrib
    ):
        srcml_pos = element.attrib["{http://www.srcML.org/srcML/position}end"].split(
            ":"
        )
        row_num = int(srcml_pos[0])
        col_num = int(srcml_pos[1])

    return [row_num, col_num]

def identify_patch_line(alloc_funcs, patch_funcs):
    alloc_funcs =  list(reversed(alloc_funcs))
    patch_funcs =  list(reversed(patch_funcs))
    alloc_len = len(alloc_funcs)
    patch_len = len(patch_funcs)

    if (alloc_len -1 > patch_len):
        return patch_funcs[-1].split(" ")[-1]
    
    fix_level = -1
    for i, alloc_func in enumerate(alloc_funcs):
        if i >= len(patch_funcs):
            break
        if alloc_funcs[i].split(" ")[-2] == patch_funcs[i].split(" ")[-2]:
            fix_level += 1
    
    return patch_funcs[fix_level].split(" ")[-1]


def run_line_srcml_return_vars(line):
    f = open("in.c", "w")
    f.write(line)
    f.close()
    run_srcml("in.c", "out.xml")
    p = XMLParser()
    tree = parse("out.xml", parser=p)
    name_nodes =  tree.xpath(".//src:expr//src:name", namespaces = ns)
    vars = set()
    for name in name_nodes:
        vars.add("".join(name.itertext()))
    return vars



def identify_patch_vars(patch_funcs):
     for patch_func in patch_funcs:
        use_file = patch_func.split(" ")[-1].split(":")[0]
        use_location = patch_func.split(" ")[-1].split(":")[1]

        if not os.path.isfile("./benchmarks/" + use_file):
            continue

        f2 = open("./benchmarks/" + use_file, "r")
        src_lines = f2.readlines()
        use_line = src_lines[int(use_location) - 1]
        return run_line_srcml_return_vars(use_line)


for file_path in sys.argv[1:]:
    f = open(file_path, "r")
    lines = f.readlines()
    patch_stacktrace = 0
    leak_stacktrace = 0
    patch_lines = []
    patch_funcs = []

    alloc_lines = []
    alloc_funcs = []

    malloc_vars = []
    used_vars = []
    
    for line in lines:
        if "The last read/write to this leaked memory over all runs happened at:" in line:
            patch_stacktrace = 1
            continue
        
        if "AddressWatcher tracking the followed leak:" in line:
            leak_stacktrace = 1
            continue

        if ".c:" in line:
            if patch_stacktrace == 1:
                patch_funcs.append(line)
            if leak_stacktrace == 1:
                if "#1" in line:
                    alloc_lines.append(line.split(" ")[-1])
                alloc_funcs.append(line)
        else:
            if "#" not in line:
                if patch_stacktrace == 1:
                    patch_stacktrace = 0 
                    patch_lines.append(identify_patch_line(alloc_funcs, patch_funcs))
                    used_vars.append(identify_patch_vars(patch_funcs))
                if leak_stacktrace == 1:
                    leak_stacktrace = 0
        

    
    for alloc_line in alloc_lines:
        alloc_file = alloc_line.split(":")[0]
        alloc_lineno = int(alloc_line.split(":")[1])
        f1 = open("./benchmarks/" + alloc_file, "r")
        src_lines = f1.readlines()
        malloc_line = src_lines[int(alloc_lineno) - 1]
        malloc_var = malloc_line.split('=')[0].strip()
        malloc_vars.append(malloc_var)


    
    for i, patch_line in enumerate(patch_lines):
        patch_file = patch_line.split(":")[0]
        patch_lineno = int(patch_line.split(":")[1])
        f1 = open("./benchmarks/" + patch_file, "r")
        src_lines = f1.readlines()
        last_use_line = src_lines[patch_lineno - 1]

        # Find var to free
        free_var = ""
        malloc_var = malloc_vars[i]
        used_variables = sorted(list(used_vars[i]))
        
        if malloc_var in last_use_line:
            free_var = malloc_var
        else:
            for var in used_variables:
                if var in last_use_line:
                    free_var = var
                    break
        
        run_srcml("./benchmarks/" + patch_file, "out.xml")
        p = XMLParser()
        tree = parse("out.xml", parser=p)
        while_nodes =  tree.xpath(".//src:while", namespaces = ns)
        if_nodes = tree.xpath(".//src:if_stmt", namespaces = ns)
        newpatch_lineno = patch_lineno
        for while_node in while_nodes:
            start_row_num, _ = get_pos_row_col(while_node,"start")
            end_row_num, _ = get_pos_row_col(while_node,"end")
            if (patch_lineno <= end_row_num and patch_lineno >= start_row_num):
                newpatch_lineno = max(end_row_num + 1, newpatch_lineno)
        
        for if_node in if_nodes:
            start_row_num, _ = get_pos_row_col(if_node,"start")
            end_row_num, _ = get_pos_row_col(if_node,"end")
            if (patch_lineno <= end_row_num and patch_lineno >= start_row_num):
                newpatch_lineno = max(end_row_num + 1, newpatch_lineno)
        
        patch_lineno = newpatch_lineno

        src_lines_new = " ".join(src_lines[:patch_lineno] + ["\tfree(" + free_var + "); // AW FIX_LOCATION\n"] + src_lines[patch_lineno:])
        f3 = open("./benchmarks/" + patch_file, "w")
        f3.write(src_lines_new)
        f3.close()