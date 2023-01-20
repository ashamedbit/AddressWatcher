import time
import os

command = "~/mem_leak/goodgcc/bin/gcc -ggdb -fno-builtin "
asan_command = "~/mem_leak/goodgcc/bin/gcc -fsanitize=address -ggdb -fno-builtin "

def run_repo(repo):
    tic = time.perf_counter()
    for root, dirs, files in os.walk(os.curdir):
        for file in files:
            if not(file.endswith(".cil.c")) and file.endswith(".c"):
                path = os.path.join(root, file)
                if "leak_" in path:
                    if repo in path:
                        fullcommand = command + path
                        print(fullcommand)
                        os.system(fullcommand)
                        os.system("./a.out")
                        os.system("./a.out")
    toc = time.perf_counter()
    withoutASAN = toc-tic

    tic = time.perf_counter()
    os.environ["LD_LIBRARY_PATH"] = "$LD_LIBRARY_PATH:/home/aniruddhan/mem_leak/goodgcc/lib64"
    os.environ["ASAN_OPTIONS"] = "log_path=/home/aniruddhan/mem_leak/testing/asan:halt_on_error=0:detect_leaks=1"
    for root, dirs, files in os.walk(os.curdir):
        for file in files:
            if not(file.endswith(".cil.c")) and file.endswith(".c"):
                path = os.path.join(root, file)
                if "leak_" in path:
                    if repo in path:
                        fullcommand = asan_command + path
                        print(fullcommand)
                        os.system(fullcommand)
                        os.system("./a.out")
                        os.system("./a.out")
    toc = time.perf_counter()
    withASAN = toc-tic

    os.system("rm asan*")

    tic = time.perf_counter()
    os.environ["LD_LIBRARY_PATH"] = "$LD_LIBRARY_PATH:/home/aniruddhan/mem_leak/goodgcc/lib64"
    os.environ["ASAN_OPTIONS"] = "log_path=/home/aniruddhan/mem_leak/testing/asan:halt_on_error=0:detect_leaks=1:address_watcher=1"
    for root, dirs, files in os.walk(os.curdir):
        for file in files:
            if not(file.endswith(".cil.c")) and file.endswith(".c"):
                path = os.path.join(root, file)
                if "leak_" in path:
                    if repo in path:
                        fullcommand = asan_command + path
                        print(fullcommand)
                        os.system(fullcommand)
                        os.system("./a.out")
                        os.system("./a.out")
                        if os.path.isfile("asan.WatchAddr.a.out"):
                            os.remove("asan.WatchAddr.a.out")
    toc = time.perf_counter()
    withAW = toc-tic

    # for root, dirs, files in os.walk(os.curdir):
    #     for file in files:
    #         if file.startswith("asan."):
    #             path = file

    # os.system("rm asan*")
    
    print("The elapsed time without ASAN is : " + str(withoutASAN))
    print("The elapsed time with ASAN is : " + str(withASAN))
    print("The elapsed time with AW is : " + str(withAW))
    print("Percentage increase over base is: " + str((withAW-withoutASAN)/(withoutASAN)))
    print("Percentage increase over ASAN is: " + str((withAW-withASAN)/(withASAN)))


# run_repo("git")
# run_repo("openssl")
run_repo("binutils")
# run_repo("tmux")
# run_repo("openssh-portable")
                    