/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 141 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __suseconds_t;
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 203 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned long u_int64_t;
#line 30 "/usr/include/x86_64-linux-gnu/bits/time.h"
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
#line 54 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef long __fd_mask;
#line 64 "/usr/include/x86_64-linux-gnu/sys/select.h"
struct __anonstruct_fd_set_14 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
#line 64 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef struct __anonstruct_fd_set_14 fd_set;
#line 196 "../stdio.h"
typedef unsigned int u_int___0;
#line 200 "../stdio.h"
typedef int int32_t___0;
#line 203 "../stdio.h"
typedef unsigned int u_int32_t___0;
#line 207 "../stdio.h"
typedef unsigned char u_char___0;
#line 214 "../stdio.h"
typedef int sig_atomic_t;
#line 215 "../stdio.h"
typedef __fd_mask fd_mask___0;
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
#line 615 "../openssh.h"
struct newkeys {
   char *enc ;
   char *mac ;
   char *comp ;
};
#line 621
struct sshkey;
#line 621
struct ssh;
#line 621 "../openssh.h"
struct kex {
   u_char___0 *session_id ;
   size_t session_id_len ;
   struct newkeys *newkeys[2] ;
   u_int___0 we_need ;
   u_int___0 dh_need ;
   int server ;
   char *name ;
   char *hostkey_alg ;
   int hostkey_type ;
   int hostkey_nid ;
   u_int___0 kex_type ;
   int rsa_sha2 ;
   int ext_info_c ;
   struct sshbuf *my ;
   struct sshbuf *peer ;
   sig_atomic_t done ;
   u_int___0 flags ;
   int hash_alg ;
   int ec_nid ;
   char *client_version_string ;
   char *server_version_string ;
   char *failed_choice ;
   int (*verify_host_key)(struct sshkey * , struct ssh * ) ;
   struct sshkey *(*load_host_public_key)(int  , int  , struct ssh * ) ;
   struct sshkey *(*load_host_private_key)(int  , int  , struct ssh * ) ;
   int (*host_key_index)(struct sshkey * , int  , struct ssh * ) ;
   int (*sign)(struct sshkey * , struct sshkey * , u_char___0 ** , size_t * , u_char___0 const   * ,
               size_t  , char const   * , u_int___0  ) ;
   int (*kex[9])(struct ssh * ) ;
   void *dh ;
   u_int___0 min ;
   u_int___0 max ;
   u_int___0 nbits ;
   void *ec_client_key ;
   void const   *ec_group ;
   u_char___0 c25519_client_key[32] ;
   u_char___0 c25519_client_pubkey[32] ;
};
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
#line 1018
struct session_state;
#line 1018
struct key_entry;
#line 1018 "../openssh.h"
struct __anonstruct_private_keys_31 {
   struct key_entry *tqh_first ;
   struct key_entry **tqh_last ;
};
#line 1018 "../openssh.h"
struct __anonstruct_public_keys_32 {
   struct key_entry *tqh_first ;
   struct key_entry **tqh_last ;
};
#line 1018 "../openssh.h"
struct ssh {
   struct session_state *state ;
   struct kex *kex ;
   char *remote_ipaddr ;
   int remote_port ;
   char *local_ipaddr ;
   int local_port ;
   char *log_preamble ;
   int dispatch_skip_packets ;
   int compat ;
   struct __anonstruct_private_keys_31 private_keys ;
   struct __anonstruct_public_keys_32 public_keys ;
   void *app_data ;
};
#line 1053 "../openssh.h"
struct packet_state {
   u_int32_t___0 seqnr ;
   u_int32_t___0 packets ;
   u_int64_t blocks ;
   u_int64_t bytes ;
};
#line 1060 "../openssh.h"
struct __anonstruct_next_33 {
   struct packet *tqe_next ;
   struct packet **tqe_prev ;
};
#line 1060 "../openssh.h"
struct packet {
   struct __anonstruct_next_33 next ;
   u_char___0 type ;
   struct sshbuf *payload ;
};
#line 1066 "../openssh.h"
typedef int ssh_packet_hook_fn(struct ssh * , struct sshbuf * , u_char___0 * , void * );
#line 1069 "../openssh.h"
typedef int z_stream;
#line 1072
struct sshcipher_ctx;
#line 1072
struct sshmac;
#line 1072 "../openssh.h"
struct __anonstruct_outgoing_34 {
   struct packet *tqh_first ;
   struct packet **tqh_last ;
};
#line 1072 "../openssh.h"
struct session_state {
   int connection_in ;
   int connection_out ;
   u_int___0 remote_protocol_flags ;
   struct sshcipher_ctx *receive_context ;
   struct sshcipher_ctx *send_context ;
   struct sshbuf *input ;
   struct sshbuf *output ;
   struct sshbuf *outgoing_packet ;
   struct sshbuf *incoming_packet ;
   struct sshbuf *compression_buffer ;
   z_stream compression_in_stream ;
   z_stream compression_out_stream ;
   int compression_in_started ;
   int compression_out_started ;
   int compression_in_failures ;
   int compression_out_failures ;
   int packet_compression ;
   u_int___0 max_packet_size ;
   int initialized ;
   int interactive_mode ;
   int server_side ;
   int after_authentication ;
   int keep_alive_timeouts ;
   int packet_timeout_ms ;
   struct newkeys *newkeys[2] ;
   struct packet_state p_read ;
   struct packet_state p_send ;
   u_int64_t max_blocks_in ;
   u_int64_t max_blocks_out ;
   u_int64_t rekey_limit ;
   u_int32_t___0 rekey_interval ;
   time_t rekey_time ;
   u_char___0 ssh1_key[32] ;
   u_int___0 ssh1_keylen ;
   u_char___0 extra_pad ;
   u_int___0 packet_discard ;
   size_t packet_discard_mac_already ;
   struct sshmac *packet_discard_mac ;
   u_int___0 packlen ;
   int rekeying ;
   int mux ;
   int set_interactive_called ;
   int set_maxsize_called ;
   int cipher_warning_done ;
   char *deattack ;
   ssh_packet_hook_fn *hook_in ;
   void *hook_in_ctx ;
   struct __anonstruct_outgoing_34 outgoing ;
};
#line 106 "/usr/include/x86_64-linux-gnu/sys/select.h"
int select(int a , fd_set * __restrict  b , fd_set * __restrict  c , fd_set * __restrict  d ,
           struct timeval * __restrict  e ) ;
