/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 129 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __mode_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 70 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __mode_t mode_t;
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 197 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef long int64_t;
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
#line 213 "../stdio.h"
typedef int pid_t___0;
#line 214 "../stdio.h"
typedef int sig_atomic_t;
#line 245 "../stdio.h"
struct passwd {
   char *pw_name ;
   char *pw_passwd ;
   int pw_uid ;
   int pw_gid ;
   int pw_change ;
   char *pw_class ;
   char *pw_gecos ;
   char *pw_dir ;
   char *pw_shell ;
   int pw_expire ;
};
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
#line 365 "../openssh.h"
struct __anonstruct_Buffer_25 {
   u_char___0 *buf ;
   u_int___0 alloc ;
   u_int___0 offset ;
   u_int___0 end ;
};
#line 365 "../openssh.h"
typedef struct __anonstruct_Buffer_25 Buffer;
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
#line 626
struct sshkey;
#line 626 "../openssh.h"
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
#line 640 "../openssh.h"
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
#line 652
struct ssh;
#line 652 "../openssh.h"
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
#line 751 "../openssh.h"
struct Forward {
   char *listen_host ;
   int listen_port ;
   char *listen_path ;
   char *connect_host ;
   int connect_port ;
   char *connect_path ;
   int allocated_port ;
   int handle ;
};
#line 762 "../openssh.h"
struct ForwardOptions {
   int gateway_ports ;
   mode_t streamlocal_bind_mask ;
   int streamlocal_bind_unlink ;
};
#line 793
enum __anonenum_LogLevel_27 {
    SYSLOG_LEVEL_QUIET = 0,
    SYSLOG_LEVEL_FATAL = 1,
    SYSLOG_LEVEL_ERROR = 2,
    SYSLOG_LEVEL_INFO = 3,
    SYSLOG_LEVEL_VERBOSE = 4,
    SYSLOG_LEVEL_DEBUG1 = 5,
    SYSLOG_LEVEL_DEBUG2 = 6,
    SYSLOG_LEVEL_DEBUG3 = 7,
    SYSLOG_LEVEL_NOT_SET = -1
} ;
#line 793 "../openssh.h"
typedef enum __anonenum_LogLevel_27 LogLevel;
#line 807 "../openssh.h"
struct allowed_cname {
   char *source_list ;
   char *target_list ;
};
#line 812 "../openssh.h"
struct __anonstruct_Options_28 {
   int forward_agent ;
   int forward_x11 ;
   int forward_x11_timeout ;
   int forward_x11_trusted ;
   int exit_on_forward_failure ;
   char *xauth_location ;
   struct ForwardOptions fwd_opts ;
   int use_privileged_port ;
   int rhosts_rsa_authentication ;
   int rsa_authentication ;
   int pubkey_authentication ;
   int hostbased_authentication ;
   int challenge_response_authentication ;
   int gss_authentication ;
   int gss_deleg_creds ;
   int password_authentication ;
   int kbd_interactive_authentication ;
   char *kbd_interactive_devices ;
   int batch_mode ;
   int check_host_ip ;
   int strict_host_key_checking ;
   int compression ;
   int compression_level ;
   int tcp_keep_alive ;
   int ip_qos_interactive ;
   int ip_qos_bulk ;
   LogLevel log_level ;
   int port ;
   int address_family ;
   int connection_attempts ;
   int connection_timeout ;
   int number_of_password_prompts ;
   int cipher ;
   char *ciphers ;
   char *macs ;
   char *hostkeyalgorithms ;
   char *kex_algorithms ;
   int protocol ;
   char *hostname ;
   char *host_key_alias ;
   char *proxy_command ;
   char *user ;
   int escape_char ;
   u_int___0 num_system_hostfiles ;
   char *system_hostfiles[32] ;
   u_int___0 num_user_hostfiles ;
   char *user_hostfiles[32] ;
   char *preferred_authentications ;
   char *bind_address ;
   char *pkcs11_provider ;
   int verify_host_key_dns ;
   int num_identity_files ;
   char *identity_files[100] ;
   int identity_file_userprovided[100] ;
   struct sshkey *identity_keys[100] ;
   int num_local_forwards ;
   struct Forward *local_forwards ;
   int num_remote_forwards ;
   struct Forward *remote_forwards ;
   int clear_forwardings ;
   int enable_ssh_keysign ;
   int64_t rekey_limit ;
   int rekey_interval ;
   int no_host_authentication_for_localhost ;
   int identities_only ;
   int server_alive_interval ;
   int server_alive_count_max ;
   int num_send_env ;
   char *send_env[256] ;
   char *control_path ;
   int control_master ;
   int control_persist ;
   int control_persist_timeout ;
   int hash_known_hosts ;
   int tun_open ;
   int tun_local ;
   int tun_remote ;
   char *local_command ;
   int permit_local_command ;
   int visual_host_key ;
   int use_roaming ;
   int request_tty ;
   int proxy_use_fdpass ;
   int num_canonical_domains ;
   char *canonical_domains[32] ;
   int canonicalize_hostname ;
   int canonicalize_max_dots ;
   int canonicalize_fallback_local ;
   int num_permitted_cnames ;
   struct allowed_cname permitted_cnames[32] ;
   char *revoked_host_keys ;
   int fingerprint_hash ;
   int update_hostkeys ;
   char *hostbased_key_types ;
   char *ignored_unknown ;
};
#line 812 "../openssh.h"
typedef struct __anonstruct_Options_28 Options;
#line 1019
struct session_state;
#line 1019
struct key_entry;
#line 1019 "../openssh.h"
struct __anonstruct_private_keys_31 {
   struct key_entry *tqh_first ;
   struct key_entry **tqh_last ;
};
#line 1019 "../openssh.h"
struct __anonstruct_public_keys_32 {
   struct key_entry *tqh_first ;
   struct key_entry **tqh_last ;
};
#line 1019 "../openssh.h"
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
#line 1054 "../openssh.h"
struct packet_state {
   u_int32_t___0 seqnr ;
   u_int32_t___0 packets ;
   u_int64_t blocks ;
   u_int64_t bytes ;
};
#line 1061 "../openssh.h"
struct __anonstruct_next_33 {
   struct packet *tqe_next ;
   struct packet **tqe_prev ;
};
#line 1061 "../openssh.h"
struct packet {
   struct __anonstruct_next_33 next ;
   u_char___0 type ;
   struct sshbuf *payload ;
};
#line 1067 "../openssh.h"
typedef int ssh_packet_hook_fn(struct ssh * , struct sshbuf * , u_char___0 * , void * );
#line 1070 "../openssh.h"
typedef int z_stream;
#line 1073
struct sshcipher_ctx;
#line 1073
struct sshmac;
#line 1073 "../openssh.h"
struct __anonstruct_outgoing_34 {
   struct packet *tqh_first ;
   struct packet **tqh_last ;
};
#line 1073 "../openssh.h"
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
#line 14 "openssh_uaf_2.c"
enum monitor_reqtype {
    MONITOR_REQ_MODULI = 0,
    MONITOR_ANS_MODULI = 1,
    MONITOR_REQ_FREE = 2,
    MONITOR_REQ_AUTHSERV = 4,
    MONITOR_REQ_SIGN = 6,
    MONITOR_ANS_SIGN = 7,
    MONITOR_REQ_PWNAM = 8,
    MONITOR_ANS_PWNAM = 9,
    MONITOR_REQ_AUTH2_READ_BANNER = 10,
    MONITOR_ANS_AUTH2_READ_BANNER = 11,
    MONITOR_REQ_AUTHPASSWORD = 12,
    MONITOR_ANS_AUTHPASSWORD = 13,
    MONITOR_REQ_BSDAUTHQUERY = 14,
    MONITOR_ANS_BSDAUTHQUERY = 15,
    MONITOR_REQ_BSDAUTHRESPOND = 16,
    MONITOR_ANS_BSDAUTHRESPOND = 17,
    MONITOR_REQ_SKEYQUERY = 18,
    MONITOR_ANS_SKEYQUERY = 19,
    MONITOR_REQ_SKEYRESPOND = 20,
    MONITOR_ANS_SKEYRESPOND = 21,
    MONITOR_REQ_KEYALLOWED = 22,
    MONITOR_ANS_KEYALLOWED = 23,
    MONITOR_REQ_KEYVERIFY = 24,
    MONITOR_ANS_KEYVERIFY = 25,
    MONITOR_REQ_KEYEXPORT = 26,
    MONITOR_REQ_PTY = 28,
    MONITOR_ANS_PTY = 29,
    MONITOR_REQ_PTYCLEANUP = 30,
    MONITOR_REQ_SESSKEY = 32,
    MONITOR_ANS_SESSKEY = 33,
    MONITOR_REQ_SESSID = 34,
    MONITOR_REQ_RSAKEYALLOWED = 36,
    MONITOR_ANS_RSAKEYALLOWED = 37,
    MONITOR_REQ_RSACHALLENGE = 38,
    MONITOR_ANS_RSACHALLENGE = 39,
    MONITOR_REQ_RSARESPONSE = 40,
    MONITOR_ANS_RSARESPONSE = 41,
    MONITOR_REQ_GSSSETUP = 42,
    MONITOR_ANS_GSSSETUP = 43,
    MONITOR_REQ_GSSSTEP = 44,
    MONITOR_ANS_GSSSTEP = 45,
    MONITOR_REQ_GSSUSEROK = 46,
    MONITOR_ANS_GSSUSEROK = 47,
    MONITOR_REQ_GSSCHECKMIC = 48,
    MONITOR_ANS_GSSCHECKMIC = 49,
    MONITOR_REQ_TERM = 50,
    MONITOR_REQ_PAM_START = 100,
    MONITOR_REQ_PAM_ACCOUNT = 102,
    MONITOR_ANS_PAM_ACCOUNT = 103,
    MONITOR_REQ_PAM_INIT_CTX = 104,
    MONITOR_ANS_PAM_INIT_CTX = 105,
    MONITOR_REQ_PAM_QUERY = 106,
    MONITOR_ANS_PAM_QUERY = 107,
    MONITOR_REQ_PAM_RESPOND = 108,
    MONITOR_ANS_PAM_RESPOND = 109,
    MONITOR_REQ_PAM_FREE_CTX = 110,
    MONITOR_ANS_PAM_FREE_CTX = 111,
    MONITOR_REQ_AUDIT_EVENT = 112,
    MONITOR_REQ_AUDIT_COMMAND = 113
} ;
#line 52 "openssh_uaf_2.c"
struct pollfd {
   int fd ;
   short events ;
   short revents ;
};
#line 97
struct mm_master;
#line 97
struct mm_master;
#line 98 "openssh_uaf_2.c"
struct monitor {
   int m_recvfd ;
   int m_sendfd ;
   int m_log_recvfd ;
   int m_log_sendfd ;
   struct mm_master *m_zback ;
   struct mm_master *m_zlib ;
   struct kex **m_pkex ;
   pid_t___0 m_pid ;
};
#line 112
struct Authctxt;
#line 112 "openssh_uaf_2.c"
typedef struct Authctxt Authctxt;
#line 114
struct KbdintDevice;
#line 114 "openssh_uaf_2.c"
typedef struct KbdintDevice KbdintDevice;
#line 116 "openssh_uaf_2.c"
struct Authctxt {
   sig_atomic_t success ;
   int authenticated ;
   int postponed ;
   int valid ;
   int attempt ;
   int failures ;
   int server_caused_failure ;
   int force_pwchange ;
   char *user ;
   char *service ;
   struct passwd *pw ;
   char *style ;
   void *kbdintctxt ;
   char *info ;
   char **auth_methods ;
   u_int___0 num_auth_methods ;
   Buffer *loginmsg ;
   void *methoddata ;
   struct sshkey **prev_userkeys ;
   u_int___0 nprev_userkeys ;
};
#line 169 "openssh_uaf_2.c"
struct KbdintDevice {
   char const   *name ;
   void *(*init_ctx)(Authctxt * ) ;
   int (*query)(void *ctx , char **name , char **infotxt , u_int___0 *numprompts ,
                char ***prompts , u_int___0 **echo_on ) ;
   int (*respond)(void *ctx , u_int___0 numresp , char **responses ) ;
   void (*free_ctx)(void *ctx ) ;
};
#line 192 "openssh_uaf_2.c"
struct mon_table {
   enum monitor_reqtype type ;
   int flags ;
   int (*f)(int  , Buffer * ) ;
};
#line 322
struct pam_ctxt;
#line 325 "openssh_uaf_2.c"
typedef pid_t___0 sp_pthread_t;
#line 326 "openssh_uaf_2.c"
struct pam_ctxt {
   sp_pthread_t pam_thread ;
   int pam_psock ;
   int pam_csock ;
   int pam_done ;
};
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 468 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 50 "/usr/include/x86_64-linux-gnu/bits/errno.h"
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
#line 70 "openssh_uaf_2.c"
extern int mm_answer_sign(int  , Buffer * ) ;
#line 71
extern int mm_answer_pwnamallow(int  , Buffer * ) ;
#line 72
extern int mm_answer_auth2_read_banner(int  , Buffer * ) ;
#line 73
extern int mm_answer_authserv(int  , Buffer * ) ;
#line 74
extern int mm_answer_authpassword(int  , Buffer * ) ;
#line 79
extern int mm_answer_keyallowed(int  , Buffer * ) ;
#line 80
extern int mm_answer_keyverify(int  , Buffer * ) ;
#line 81
extern int mm_answer_pty(int  , Buffer * ) ;
#line 82
extern int mm_answer_pty_cleanup(int  , Buffer * ) ;
#line 83
extern int mm_answer_term(int  , Buffer * ) ;
#line 92
int mm_answer_pam_init_ctx(int sock , Buffer *m ) ;
#line 94
int mm_answer_pam_respond(int sock , Buffer *m ) ;
#line 95
int mm_answer_pam_free_ctx(int sock , Buffer *m ) ;
#line 110 "openssh_uaf_2.c"
void *sshpam_ctxt  ;
#line 110 "openssh_uaf_2.c"
void *sshpam_authok  ;
#line 185 "openssh_uaf_2.c"
static char *auth_method  =    (char *)"unknown";
#line 186 "openssh_uaf_2.c"
static char *auth_submethod  =    (char *)((void *)0);
#line 206 "openssh_uaf_2.c"
struct mon_table mon_dispatch_proto20[8]  = 
#line 206
  {      {(enum monitor_reqtype )6, 16, & mm_answer_sign}, 
        {(enum monitor_reqtype )8, 16, & mm_answer_pwnamallow}, 
        {(enum monitor_reqtype )4, 16, & mm_answer_authserv}, 
        {(enum monitor_reqtype )10, 16, & mm_answer_auth2_read_banner}, 
        {(enum monitor_reqtype )12, 12, & mm_answer_authpassword}, 
        {(enum monitor_reqtype )22, 4, & mm_answer_keyallowed}, 
        {(enum monitor_reqtype )24, 12, & mm_answer_keyverify}, 
        {(enum monitor_reqtype )0, 0, (int (*)(int  , Buffer * ))((void *)0)}};
