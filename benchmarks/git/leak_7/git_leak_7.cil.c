/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 218 "../git.h"
typedef unsigned long long uintmax_t;
#line 219 "../git.h"
typedef uintmax_t timestamp_t;
#line 255 "../git.h"
struct object_id {
   unsigned char hash[20] ;
};
#line 267 "../git.h"
struct object {
   unsigned int parsed : 1 ;
   unsigned int type : 3 ;
   unsigned int flags : 27 ;
   struct object_id oid ;
};
#line 274 "../git.h"
struct tree {
   struct object object ;
   void *buffer ;
   unsigned long size ;
};
#line 307
struct commit;
#line 307 "../git.h"
struct commit_list {
   struct commit *item ;
   struct commit_list *next ;
};
#line 312 "../git.h"
struct commit {
   struct object object ;
   void *util ;
   unsigned int index ;
   timestamp_t date ;
   struct commit_list *parents ;
   struct tree *tree ;
};
#line 364 "../git.h"
struct object_array_entry {
   struct object *item ;
   char *name ;
   char *path ;
   unsigned int mode ;
};
#line 364 "../git.h"
struct object_array {
   unsigned int nr ;
   unsigned int alloc ;
   struct object_array_entry *objects ;
};
#line 483 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 161 "../git.h"
extern int ( /* missing proto */  st_mult)() ;
#line 174
extern int ( /* missing proto */  strdup)() ;
#line 22 "git_leak_7.c"
static char object_array_slopbuf[1]  ;
#line 35
extern int ( /* missing proto */  xrealloc)() ;
#line 24 "git_leak_7.c"
void add_object_array_with_path(struct object *obj , char const   *name , struct object_array *array ,
                                unsigned int mode , char const   *path ) 
{ 
  unsigned int nr ;
  unsigned int alloc ;
  struct object_array_entry *objects ;
  struct object_array_entry *entry ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 28
  nr = array->nr;
#line 29
  alloc = array->alloc;
#line 30
  objects = array->objects;
#line 33
  if (nr >= alloc) {
#line 34
    alloc = (alloc + 32U) * 2U;
#line 35
    tmp = st_mult(sizeof(*objects), alloc);
#line 35
    tmp___0 = xrealloc(objects, tmp);
#line 35
    objects = (struct object_array_entry *)tmp___0;
#line 36
    array->alloc = alloc;
#line 37
    array->objects = objects;
  }
#line 39
  entry = objects + nr;
#line 40
  entry->item = obj;
#line 41
  if (! name) {
#line 42
    entry->name = (char *)((void *)0);
  } else
#line 43
  if (! *name) {
#line 45
    entry->name = object_array_slopbuf;
  } else {
#line 47
    tmp___1 = strdup(name);
#line 47
    entry->name = (char *)tmp___1;
  }
#line 48
  entry->mode = mode;
#line 49
  if (path) {
#line 50
    tmp___2 = strdup(path);
#line 50
    entry->path = (char *)tmp___2;
  } else {
#line 52
    entry->path = (char *)((void *)0);
  }
#line 53
  nr ++;
#line 53
  array->nr = nr;
#line 54
  return;
}
}
#line 56 "git_leak_7.c"
void add_object_array(struct object *obj , char const   *name , struct object_array *array ) 
{ 


  {
#line 58
  add_object_array_with_path(obj, name, array, 12288U, (char const   *)((void *)0));
#line 59
  return;
}
}
#line 80
extern int ( /* missing proto */  memset)() ;
#line 90
extern int ( /* missing proto */  parse_object)() ;
#line 116
extern int ( /* missing proto */  tree_is_complete)() ;
#line 61 "git_leak_7.c"
static int commit_is_complete(struct commit *commit ) 
{ 
  struct object_array study ;
  struct object_array found ;
  int is_incomplete ;
  int i ;
  struct commit *c ;
  struct commit_list *parent ;
  int tmp ;
  struct commit *p ;
  struct commit *c___0 ;
  int tmp___0 ;

  {
#line 65
  is_incomplete = 0;
#line 69
  if (commit->object.flags & 1U) {
#line 70
    return (1);
  }
#line 71
  if (commit->object.flags & (1U << 10)) {
#line 72
    return (0);
  }
#line 80
  memset(& study, 0, sizeof(study));
#line 81
  memset(& found, 0, sizeof(found));
#line 82
  add_object_array(& commit->object, (char const   *)((void *)0), & study);
#line 83
  add_object_array(& commit->object, (char const   *)((void *)0), & found);
#line 84
  commit->object.flags |= 1U << 11;
#line 85
  while (study.nr) {
#line 89
    (study.nr) --;
#line 89
    c = (struct commit *)(study.objects + study.nr)->item;
#line 90
    if (! c->object.parsed) {
#line 90
      tmp = parse_object(& c->object.oid);
#line 90
      if (! tmp) {
#line 91
        c->object.flags |= 1U << 10;
      }
    }
#line 93
    if (c->object.flags & (1U << 10)) {
#line 94
      is_incomplete = 1;
#line 95
      break;
    } else
#line 97
    if (c->object.flags & 1U) {
#line 98
      continue;
    }
#line 99
    parent = c->parents;
#line 99
    while (parent) {
#line 100
      p = parent->item;
#line 101
      if (p->object.flags & (1U << 11)) {
#line 102
        goto __Cont;
      }
#line 103
      p->object.flags |= 1U << 11;
#line 104
      add_object_array(& p->object, (char const   *)((void *)0), & study);
#line 105
      add_object_array(& p->object, (char const   *)((void *)0), & found);
      __Cont: /* CIL Label */ 
#line 99
      parent = parent->next;
    }
  }
#line 108
  if (! is_incomplete) {
#line 113
    i = 0;
#line 113
    while ((unsigned int )i < found.nr) {
#line 114
      c___0 = (struct commit *)(found.objects + i)->item;
#line 116
      tmp___0 = tree_is_complete(& (c___0->tree)->object.oid);
#line 116
      if (! tmp___0) {
#line 117
        is_incomplete = 1;
#line 118
        c___0->object.flags |= 1U << 10;
      }
#line 113
      i ++;
    }
#line 121
    if (! is_incomplete) {
#line 123
      i = 0;
#line 123
      while ((unsigned int )i < found.nr) {
#line 124
        ((found.objects + i)->item)->flags |= 1U;
#line 123
        i ++;
      }
    }
  }
#line 128
  i = 0;
#line 128
  while ((unsigned int )i < found.nr) {
#line 129
    ((found.objects + i)->item)->flags &= ~ (1U << 11);
#line 128
    i ++;
  }
#line 130
  if (is_incomplete) {
#line 131
    commit->object.flags |= 1U << 10;
  } else {
#line 141
    i = 0;
#line 141
    while ((unsigned int )i < found.nr) {
#line 142
      ((found.objects + i)->item)->flags |= 1U;
#line 141
      i ++;
    }
  }
#line 145
  free((void *)study.objects);
#line 146
  free((void *)found.objects);
#line 147
  return (! is_incomplete);
}
}
#line 150 "git_leak_7.c"
int main(void) 
{ 
  struct commit commit ;

  {
#line 153
  commit_is_complete(& commit);
#line 154
  return (0);
}
}