#line 374 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand)(void) ;
#line 376
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) ;
#line 466
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 50 "/usr/include/x86_64-linux-gnu/bits/errno.h"
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
#line 12 "openssh_leak_2.c"
int select(int a , fd_set * __restrict  b , fd_set * __restrict  c , fd_set * __restrict  d ,
           struct timeval * __restrict  e ) 
{ 


  {
#line 14
  if (b) {
#line 14
    b->__fds_bits[0] = (__fd_mask )a;
  }
#line 15
  if (c) {
#line 15
    c->__fds_bits[0] = (__fd_mask )a;
  }
#line 16
  if (d) {
#line 16
    d->__fds_bits[0] = (__fd_mask )a;
  }
#line 17
  return (1);
}
}
#line 20 "openssh_leak_2.c"
void ms_to_timeval(struct timeval *tv , int ms ) 
{ 


  {
#line 23
  if (ms < 0) {
#line 24
    ms = 0;
  }
#line 25
  tv->tv_sec = (__time_t )(ms / 1000);
#line 26
  tv->tv_usec = (__suseconds_t )((ms % 1000) * 1000);
#line 27
  return;
}
}
#line 46
extern int ( /* missing proto */  memset)() ;
#line 57
extern int ( /* missing proto */  gettimeofday)() ;
#line 29 "openssh_leak_2.c"
int ssh_packet_write_wait(struct ssh *ssh ) 
{ 
  fd_set *setp ;
  int ret ;
  int r ;
  int ms_remain ;
  struct timeval start ;
  struct timeval timeout ;
  struct timeval *timeoutp ;
  struct session_state *state ;
  void *tmp ;
  int tmp___1 ;
  int *tmp___2 ;
  int *tmp___3 ;
  int *tmp___4 ;
  int tmp___6 ;
  int tmp___8 ;
  int tmp___9 ;

  {
#line 33
  ms_remain = 0;
#line 34
  timeoutp = (struct timeval *)((void *)0);
#line 35
  state = ssh->state;
#line 37
  tmp = malloc((unsigned long )(((state->connection_out + 1) + (8 * (int )sizeof(__fd_mask ) - 1)) / (8 * (int )sizeof(__fd_mask ))) * sizeof(fd_mask___0 ));
#line 37
  setp = (fd_set *)tmp;
#line 39
  if ((unsigned long )setp == (unsigned long )((void *)0)) {
#line 40
    return (-2);
  }
#line 41
  tmp___1 = rand();
#line 41
  if (tmp___1 % 2 == 1) {
#line 41
    r = 1;
  } else {
#line 41
    r = 0;
  }
#line 41
  if (r != 0) {
#line 43
    return (r);
  }
#line 45
  while (1) {
#line 45
    tmp___9 = rand();
#line 45
    if (tmp___9 % 2 == 1) {
#line 45
      tmp___8 = 1;
    } else {
#line 45
      tmp___8 = 0;
    }
#line 45
    if (! tmp___8) {
#line 45
      break;
    }
#line 46
    memset(setp, 0, (unsigned long )(((state->connection_out + 1) + (8 * (int )sizeof(__fd_mask ) - 1)) / (8 * (int )sizeof(__fd_mask ))) * sizeof(fd_mask___0 ));
#line 48
    setp->__fds_bits[state->connection_out / (8 * (int )sizeof(__fd_mask ))] |= (__fd_mask )(1UL << state->connection_out % (8 * (int )sizeof(__fd_mask )));
#line 50
    if (state->packet_timeout_ms > 0) {
#line 51
      ms_remain = state->packet_timeout_ms;
#line 52
      timeoutp = & timeout;
    }
#line 54
    while (1) {
#line 55
      if (state->packet_timeout_ms != -1) {
#line 56
        ms_to_timeval(& timeout, ms_remain);
#line 57
        gettimeofday(& start, (void *)0);
      }
#line 59
      ret = select(state->connection_out + 1, (fd_set * __restrict  )((void *)0),
                   (fd_set * __restrict  )setp, (fd_set * __restrict  )((void *)0),
                   (struct timeval * __restrict  )timeoutp);
#line 59
      if (ret >= 0) {
#line 61
        break;
      }
#line 62
      tmp___2 = __errno_location();
#line 62
      if (*tmp___2 != 11) {
#line 62
        tmp___3 = __errno_location();
#line 62
        if (*tmp___3 != 4) {
#line 62
          tmp___4 = __errno_location();
#line 62
          if (*tmp___4 != 11) {
#line 64
            break;
          }
        }
      }
#line 65
      if (state->packet_timeout_ms == -1) {
#line 66
        goto __Cont;
      }
#line 67
      ms_remain = rand();
#line 68
      if (ms_remain <= 0) {
#line 69
        ret = 0;
#line 70
        break;
      }
      __Cont: /* CIL Label */ ;
    }
#line 73
    if (ret == 0) {
#line 74
      free((void *)setp);
#line 75
      return (-53);
    }
#line 77
    tmp___6 = rand();
#line 77
    if (tmp___6 % 2 == 1) {
#line 77
      r = 1;
    } else {
#line 77
      r = 0;
    }
#line 77
    if (r != 0) {
#line 78
      free((void *)setp);
#line 79
      return (r);
    }
  }
#line 82
  free((void *)setp);
#line 83
  return (0);
}
}
#line 89
extern int ( /* missing proto */  time)() ;
#line 87 "openssh_leak_2.c"
int main(int argc , char **argv ) 
{ 
  struct ssh ssh ;
  int tmp ;

  {
#line 89
  tmp = time((void *)0);
#line 89
  srand((unsigned int )tmp);
#line 90
  ssh_packet_write_wait(& ssh);
#line 91
  return (0);
}
}