#line 245 "openssh_uaf_2.c"
struct mon_table mon_dispatch_postauth20[5]  = {      {(enum monitor_reqtype )6, 0, & mm_answer_sign}, 
        {(enum monitor_reqtype )28, 0, & mm_answer_pty}, 
        {(enum monitor_reqtype )30, 0, & mm_answer_pty_cleanup}, 
        {(enum monitor_reqtype )50, 0, & mm_answer_term}, 
        {(enum monitor_reqtype )0, 0, (int (*)(int  , Buffer * ))((void *)0)}};
#line 260 "openssh_uaf_2.c"
struct mon_table mon_dispatch_proto15[1]  = {      {(enum monitor_reqtype )0, 0, (int (*)(int  , Buffer * ))((void *)0)}};
#line 293 "openssh_uaf_2.c"
struct mon_table mon_dispatch_postauth15[1]  = {      {(enum monitor_reqtype )0, 0, (int (*)(int  , Buffer * ))((void *)0)}};
#line 307
KbdintDevice sshpam_device ;
#line 308 "openssh_uaf_2.c"
Options options  ;
#line 313 "openssh_uaf_2.c"
static int sshpam_authenticated  =    0;
#line 318 "openssh_uaf_2.c"
static Authctxt *sshpam_authctxt  =    (Authctxt *)((void *)0);
#line 320 "openssh_uaf_2.c"
static char badpw[14]  = 
#line 320
  {      (char )'\b',      (char )'\n',      (char )'\r',      (char )'\177', 
        (char )'I',      (char )'N',      (char )'C',      (char )'O', 
        (char )'R',      (char )'R',      (char )'E',      (char )'C', 
        (char )'T',      (char )'\000'};
