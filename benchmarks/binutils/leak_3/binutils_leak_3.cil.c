/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 29 "../include/common.h"
typedef int bool;
#line 34 "../include/common.h"
typedef void make_cleanup_ftype(void * );
#line 36 "../include/common.h"
struct cleanup {
   struct cleanup *next ;
   void (*function)(void * ) ;
   void (*free_arg)(void * ) ;
   void *arg ;
};
#line 13 "binutils_leak_3.c"
typedef bool bfd_boolean;
#line 15 "binutils_leak_3.c"
struct bfd_hash_entry {
   struct bfd_hash_entry *next ;
   char const   *string ;
   unsigned long hash ;
};
#line 27 "binutils_leak_3.c"
struct bfd_hash_table {
   struct bfd_hash_entry **table ;
   void *memory ;
   unsigned int size ;
   unsigned int count ;
   unsigned int entsize ;
};
#line 42 "binutils_leak_3.c"
struct objalloc {
   char *current_ptr ;
   unsigned int current_space ;
   void *chunks ;
};
#line 49 "binutils_leak_3.c"
struct objalloc_chunk {
   struct objalloc_chunk *next ;
   char *current_ptr ;
};
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 376 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) ;
#line 466
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 31 "../include/common.h"
bool true  =    1;
#line 32 "../include/common.h"
bool false  =    0;
#line 44 "../include/common.h"
static struct cleanup  const  sentinel_cleanup  =    {(struct cleanup *)0, (void (*)(void * ))0, (void (*)(void * ))0, (void *)0};
#line 49 "../include/common.h"
static struct cleanup *cleanup_chain  =    (struct cleanup *)(& sentinel_cleanup);
#line 50 "../include/common.h"
static struct cleanup *final_cleanup_chain  ;
#line 52
void discard_cleanups(struct cleanup *old_chain ) ;
#line 53
void discard_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) ;
#line 55
void discard_final_cleanups(struct cleanup *old_chain ) ;
#line 56
static void do_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) ;
#line 58
void do_cleanups(struct cleanup *old_chain ) ;
#line 59
static struct cleanup *make_my_cleanup2(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                        void *arg , void (*free_arg)(void * ) ) ;
#line 62
static struct cleanup *make_my_cleanup(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                       void *arg ) ;
#line 65
struct cleanup *make_cleanup(make_cleanup_ftype *function , void *arg ) ;
#line 68 "../include/common.h"
void discard_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 71
  discard_my_cleanups(& cleanup_chain, old_chain);
#line 72
  return;
}
}
#line 74 "../include/common.h"
void discard_final_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 77
  discard_my_cleanups(& final_cleanup_chain, old_chain);
#line 78
  return;
}
}
#line 80 "../include/common.h"
void discard_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) 
{ 
  struct cleanup *ptr ;

  {
#line 86
  while (1) {
#line 86
    ptr = *pmy_chain;
#line 86
    if (! ((unsigned long )ptr != (unsigned long )old_chain)) {
#line 86
      break;
    }
#line 88
    *pmy_chain = ptr->next;
#line 89
    if (ptr->free_arg) {
#line 90
      (*(ptr->free_arg))(ptr->arg);
    }
#line 91
    free((void *)ptr);
  }
#line 94
  printf((char const   * __restrict  )"freearg: %x\n", ptr->arg);
#line 95
  return;
}
}
#line 97 "../include/common.h"
static void do_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) 
{ 
  struct cleanup *ptr ;

  {
#line 103
  while (1) {
#line 103
    ptr = *pmy_chain;
#line 103
    if (! ((unsigned long )ptr != (unsigned long )old_chain)) {
#line 103
      break;
    }
#line 105
    *pmy_chain = ptr->next;
#line 106
    (*(ptr->function))(ptr->arg);
#line 107
    printf((char const   * __restrict  )"cleanup!!!!! =========\n");
#line 108
    printf((char const   * __restrict  )"%x\n", ptr->arg);
#line 109
    if (ptr->free_arg) {
#line 110
      (*(ptr->free_arg))(ptr->arg);
    }
#line 112
    free((void *)ptr);
  }
#line 114
  return;
}
}
#line 116 "../include/common.h"
void do_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 118
  do_my_cleanups(& cleanup_chain, old_chain);
