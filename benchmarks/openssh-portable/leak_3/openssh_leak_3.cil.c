/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 203 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned long u_int64_t;
#line 196 "../stdio.h"
typedef unsigned int u_int___0;
#line 200 "../stdio.h"
typedef int int32_t___0;
#line 203 "../stdio.h"
typedef unsigned int u_int32_t___0;
#line 207 "../stdio.h"
typedef unsigned char u_char___0;
#line 351 "../openssh.h"
struct sshbuf {
   u_char___0 *d ;
   u_char___0 const   *cd ;
   size_t off ;
   size_t size ;
   size_t max_size ;
   size_t alloc ;
   int readonly ;
   int dont_free ;
   u_int___0 refcount ;
   struct sshbuf *parent ;
};
#line 364 "../openssh.h"
typedef u_int___0 BN_ULONG;
#line 372 "../openssh.h"
struct bignum_st {
   BN_ULONG *d ;
   int top ;
   int dmax ;
   int neg ;
   int flags ;
};
#line 390 "../openssh.h"
typedef struct bignum_st BIGNUM;
#line 391 "../openssh.h"
struct rsa_st {
   int pad ;
   int32_t___0 version ;
   void const   *meth ;
   void *engine ;
   BIGNUM *n ;
   BIGNUM *e ;
   BIGNUM *d ;
   BIGNUM *p ;
   BIGNUM *q ;
   BIGNUM *dmp1 ;
   BIGNUM *dmq1 ;
   BIGNUM *iqmp ;
   void *pss ;
   int ex_data ;
   int references ;
   int flags ;
   void *_method_mod_n ;
   void *_method_mod_p ;
   void *_method_mod_q ;
   char *bignum_data ;
   void *blinding ;
   void *mt_blinding ;
   void *lock ;
};
#line 391 "../openssh.h"
typedef struct rsa_st RSA;
#line 434 "../openssh.h"
struct dsa_st {
   int pad ;
   int32_t___0 version ;
   BIGNUM *p ;
   BIGNUM *q ;
   BIGNUM *g ;
   BIGNUM *pub_key ;
   BIGNUM *priv_key ;
   int flags ;
};
#line 434 "../openssh.h"
typedef struct dsa_st DSA;
#line 621
struct sshkey;
#line 699 "../openssh.h"
struct sshkey_cert {
   struct sshbuf *certblob ;
   u_int___0 type ;
   u_int64_t serial ;
   char *key_id ;
   u_int___0 nprincipals ;
   char **principals ;
   u_int64_t valid_after ;
   u_int64_t valid_before ;
   struct sshbuf *critical ;
   struct sshbuf *extensions ;
   struct sshkey *signature_key ;
};
#line 713 "../openssh.h"
struct sshkey {
   int type ;
   int flags ;
   RSA *rsa ;
   DSA *dsa ;
   int ecdsa_nid ;
   void *ecdsa ;
   u_char___0 *ed25519_sk ;
   u_char___0 *ed25519_pk ;
   struct sshkey_cert *cert ;
};
#line 725 "../openssh.h"
struct hostkeys_update_ctx {
   char *host_str ;
   char *ip_str ;
   struct sshkey **keys ;
   int *keys_seen ;
   size_t nkeys ;
   size_t nnew ;
   struct sshkey **old_keys ;
   size_t nold ;
};
#line 12 "openssh_leak_3.c"
typedef void global_confirm_cb(int  , u_int32_t___0 seq , void * );
#line 14 "openssh_leak_3.c"
struct __anonstruct_entry_37 {
   struct global_confirm *tqe_next ;
   struct global_confirm **tqe_prev ;
};
#line 14 "openssh_leak_3.c"
struct global_confirm {
   struct __anonstruct_entry_37 entry ;
   global_confirm_cb *cb ;
   void *ctx ;
   int ref_count ;
};
#line 20 "openssh_leak_3.c"
struct global_confirms {
   struct global_confirm *tqh_first ;
   struct global_confirm **tqh_last ;
};
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 374 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand)(void) ;
#line 376
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) ;
#line 468
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 21 "openssh_leak_3.c"
static struct global_confirms global_confirms  =    {(struct global_confirm *)((void *)0), & global_confirms.tqh_first};
#line 32 "openssh_leak_3.c"
static void hostkeys_update_ctx_free(struct hostkeys_update_ctx *ctx ) 
{ 


  {
#line 37
  if ((unsigned long )ctx == (unsigned long )((void *)0)) {
#line 38
    return;
  }
#line 39
  free((void *)ctx->keys_seen);
#line 40
  free((void *)ctx);
#line 41
  return;
}
}
#line 43 "openssh_leak_3.c"
static void update_known_hosts(struct hostkeys_update_ctx *ctx ) 
{ 
  int was_raw ;
  size_t i ;

  {
#line 46
  was_raw = 0;
#line 50
  i = (size_t )0;
#line 50
  while (i < ctx->nkeys) {
#line 51
    if (*(ctx->keys_seen + i) != 2) {

    }
#line 50
    i ++;
  }
#line 54
  return;
}
}
#line 57 "openssh_leak_3.c"
static void client_global_hostkeys_private_confirm(int type , u_int32_t___0 seq ,
                                                   void *_ctx ) 
{ 
  struct hostkeys_update_ctx *ctx ;
  size_t i ;
  size_t ndone ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___3 ;
  int tmp___4 ;

  {
#line 60
  ctx = (struct hostkeys_update_ctx *)_ctx;
#line 66
  if (ctx->nnew == 0UL) {
#line 67
    printf((char const   * __restrict  )"%s: ctx->nnew == 0\n", "client_global_hostkeys_private_confirm");
#line 67
    exit(1);
  }
#line 68
  tmp___1 = rand();
#line 68
  if (tmp___1 % 2 == 1) {
#line 68
    tmp___0 = 1;
  } else {
#line 68
    tmp___0 = 0;
  }
#line 68
  if (tmp___0) {
#line 69
    printf((char const   * __restrict  )"Server failed to confirm ownership of private host keys\n");
#line 71
    hostkeys_update_ctx_free(ctx);
#line 72
    return;
  }
#line 75
  i = (size_t )0;
#line 75
  ndone = i;
#line 75
  while (i < ctx->nkeys) {
#line 76
    if (*(ctx->keys_seen + i)) {
#line 77
      goto __Cont;
    }
#line 79
    tmp___4 = rand();
#line 79
    if (tmp___4 % 2 == 1) {
#line 79
      tmp___3 = 1;
    } else {
#line 79
      tmp___3 = 0;
    }
#line 79
    if (tmp___3) {
#line 80
      goto out;
    }
#line 82
    ndone ++;
    __Cont: /* CIL Label */ 
#line 75
    i ++;
  }
#line 86
  update_known_hosts(ctx);
  out: 
#line 88
  hostkeys_update_ctx_free(ctx);
#line 89
  return;
}
}
#line 91 "openssh_leak_3.c"
void client_register_global_confirm(global_confirm_cb *cb , void *ctx ) 
{ 
  struct global_confirm *gc ;
  struct global_confirm *last_gc ;
  void *tmp ;

  {
#line 97
  last_gc = *(((struct global_confirms *)global_confirms.tqh_last)->tqh_last);
#line 98
  if (last_gc) {
#line 98
    if ((unsigned long )last_gc->cb == (unsigned long )cb) {
#line 98
      if ((unsigned long )last_gc->ctx == (unsigned long )ctx) {
#line 99
        (last_gc->ref_count) ++;
#line 99
        if (last_gc->ref_count >= 10000) {
#line 100
          printf((char const   * __restrict  )"%s: last_gc->ref_count \n", "client_register_global_confirm");
#line 100
          exit(1);
        }
#line 102
        return;
      }
    }
  }
#line 105
  tmp = calloc((size_t )1, sizeof(*gc));
#line 105
  gc = (struct global_confirm *)tmp;
#line 106
  gc->cb = cb;
#line 107
  gc->ctx = ctx;
#line 108
  gc->ref_count = 1;
#line 109
  while (1) {
#line 109
    gc->entry.tqe_next = (struct global_confirm *)((void *)0);
#line 109
    gc->entry.tqe_prev = global_confirms.tqh_last;
#line 109
    *(global_confirms.tqh_last) = gc;
#line 109
    global_confirms.tqh_last = & gc->entry.tqe_next;
#line 109
    break;
  }
#line 110
  return;
}
}
#line 112 "openssh_leak_3.c"
static int client_global_request_reply(int type , u_int32_t___0 seq , void *ctxt ) 
{ 
  struct global_confirm *gc ;

  {
#line 117
  gc = global_confirms.tqh_first;
#line 117
  if ((unsigned long )gc == (unsigned long )((void *)0)) {
#line 118
    return (0);
  }
#line 119
  if ((unsigned long )gc->cb != (unsigned long )((void *)0)) {
#line 120
    (*(gc->cb))(type, seq, gc->ctx);
  }
#line 121
  (gc->ref_count) --;
#line 121
  if (gc->ref_count <= 0) {
#line 122
    while (1) {
#line 122
      if ((unsigned long )gc->entry.tqe_next != (unsigned long )((void *)0)) {
#line 122
        (gc->entry.tqe_next)->entry.tqe_prev = gc->entry.tqe_prev;
      } else {
#line 122
        global_confirms.tqh_last = gc->entry.tqe_prev;
      }
#line 122
      *(gc->entry.tqe_prev) = gc->entry.tqe_next;
#line 122
      gc->entry.tqe_prev = (struct global_confirm **)0;
#line 122
      gc->entry.tqe_next = (struct global_confirm *)0;
#line 122
      break;
    }
#line 123
    free((void *)gc);
  }
#line 126
  return (0);
}
}
#line 143
int client_input_hostkeys(int argc , char **argv ) ;
#line 135 "openssh_leak_3.c"
int client_input_hostkeys(int argc , char **argv ) 
{ 
  u_char___0 const   *blob ;
  size_t i ;
  size_t len ;
  struct sshbuf *buf ;
  struct sshkey *key ;
  struct hostkeys_update_ctx *ctx ;
  void *tmp___0 ;
  int i___0 ;
  int *tmp___1 ;
  void *tmp___2 ;
  int tmp___4 ;

  {
#line 137
  blob = (u_char___0 const   *)((void *)0);
#line 138
  len = (size_t )0;
#line 139
  buf = (struct sshbuf *)((void *)0);
#line 140
  key = (struct sshkey *)((void *)0);
#line 145
  ctx = (struct hostkeys_update_ctx *)((void *)0);
#line 147
  tmp___0 = calloc((size_t )1, sizeof(*ctx));
#line 147
  ctx = (struct hostkeys_update_ctx *)tmp___0;
#line 149
  if (argc == 1) {
#line 151
    return (1);
  }
#line 153
  i___0 = 1;
#line 153
  while (i___0 < argc) {
#line 155
    if ((int )*(*(argv + i___0) + 0) != 107) {
#line 156
      printf((char const   * __restrict  )"parse key %s error\n", *(argv + i___0));
#line 157
      goto out;
    }
#line 159
    (ctx->nkeys) ++;
#line 153
    i___0 ++;
  }
#line 162
  if (ctx->nkeys == 0UL) {
#line 163
    printf((char const   * __restrict  )"%s: server sent no hostkeys\n", "client_input_hostkeys");
#line 164
    goto out;
  }
#line 167
  tmp___2 = calloc(ctx->nkeys, sizeof(*(ctx->keys_seen)));
#line 167
  tmp___1 = (int *)tmp___2;
#line 167
  ctx->keys_seen = tmp___1;
#line 167
  if ((unsigned long )tmp___1 == (unsigned long )((void *)0)) {
#line 169
    printf((char const   * __restrict  )"%s: calloc failed\n", "client_input_hostkeys");
#line 169
    exit(1);
  }
#line 172
  ctx->nnew = (size_t )0;
#line 173
  i = (size_t )0;
#line 173
  while (i < ctx->nkeys) {
#line 174
    tmp___4 = rand();
#line 174
    if (tmp___4 % 2 == 1) {
#line 174
      *(ctx->keys_seen + i) = 1;
    } else {
#line 174
      *(ctx->keys_seen + i) = 0;
    }
#line 175
    if (! *(ctx->keys_seen + i)) {
#line 176
      (ctx->nnew) ++;
    }
#line 173
    i ++;
  }
#line 179
  printf((char const   * __restrict  )"%zu keys from server: %zu new, %zu retained. \n",
         ctx->nkeys, ctx->nnew, ctx->nkeys - ctx->nnew);
#line 182
  if (ctx->nnew == 0UL) {
#line 184
    update_known_hosts(ctx);
  } else
#line 185
  if (ctx->nnew != 0UL) {
#line 190
    printf((char const   * __restrict  )"asking server to prove ownership for %zu keys\n",
           ctx->nnew);
#line 191
    client_register_global_confirm(& client_global_hostkeys_private_confirm, (void *)ctx);
#line 193
    ctx = (struct hostkeys_update_ctx *)((void *)0);
  }
  out: 
#line 198
  hostkeys_update_ctx_free(ctx);
#line 203
  return (1);
}
}
#line 207
extern int ( /* missing proto */  time)() ;
#line 206 "openssh_leak_3.c"
int main(int argc , char **argv ) 
{ 
  int tmp ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 207
  tmp = time((void *)0);
#line 207
  srand((unsigned int )tmp);
#line 208
  while (1) {
#line 208
    tmp___2 = rand();
#line 208
    if (tmp___2 % 2 == 1) {
#line 208
      tmp___1 = 1;
    } else {
#line 208
      tmp___1 = 0;
    }
#line 208
    if (! tmp___1) {
#line 208
      break;
    }
#line 209
    client_input_hostkeys(argc, argv);
  }
#line 210
  while (! ((unsigned long )global_confirms.tqh_first == (unsigned long )((void *)0))) {
#line 211
    client_global_request_reply(0, (u_int32_t___0 )0, (void *)0);
  }
#line 212
  return (0);
}
}