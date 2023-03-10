/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 44 "/usr/include/stdio.h"
struct _IO_FILE;
#line 44
struct _IO_FILE;
#line 48 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 144 "/usr/include/libio.h"
struct _IO_FILE;
#line 150 "/usr/include/libio.h"
typedef void _IO_lock_t;
#line 156 "/usr/include/libio.h"
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
#line 241 "/usr/include/libio.h"
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 90 "git_df_1.c"
struct packed_git;
#line 90
struct remote_lock;
#line 90 "git_df_1.c"
struct repo {
   char *url ;
   int path_len ;
   int has_info_refs ;
   int can_update_info_refs ;
   int has_info_packs ;
   struct packed_git *packs ;
   struct remote_lock *locks ;
};
#line 126 "git_df_1.c"
struct remote_lock {
   char *url ;
   char *owner ;
   char *token ;
   time_t start_time ;
   long timeout ;
   int refreshing ;
   struct remote_lock *next ;
};
#line 156 "git_df_1.c"
typedef int CURLcode;
#line 157 "git_df_1.c"
struct __anonstruct_CURL_26 {

};
#line 157 "git_df_1.c"
typedef struct __anonstruct_CURL_26 CURL;
#line 159 "git_df_1.c"
struct slot_results {
   CURLcode curl_result ;
   long http_code ;
};
#line 165 "git_df_1.c"
struct active_request_slot {
   CURL *curl ;
   FILE *local ;
   int in_use ;
   CURLcode curl_result ;
   long http_code ;
   int *finished ;
   struct slot_results *results ;
   void *callback_data ;
   void (*callback_func)(void *data ) ;
   struct active_request_slot *next ;
};
#line 170 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr ;
#line 356
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
#line 364
extern  __attribute__((__nothrow__)) int sprintf(char * __restrict  __s , char const   * __restrict  __format 
                                                 , ...) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 101 "git_df_1.c"
static struct repo *remote  ;
#line 185
extern int ( /* missing proto */  strlen)() ;
#line 192
extern int ( /* missing proto */  get_active_slot)() ;
#line 194
extern int ( /* missing proto */  curl_easy_setopt)() ;
#line 198
extern int ( /* missing proto */  run_active_slot)() ;
#line 197
extern int ( /* missing proto */  start_active_slot)() ;
#line 183 "git_df_1.c"
static int remote_exists(char const   *path ) 
{ 
  char *url ;
  int tmp ;
  int tmp___0 ;
  void *tmp___1 ;
  struct active_request_slot *slot ;
  struct slot_results results ;
  int ret ;
  int tmp___2 ;
  int tmp___3 ;

  {
#line 185
  tmp = strlen(remote->url);
#line 185
  tmp___0 = strlen(path);
#line 185
  tmp___1 = malloc((size_t )((tmp + tmp___0) + 1));
#line 185
  url = (char *)tmp___1;
#line 188
  ret = -1;
#line 190
  sprintf((char * __restrict  )url, (char const   * __restrict  )"%s%s", remote->url,
          path);
#line 192
  tmp___2 = get_active_slot();
#line 192
  slot = (struct active_request_slot *)tmp___2;
#line 193
  slot->results = & results;
#line 194
  curl_easy_setopt(slot->curl, 0, url);
#line 195
  curl_easy_setopt(slot->curl, 0, 1);
#line 197
  tmp___3 = start_active_slot(slot);
#line 197
  if (tmp___3) {
#line 198
    run_active_slot(slot);
#line 199
    free((void *)url);
#line 200
    if (results.http_code == 404L) {
#line 201
      ret = 0;
    } else
#line 202
    if (results.curl_result == 0) {
#line 203
      ret = 1;
    } else {
#line 205
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"HEAD HTTP error %ld\n",
              results.http_code);
    }
  } else {
#line 207
    free((void *)url);
#line 208
    fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Unable to start HEAD request\n");
  }
#line 211
  free((void *)url);
#line 212
  return (ret);
}
}
#line 215 "git_df_1.c"
int main(void) 
{ 


  {
#line 217
  remote_exists("path");
#line 218
  return (0);
}
}