#line 119
  return;
}
}
#line 121 "../include/common.h"
static struct cleanup *make_my_cleanup2(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                        void *arg , void (*free_arg)(void * ) ) 
{ 
  struct cleanup *new ;
  void *tmp ;
  struct cleanup *old_chain ;

  {
#line 125
  tmp = malloc(sizeof(struct cleanup ));
#line 125
  new = (struct cleanup *)tmp;
#line 127
  old_chain = *pmy_chain;
#line 129
  new->next = *pmy_chain;
#line 130
  new->function = function;
#line 131
  new->free_arg = free_arg;
#line 132
  new->arg = arg;
#line 133
  *pmy_chain = new;
#line 135
  if ((unsigned long )old_chain == (unsigned long )((void *)0)) {
#line 136
    exit(1);
  }
#line 138
  return (old_chain);
}
}
#line 141 "../include/common.h"
static struct cleanup *make_my_cleanup(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                       void *arg ) 
{ 
  struct cleanup *tmp ;

  {
#line 145
  tmp = make_my_cleanup2(pmy_chain, function, arg, (void (*)(void * ))((void *)0));
#line 145
  return (tmp);
}
}
#line 148 "../include/common.h"
struct cleanup *make_cleanup(make_cleanup_ftype *function , void *arg ) 
{ 
  struct cleanup *tmp ;

  {
#line 151
  tmp = make_my_cleanup(& cleanup_chain, function, arg);
#line 151
  return (tmp);
}
}
#line 55 "binutils_leak_3.c"
struct objalloc *objalloc_create(void) 
{ 
  struct objalloc *ret ;
  struct objalloc_chunk *chunk ;
  void *tmp ;
  void *tmp___0 ;