#line 322 "openssh_uaf_2.c"
static struct pam_ctxt *cleanup_ctxt  ;
#line 323 "openssh_uaf_2.c"
static Authctxt *authctxt  ;
#line 333
static void *sshpam_thread(void *ctxtp ) ;
#line 334
static int sshpam_query(void *ctx , char **name , char **info , u_int___0 *num , char ***prompts ,
                        u_int___0 **echo_on ) ;
#line 341
extern int ( /* missing proto */  debug3)() ;
#line 342
extern int ( /* missing proto */  sshpam_thread_cleanup)() ;
#line 336 "openssh_uaf_2.c"
static void sshpam_free_ctx(void *ctxtp ) 
{ 
  struct pam_ctxt *ctxt ;

  {
#line 339
  ctxt = (struct pam_ctxt *)ctxtp;
#line 341
  debug3("PAM: %s entering", "sshpam_free_ctx");
#line 342
  sshpam_thread_cleanup();
#line 343
  free((void *)ctxt);
#line 350
  return;
}
}
#line 365
extern int ( /* missing proto */  error)() ;
#line 365
extern int ( /* missing proto */  strerror)() ;
#line 367
extern int ( /* missing proto */  close)() ;
#line 364
extern int ( /* missing proto */  pthread_create)() ;
#line 353 "openssh_uaf_2.c"
static void *sshpam_init_ctx(Authctxt *authctxt___0 ) 
{ 
  struct pam_ctxt *ctxt ;
  int socks[2] ;
  void *tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 359
  tmp = calloc((size_t )1, sizeof(*ctxt));
#line 359
  ctxt = (struct pam_ctxt *)tmp;
#line 362
  ctxt->pam_psock = socks[0];
#line 363
  ctxt->pam_csock = socks[1];
#line 364
  tmp___2 = pthread_create(& ctxt->pam_thread, (void *)0, & sshpam_thread, ctxt);
#line 364
  if (tmp___2 == -1) {
#line 365
    tmp___0 = __errno_location();
#line 365
    tmp___1 = strerror(*tmp___0);
#line 365
    error("PAM: failed to start authentication thread: %s", tmp___1);
#line 367
    close(socks[0]);
#line 368
    close(socks[1]);
#line 369
    free((void *)ctxt);
#line 370
    return ((void *)0);
  }
#line 372
  cleanup_ctxt = ctxt;
#line 373
  return ((void *)ctxt);
}
}
#line 396
extern int ( /* missing proto */  buffer_init)() ;
#line 399
extern int ( /* missing proto */  buffer_put_cstring)() ;
#line 402
extern int ( /* missing proto */  buffer_free)() ;
#line 377 "openssh_uaf_2.c"
static int sshpam_respond(void *ctx , u_int___0 num , char **resp ) 
{ 
  Buffer buffer ;
  struct pam_ctxt *ctxt ;

  {
#line 381
  ctxt = (struct pam_ctxt *)ctx;
#line 383
  switch (ctxt->pam_done) {
  case 1: 
#line 385
  sshpam_authenticated = 1;
#line 386
  return (0);
  case 0: 
#line 388
  break;
  default: 
#line 390
  return (-1);
  }
#line 392
  if (num != 1U) {
#line 393
    error("PAM: expected one response, got %u", num);
#line 394
    return (-1);
  }
#line 396
  buffer_init(& buffer);
#line 397
  if (sshpam_authctxt->valid) {
#line 397
    if ((sshpam_authctxt->pw)->pw_uid != 0) {
#line 399
      buffer_put_cstring(& buffer, *resp);
    } else {
#line 401
      buffer_put_cstring(& buffer, badpw);
    }
  } else {
#line 401
    buffer_put_cstring(& buffer, badpw);
  }
#line 402
  buffer_free(& buffer);
#line 403
  return (1);
}
}
#line 407 "openssh_uaf_2.c"
struct mon_table *mon_dispatch  ;
#line 408 "openssh_uaf_2.c"
KbdintDevice sshpam_device  =    {"pam", & sshpam_init_ctx, & sshpam_query, & sshpam_respond, & sshpam_free_ctx};
#line 417 "openssh_uaf_2.c"
int mm_answer_pam_init_ctx(int sock , Buffer *m ) 
{ 


  {
#line 420
  debug3("%s", "mm_answer_pam_init_ctx");
#line 421
  sshpam_ctxt = (*(sshpam_device.init_ctx))(authctxt);
#line 422
  sshpam_authok = (void *)0;
#line 423
  return (0);
}
}
#line 432
extern int ( /* missing proto */  buffer_clear)() ;
#line 433
extern int ( /* missing proto */  mm_request_send)() ;
#line 426 "openssh_uaf_2.c"
int mm_answer_pam_free_ctx(int sock , Buffer *m ) 
{ 


  {
#line 430
  debug3("%s", "mm_answer_pam_free_ctx");
#line 431
  (*(sshpam_device.free_ctx))(sshpam_ctxt);
#line 432
  buffer_clear(m);
#line 433
  mm_request_send(sock, 111, m);
#line 434
  auth_method = (char *)"keyboard-interactive";
#line 435
  auth_submethod = (char *)"pam";
#line 436
  return ((unsigned long )sshpam_authok == (unsigned long )sshpam_ctxt);
}
}
#line 447
extern int ( /* missing proto */  buffer_get_int)() ;
#line 451
extern int ( /* missing proto */  buffer_get_string)() ;
#line 439 "openssh_uaf_2.c"
int mm_answer_pam_respond(int sock , Buffer *m ) 
{ 
  char **resp ;
  u_int___0 i ;
  u_int___0 num ;
  int ret ;
  int tmp ;
  void *tmp___0 ;
  int tmp___1 ;

  {
#line 446
  sshpam_authok = (void *)0;
#line 447
  tmp = buffer_get_int(m);
#line 447
  num = (u_int___0 )tmp;
#line 448
  if (num > 0U) {
#line 449
    tmp___0 = calloc((size_t )num, sizeof(char *));
#line 449
    resp = (char **)tmp___0;
#line 450
    i = (u_int___0 )0;
#line 450
    while (i < num) {
#line 451
      tmp___1 = buffer_get_string(m, (void *)0);
#line 451
      *(resp + i) = (char *)tmp___1;
#line 450
      i ++;
    }
#line 452
    ret = (*(sshpam_device.respond))(sshpam_ctxt, num, resp);
#line 453
    i = (u_int___0 )0;
#line 453
    while (i < num) {
#line 454
      free((void *)*(resp + i));
#line 453
      i ++;
    }
#line 455
    free((void *)resp);
  } else {
#line 457
    ret = (*(sshpam_device.respond))(sshpam_ctxt, num, (char **)((void *)0));
  }
#line 459
  if (ret == 0) {
#line 460
    sshpam_authok = sshpam_ctxt;
  }
#line 461
  return (0);
}
}
#line 477
extern int ( /* missing proto */  mm_request_receive)() ;
#line 478
extern int ( /* missing proto */  buffer_get_char)() ;
#line 494
extern int ( /* missing proto */  debug2)() ;
#line 466 "openssh_uaf_2.c"
int monitor_read(struct monitor *pmonitor , struct mon_table *ent , struct mon_table **pent ) 
{ 
  Buffer m ;
  int ret ;
  u_char___0 type ;
  int tmp ;

  {
#line 475
  buffer_init(& m);
#line 477
  mm_request_receive(pmonitor->m_sendfd, & m);
#line 478
  tmp = buffer_get_char(& m);
#line 478
  type = (u_char___0 )tmp;
#line 480
  while ((unsigned long )ent->f != (unsigned long )((void *)0)) {
#line 481
    if ((unsigned int )ent->type == (unsigned int )type) {
#line 482
      break;
    }
#line 483
    ent ++;
  }
#line 486
  if ((unsigned long )ent->f != (unsigned long )((void *)0)) {
#line 487
    if (! (ent->flags & 4096)) {
#line 488
      printf((char const   * __restrict  )"%s: unpermitted request", "monitor_read");
#line 488
      exit(1);
    }
#line 489
    ret = (*(ent->f))(pmonitor->m_sendfd, & m);
#line 490
    buffer_free(& m);
#line 493
    if (ent->flags & 16) {
#line 494
      debug2("%s: %d used once, disabling now", "monitor_read", (int )type);
#line 496
      ent->flags &= -4097;
    }
#line 499
    if ((unsigned long )pent != (unsigned long )((void *)0)) {
#line 500
      *pent = ent;
    }
#line 502
    return (ret);
  }
#line 505
  printf((char const   * __restrict  )"%s: unsupported request: ", "monitor_read");
#line 505
  exit(1);
#line 508
  return (-1);
}
}
#line 522
extern int ( /* missing proto */  memset)() ;
#line 528
extern int ( /* missing proto */  monitor_permit)() ;
#line 547
extern int ( /* missing proto */  auth_root_allowed)() ;
#line 512 "openssh_uaf_2.c"
void monitor_child_preauth(Authctxt *_authctxt , struct monitor *pmonitor ) 
{ 
  struct mon_table *ent ;
  int authenticated ;
  int partial ;
  int compat20 ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
#line 516
  authenticated = 0;
#line 516
  partial = 0;
#line 519
  tmp = -1;
#line 519
  pmonitor->m_recvfd = tmp;
#line 519
  pmonitor->m_log_sendfd = tmp;
#line 521
  authctxt = _authctxt;
#line 522
  memset(authctxt, 0, sizeof(*authctxt));
#line 524
  if (compat20) {
#line 525
    mon_dispatch = mon_dispatch_proto20;
#line 528
    monitor_permit(mon_dispatch, 0, 1);
#line 529
    monitor_permit(mon_dispatch, 6, 1);
  } else {
#line 531
    mon_dispatch = mon_dispatch_proto15;
#line 533
    monitor_permit(mon_dispatch, 32, 1);
  }
#line 537
  while (! authenticated) {
#line 538
    partial = 0;
#line 539
    auth_method = (char *)"unknown";
#line 540
    auth_submethod = (char *)((void *)0);
#line 541
    tmp___0 = monitor_read(pmonitor, mon_dispatch, & ent);
#line 541
    authenticated = tmp___0 == 1;
#line 543
    if (authenticated) {
#line 544
      if (! (ent->flags & 8)) {
#line 545
        printf((char const   * __restrict  )"%s: unexpected authentication from %d",
               "monitor_child_preauth");
#line 545
        exit(1);
      }
#line 547
      if ((authctxt->pw)->pw_uid == 0) {
#line 547
        tmp___1 = auth_root_allowed(auth_method);
#line 547
        if (! tmp___1) {
#line 549
          authenticated = 0;
        }
      }
    }
  }
#line 553
  return;
}
}
#line 557 "openssh_uaf_2.c"
int main(void) 
{ 
  struct monitor pmonitor ;
  Authctxt authctxt___0 ;

  {
#line 560
  monitor_child_preauth(& authctxt___0, & pmonitor);
#line 561
  return (0);
}
}
