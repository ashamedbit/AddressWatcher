/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
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
#line 512 "../include/binutils.h"
typedef unsigned long long BFD_HOST_U_64_BIT;
#line 517 "../include/binutils.h"
typedef BFD_HOST_U_64_BIT bfd_size_type;
#line 15 "binutils_df_3.c"
struct __anonstruct_asection_25 {

};
#line 15 "binutils_df_3.c"
typedef struct __anonstruct_asection_25 asection;
#line 18
struct build_id;
#line 18 "binutils_df_3.c"
struct objfile {
   struct build_id *obfd ;
   char *name ;
};
/* compiler builtin: 
   void *__builtin_alloca(unsigned long  ) ;  */
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 466 "/usr/include/stdlib.h"
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
#line 11 "binutils_df_3.c"
char *debug_file_directory  =    (char *)((void *)0);
#line 12 "binutils_df_3.c"
char *gdb_sysroot  =    (char *)0;
#line 27
extern int ( /* missing proto */  strdup)() ;
#line 23 "binutils_df_3.c"
char *lrealpath(char const   *filename ) 
{ 
  int tmp ;

  {
#line 27
  tmp = strdup(filename);
#line 27
  return ((char *)tmp);
}
}
#line 43
extern int ( /* missing proto */  build_id_bfd_get)() ;
#line 48
extern int ( /* missing proto */  build_id_to_debug_filename)() ;
#line 53
extern int ( /* missing proto */  warning)() ;
#line 53
extern int ( /* missing proto */  _)() ;
#line 51
extern int ( /* missing proto */  strcmp)() ;
#line 61
extern int ( /* missing proto */  get_debug_link_info)() ;
#line 72
extern int ( /* missing proto */  strlen)() ;
#line 74
extern int ( /* missing proto */  IS_DIR_SEPARATOR)() ;
#line 77
extern int ( /* missing proto */  gdb_assert)() ;
#line 94
extern int ( /* missing proto */  strcpy)() ;
#line 95
extern int ( /* missing proto */  strcat)() ;
#line 97
extern int ( /* missing proto */  separate_debug_file_exists)() ;
#line 135
extern int ( /* missing proto */  strncmp)() ;
#line 29 "binutils_df_3.c"
static char *find_separate_debug_file(struct objfile *objfile ) 
{ 
  char *basename ;
  char *dir ;
  char *debugfile ;
  char *canon_name ;
  unsigned long crc32 ;
  int i ;
  struct build_id *build_id ;
  int tmp ;
  char *build_id_name ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  void *tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;

  {
#line 43
  tmp = build_id_bfd_get(objfile->obfd);
#line 43
  build_id = (struct build_id *)tmp;
#line 44
  if ((unsigned long )build_id != (unsigned long )((void *)0)) {
#line 48
    tmp___0 = build_id_to_debug_filename(build_id);
#line 48
    build_id_name = (char *)tmp___0;
#line 49
    free((void *)build_id);
#line 51
    if ((unsigned long )build_id_name != (unsigned long )((void *)0)) {
#line 51
      tmp___2 = strcmp(build_id_name, objfile->name);
#line 51
      if (tmp___2 == 0) {
#line 53
        tmp___1 = _("\"%s\": separate debug info file has no debug info");
#line 53
        warning(tmp___1, build_id_name);
#line 55
        free((void *)build_id_name);
      } else {
#line 51
        goto _L;
      }
    } else
    _L: /* CIL Label */ 
#line 57
    if ((unsigned long )build_id_name != (unsigned long )((void *)0)) {
#line 58
      return (build_id_name);
    }
  }
#line 61
  tmp___3 = get_debug_link_info(objfile, & crc32);
#line 61
  basename = (char *)tmp___3;
#line 63
  if ((unsigned long )basename == (unsigned long )((void *)0)) {
#line 64
    return ((char *)((void *)0));
  }
#line 66
  tmp___4 = strdup(objfile->name);
#line 66
  dir = (char *)tmp___4;
#line 72
  tmp___5 = strlen(dir);
#line 72
  i = tmp___5 - 1;
#line 72
  while (i >= 0) {
#line 74
    tmp___6 = IS_DIR_SEPARATOR((int )*(dir + i));
#line 74
    if (tmp___6) {
#line 75
      break;
    }
#line 72
    i --;
  }
#line 77
  if (i >= 0) {
#line 77
    tmp___7 = IS_DIR_SEPARATOR((int )*(dir + i));
#line 77
    if (tmp___7) {
#line 77
      tmp___8 = 1;
    } else {
#line 77
      tmp___8 = 0;
    }
  } else {
#line 77
    tmp___8 = 0;
  }
#line 77
  gdb_assert(tmp___8);
#line 78
  *(dir + (i + 1)) = (char )'\000';
#line 81
  canon_name = lrealpath((char const   *)dir);
#line 82
  i = strlen(dir);
#line 83
  if (canon_name) {
#line 83
    tmp___9 = strlen(canon_name);
#line 83
    if (tmp___9 > i) {
#line 84
      i = strlen(canon_name);
    }
  }
#line 86
  tmp___10 = strlen(debug_file_directory);
#line 86
  tmp___11 = strlen(".debug");
#line 86
  tmp___12 = strlen("/");
#line 86
  tmp___13 = strlen(basename);
#line 86
  tmp___14 = __builtin_alloca((unsigned long )((((((tmp___10 + 1) + i) + tmp___11) + tmp___12) + tmp___13) + 1));
#line 86
  debugfile = (char *)tmp___14;
#line 94
  strcpy(debugfile, dir);
#line 95
  strcat(debugfile, basename);
#line 97
  tmp___16 = separate_debug_file_exists(debugfile, crc32);
#line 97
  if (tmp___16) {
#line 99
    free((void *)basename);
#line 100
    free((void *)dir);
#line 101
    free((void *)canon_name);
#line 102
    tmp___15 = strdup(debugfile);
#line 102
    return ((char *)tmp___15);
  }
#line 106
  strcpy(debugfile, dir);
#line 107
  strcat(debugfile, ".debug");
#line 108
  strcat(debugfile, "/");
#line 109
  strcat(debugfile, basename);
#line 111
  tmp___18 = separate_debug_file_exists(debugfile, crc32);
#line 111
  if (tmp___18) {
#line 113
    free((void *)basename);
#line 114
    free((void *)dir);
#line 115
    free((void *)canon_name);
#line 116
    tmp___17 = strdup(debugfile);
#line 116
    return ((char *)tmp___17);
  }
#line 120
  strcpy(debugfile, debug_file_directory);
#line 121
  strcat(debugfile, "/");
#line 122
  strcat(debugfile, dir);
#line 123
  strcat(debugfile, basename);
#line 125
  tmp___20 = separate_debug_file_exists(debugfile, crc32);
#line 125
  if (tmp___20) {
#line 127
    free((void *)basename);
#line 128
    free((void *)dir);
#line 129
    free((void *)canon_name);
#line 130
    tmp___19 = strdup(debugfile);
#line 130
    return ((char *)tmp___19);
  }
#line 135
  if (canon_name) {
#line 135
    tmp___24 = strlen(gdb_sysroot);
#line 135
    tmp___25 = strncmp(canon_name, gdb_sysroot, tmp___24);
#line 135
    if (tmp___25 == 0) {
#line 135
      tmp___26 = strlen(gdb_sysroot);
#line 135
      tmp___27 = IS_DIR_SEPARATOR((int )*(canon_name + tmp___26));
#line 135
      if (tmp___27) {
#line 139
        strcpy(debugfile, debug_file_directory);
#line 140
        tmp___21 = strlen(gdb_sysroot);
#line 140
        strcat(debugfile, canon_name + tmp___21);
#line 141
        strcat(debugfile, "/");
#line 142
        strcat(debugfile, basename);
#line 144
        tmp___23 = separate_debug_file_exists(debugfile, crc32);
#line 144
        if (tmp___23) {
#line 146
          free((void *)canon_name);
#line 147
          free((void *)basename);
#line 148
          free((void *)dir);
#line 149
          free((void *)canon_name);
#line 150
          tmp___22 = strdup(debugfile);
#line 150
          return ((char *)tmp___22);
        }
      }
    }
  }
#line 154
  if (canon_name) {
#line 155
    free((void *)canon_name);
  }
#line 157
  free((void *)basename);
#line 158
  free((void *)dir);
#line 159
  return ((char *)((void *)0));
}
}
#line 161 "binutils_df_3.c"
int main(void) 
{ 
  struct objfile objfile ;

  {
#line 164
  find_separate_debug_file(& objfile);
#line 165
  return (0);
}
}