  {
#line 61
  tmp = malloc(sizeof(*ret));
#line 61
  ret = (struct objalloc *)tmp;
#line 63
  if ((unsigned long )ret == (unsigned long )((void *)0)) {
#line 64
    return ((struct objalloc *)((void *)0));
  }
#line 66
  tmp___0 = malloc((size_t )4064);
#line 66
  ret->chunks = tmp___0;
#line 67
  if ((unsigned long )ret->chunks == (unsigned long )((void *)0)) {
#line 69
    free((void *)ret);
#line 70
    return ((struct objalloc *)((void *)0));
  }
#line 73
  chunk = (struct objalloc_chunk *)ret->chunks;
#line 74
  chunk->next = (struct objalloc_chunk *)((void *)0);
#line 75
  chunk->current_ptr = (char *)((void *)0);
#line 76
  chunk->next = (struct objalloc_chunk *)((void *)0);
#line 78
  ret->current_ptr = (char *)chunk + 32;
#line 79
  ret->current_space = 4032U;
#line 81
  return (ret);
}
}
#line 84 "binutils_leak_3.c"
void *objalloc_alloc(struct objalloc *o , unsigned long len ) 
{ 
  struct objalloc_chunk *chunk ;
  void *tmp ;

  {
#line 91
  if (len > 4064UL) {
#line 92
    exit(1);
  }
#line 94
  tmp = malloc((size_t )4064);
#line 94
  chunk = (struct objalloc_chunk *)tmp;
#line 95
  if ((unsigned long )chunk == (unsigned long )((void *)0)) {
#line 96
    return ((void *)0);
  }
#line 98
  chunk->next = (struct objalloc_chunk *)o->chunks;
#line 99
  chunk->current_ptr = (char *)((void *)0);
#line 101
  o->current_ptr = (char *)chunk + 32;
#line 102
  o->current_space = 4032U;
#line 104
  o->chunks = (void *)chunk;
#line 106
  return ((void *)(chunk + 32));
}
}
#line 109 "binutils_leak_3.c"
void objalloc_free(struct objalloc *o ) 
{ 
  struct objalloc_chunk *l ;
  void *data ;
  struct objalloc_chunk *next ;

  {
#line 115
  l = (struct objalloc_chunk *)o->chunks;
#line 116
  while ((unsigned long )l != (unsigned long )((void *)0)) {
#line 118
    data = (void *)(l + 32);
#line 121
    next = l->next;
#line 122
    free((void *)l);
#line 123
    l = next;
  }
#line 125
  free((void *)o);
#line 126
  return;
}
}
#line 152
extern int ( /* missing proto */  memset)() ;
#line 128 "binutils_leak_3.c"
bfd_boolean bfd_hash_table_init_n(struct bfd_hash_table *table , unsigned int entsize ,
                                  unsigned int size ) 
{ 
  unsigned long alloc ;
  struct objalloc *tmp ;
  void *tmp___0 ;

  {
#line 135
  alloc = (unsigned long )size;
#line 136
  alloc *= sizeof(struct bfd_hash_entry *);
#line 137
  tmp = objalloc_create();
#line 137
  table->memory = (void *)tmp;
#line 138
  if ((unsigned long )table->memory == (unsigned long )((void *)0)) {
#line 140
    return (0);
  }
#line 143
  tmp___0 = objalloc_alloc((struct objalloc *)table->memory, alloc);
#line 143
  table->table = (struct bfd_hash_entry **)tmp___0;
#line 146
  if ((unsigned long )table->table == (unsigned long )((void *)0)) {
#line 148
    objalloc_free((struct objalloc *)table);
#line 149
    return (0);
  }
#line 152
  memset((void *)table->table, 0, alloc);
#line 153
  table->size = size;
#line 154
  table->entsize = entsize;
#line 155
  table->count = 0U;
#line 157
  return (1);
}
}
#line 160 "binutils_leak_3.c"
struct bfd_hash_entry *bfd_hash_insert(struct bfd_hash_table *table , char const   *string ,
                                       unsigned long hash ) 
{ 
  struct bfd_hash_entry *hashp ;
  unsigned int _index ;
  void *tmp ;

  {
#line 168
  tmp = objalloc_alloc((struct objalloc *)table->memory, sizeof(*hashp));
#line 168
  hashp = (struct bfd_hash_entry *)tmp;
#line 169
  hashp->hash = hash;
#line 170
  hashp->string = string;
#line 171
  _index = (unsigned int )(hash % (unsigned long )table->size);
#line 172
  *(table->table + _index) = hashp;
#line 173
  (table->count) ++;
#line 175
  return (hashp);
}
}
#line 178 "binutils_leak_3.c"
void bfd_dwarf2_cleanup_debug_info(struct bfd_hash_table *table ) 
{ 


  {
#line 181
  objalloc_free((struct objalloc *)table->memory);
#line 182
  return;
}
}
#line 197
extern int ( /* missing proto */  time)() ;
#line 185 "binutils_leak_3.c"
int main(void) 
{ 
  time_t t ;
  struct bfd_hash_table table ;
  unsigned int entsize ;
  unsigned int size ;
  unsigned int cnt ;
  char const   *hash[10] ;
  int tmp ;
  bfd_boolean tmp___0 ;

  {
#line 191
  entsize = 10U;
#line 192
  size = 10U;
#line 193
  cnt = 0U;
#line 194
  hash[0] = "a";
#line 194
  hash[1] = "b";
#line 194
  hash[2] = "c";
#line 194
  hash[3] = "d";
#line 194
  hash[4] = "e";
#line 194
  hash[5] = "f";
#line 194
  hash[6] = "g";
#line 194
  hash[7] = "h";
#line 194
  hash[8] = "i";
#line 194
  hash[9] = "j";
#line 197
  tmp = time(& t);
#line 197
  srand((unsigned int )tmp);
#line 199
  tmp___0 = bfd_hash_table_init_n(& table, entsize, size);
#line 199
  if (! tmp___0) {
#line 200
    return;
  }
#line 202
  while (cnt < entsize) {
#line 204
    bfd_hash_insert(& table, hash[cnt], (unsigned long )cnt);
#line 205
    cnt ++;
  }
#line 209
  bfd_dwarf2_cleanup_debug_info(& table);
#line 210
  memset(& table, 0, sizeof(struct bfd_hash_table ));
#line 212
  return (0);
}
}
