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
#line 524 "../include/binutils.h"
struct bfd;
#line 17 "../include/bfd.h"
typedef int bool___0;
#line 21
enum bfd_flavour {
    bfd_target_unknown_flavour = 0,
    bfd_target_aout_flavour = 1,
    bfd_target_coff_flavour = 2,
    bfd_target_ecoff_flavour = 3,
    bfd_target_xcoff_flavour = 4,
    bfd_target_elf_flavour = 5,
    bfd_target_ieee_flavour = 6,
    bfd_target_nlm_flavour = 7,
    bfd_target_oasys_flavour = 8,
    bfd_target_tekhex_flavour = 9,
    bfd_target_srec_flavour = 10,
    bfd_target_verilog_flavour = 11,
    bfd_target_ihex_flavour = 12,
    bfd_target_som_flavour = 13,
    bfd_target_os9k_flavour = 14,
    bfd_target_versados_flavour = 15,
    bfd_target_msdos_flavour = 16,
    bfd_target_ovax_flavour = 17,
    bfd_target_evax_flavour = 18,
    bfd_target_mmo_flavour = 19,
    bfd_target_mach_o_flavour = 20,
    bfd_target_pef_flavour = 21,
    bfd_target_pef_xlib_flavour = 22,
    bfd_target_sym_flavour = 23
} ;
#line 50 "../include/bfd.h"
struct bfd_target {
   char *name ;
   enum bfd_flavour flavour ;
};
#line 57 "../include/bfd.h"
struct bfd {
   char *filename ;
   int direction ;
   struct bfd *archive_next ;
   struct bfd_target  const  *xvec ;
   void *memory ;
   bool___0 cacheable ;
};
#line 9 "binutils_df_2.c"
typedef int bool___1;
#line 10 "binutils_df_2.c"
typedef int bfd_vma___0;
#line 11 "binutils_df_2.c"
typedef bool___1 bfd_boolean___0;
#line 12 "binutils_df_2.c"
typedef int Elf_Internal_Rela;
#line 14 "binutils_df_2.c"
struct link_info {
   bool___1 keep_memory ;
};
#line 18 "binutils_df_2.c"
struct alpha_relax_info {
   struct bfd *abfd ;
   struct link_info *link_info ;
};
#line 23 "binutils_df_2.c"
typedef struct bfd bfd___1;
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 374 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand)(void) ;
#line 376
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
#line 25 "binutils_df_2.c"
Elf_Internal_Rela *_bfd_elf_link_read_relocs(bfd___1 *abfd , Elf_Internal_Rela *internal_relocs ,
                                             bfd_boolean___0 keep_memory ) 
{ 
  Elf_Internal_Rela *alloc1 ;
  Elf_Internal_Rela *alloc2 ;
  int tmp___0 ;
  int tmp___1 ;
  void *tmp___2 ;

  {
#line 30
  alloc2 = (Elf_Internal_Rela *)((void *)0);
#line 34
  tmp___1 = rand();
#line 34
  if (tmp___1 % 2 == 1) {
#line 34
    tmp___0 = 1;
  } else {
#line 34
    tmp___0 = 0;
  }
#line 34
  if (tmp___0) {
#line 34
    if (abfd->memory) {
#line 35
      printf((char const   * __restrict  )"cached memory(abfd->memory) is returned\n");
#line 36
      return ((Elf_Internal_Rela *)abfd->memory);
    }
  }
#line 39
  if ((unsigned long )internal_relocs == (unsigned long )((void *)0)) {
#line 41
    tmp___2 = malloc(sizeof(Elf_Internal_Rela ));
#line 41
    alloc2 = (Elf_Internal_Rela *)tmp___2;
#line 41
    internal_relocs = alloc2;
#line 44
    if (keep_memory) {
#line 45
      abfd->memory = (void *)alloc2;
    }
#line 47
    if ((unsigned long )internal_relocs == (unsigned long )((void *)0)) {
#line 48
      goto error_return;
    }
  }
#line 51
  if ((unsigned long )alloc1 == (unsigned long )((void *)0)) {
#line 54
    return (internal_relocs);
  }
  error_return: 
#line 56
  if (keep_memory) {
#line 57
    abfd->memory = (void *)0;
  }
#line 59
  return ((Elf_Internal_Rela *)((void *)0));
}
}
#line 62 "binutils_df_2.c"
static bfd_vma___0 elf64_alpha_relax_opt_call(struct alpha_relax_info *info , bfd_vma___0 symval ) 
{ 
  Elf_Internal_Rela *tsec_relocs ;
  Elf_Internal_Rela *tsec_free ;

  {
#line 68
  tsec_relocs = _bfd_elf_link_read_relocs(info->abfd, (Elf_Internal_Rela *)((void *)0),
                                          (info->link_info)->keep_memory);
#line 72
  if ((unsigned long )tsec_relocs == (unsigned long )((void *)0)) {
#line 73
    return (0);
  }
#line 75
  *tsec_relocs = 1;
#line 77
  if ((info->link_info)->keep_memory) {
#line 77
    tsec_free = (Elf_Internal_Rela *)((void *)0);
  } else {
#line 77
    tsec_free = tsec_relocs;
  }
#line 79
  if (tsec_free) {
#line 80
    free((void *)tsec_free);
  }
#line 82
  return (0);
}
}
#line 85 "binutils_df_2.c"
static bfd_boolean___0 elf64_alpha_relax_with_lituse(struct alpha_relax_info *info ,
                                                     bfd_vma___0 symval ) 
{ 
  bfd___1 *abfd ;
  Elf_Internal_Rela *internal_relocs ;
  Elf_Internal_Rela *tmp ;
  bfd_vma___0 optdest ;
  bfd_vma___0 tmp___0 ;

  {
#line 88
  abfd = info->abfd;
#line 89
  tmp = _bfd_elf_link_read_relocs(abfd, (Elf_Internal_Rela *)((void *)0), (info->link_info)->keep_memory);
#line 89
  internal_relocs = tmp;
#line 92
  tmp___0 = elf64_alpha_relax_opt_call(info, symval);
#line 92
  optdest = tmp___0;
#line 93
  free((void *)internal_relocs);
#line 94
  return (0);
}
}
#line 98
extern int ( /* missing proto */  time)() ;
#line 96 "binutils_df_2.c"
int main(void) 
{ 
  time_t t ;
  int tmp ;
  bfd_vma___0 symval ;
  struct alpha_relax_info info ;
  bfd___1 bfd___2 ;
  struct link_info link_info ;
  int tmp___1 ;

  {
#line 98
  tmp = time(& t);
#line 98
  srand((unsigned int )tmp);
#line 100
  symval = 1;
#line 105
  bfd___2.memory = malloc(sizeof(Elf_Internal_Rela ));
#line 106
  tmp___1 = rand();
#line 106
  if (tmp___1 % 2 == 1) {
#line 106
    link_info.keep_memory = 1;
  } else {
#line 106
    link_info.keep_memory = 0;
  }
#line 108
  info.abfd = & bfd___2;
#line 109
  info.link_info = & link_info;
#line 111
  printf((char const   * __restrict  )"keep_memory: %d\n", link_info.keep_memory);
#line 112
  elf64_alpha_relax_with_lituse(& info, symval);
#line 114
  *((int *)bfd___2.memory) = 1;
#line 115
  free(bfd___2.memory);
#line 116
  return (0);
}
}