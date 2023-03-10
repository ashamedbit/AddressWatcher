/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
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
#line 320 "../openssl.h"
struct evp_cipher_st;
#line 320 "../openssl.h"
typedef struct evp_cipher_st EVP_CIPHER;
#line 321
struct evp_cipher_ctx_st;
#line 321 "../openssl.h"
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
#line 323
struct evp_md_ctx_st;
#line 323 "../openssl.h"
typedef struct evp_md_ctx_st EVP_MD_CTX;
#line 379
struct ssl_st;
#line 379 "../openssl.h"
typedef struct ssl_st SSL;
#line 380
struct ssl_ctx_st;
#line 380 "../openssl.h"
typedef struct ssl_ctx_st SSL_CTX;
#line 382
struct comp_ctx_st;
#line 382 "../openssl.h"
typedef struct comp_ctx_st COMP_CTX;
#line 21 "openssl_df_4.c"
struct __anonstruct_RECORD_LAYER_27 {

};
#line 21 "openssl_df_4.c"
typedef struct __anonstruct_RECORD_LAYER_27 RECORD_LAYER;
#line 23
struct cert_st;
#line 23 "openssl_df_4.c"
struct ssl_st {
   EVP_CIPHER_CTX *enc_read_ctx ;
   unsigned char read_iv[16] ;
   EVP_MD_CTX *read_hash ;
   COMP_CTX *compress ;
   COMP_CTX *expand ;
   EVP_CIPHER_CTX *enc_write_ctx ;
   unsigned char write_iv[16] ;
   EVP_MD_CTX *write_hash ;
   struct cert_st *cert ;
   RECORD_LAYER rlayer ;
};
#line 47 "openssl_df_4.c"
struct record_data {
   char const   *plaintext ;
   char const   *ciphertext ;
   char const   *key ;
   char const   *iv ;
   char const   *seq ;
};
#line 226 "openssl_df_4.c"
struct ssl3_record_st {
   int rec_version ;
   int type ;
   size_t length ;
   size_t orig_len ;
   size_t off ;
   unsigned char *data ;
   unsigned char *input ;
   unsigned char *comp ;
   unsigned int read ;
   unsigned long epoch ;
   unsigned char seq_num[8] ;
};
#line 226 "openssl_df_4.c"
typedef struct ssl3_record_st SSL3_RECORD;
#line 170 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr ;
#line 356
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 47 "openssl_df_4.c"
struct record_data refdata[7]  = {      {"0800001e001c000a00140012001d00170018001901000101010201030104000000000b0001b9000001b50001b0308201ac30820115a003020102020102300d06092a864886f70d01010b0500300e310c300a06035504031303727361301e170d3136303733303031323335395a170d3236303733303031323335395a300e310c300a0603550403130372736130819f300d06092a864886f70d010101050003818d0030818902818100b4bb498f8279303d980836399b36c6988c0c68de55e1bdb826d3901a2461eafd2de49a91d015abbc9a95137ace6c1af19eaa6af98c7ced43120998e187a80ee0ccb0524b1b018c3e0b63264d449a6d38e22a5fda430846748030530ef0461c8ca9d9efbfae8ea6d1d03e2bd193eff0ab9a8002c47428a6d35a8d88d79f7f1e3f0203010001a31a301830090603551d1304023000300b0603551d0f0404030205a0300d06092a864886f70d01010b05000381810085aad2a0e5b9276b908c65f73a7267170618a54c5f8a7b337d2df7a594365417f2eae8f8a58c8f8172f9319cf36b7fd6c55b80f21a03015156726096fd335e5e67f2dbf102702e608ccae6bec1fc63a42a99be5c3eb7107c3c54e9b9eb2bd5203b1c3b84e0a8b2f759409ba3eac9d91d402dcc0cc8f8961229ac9187b42b4de100000f00008408040080134e22eac57321ab47db6b38b2992cec2dd79bd065a034a9af6b9e3d03475e4309e6523ccdf055453fb480804a3a7e996229eb28e734f6702bea2b32149899ac043a4b44468197868da77147ce9f73c0543c4e3fc33e306cac8506faa80a959c5f1edccbee76eda1ad7a4fa440de35dcb87e82ec94e8725355ce7507713a609e140000207304bb73321f01b71dd94622fae98daf634490d220e4c8f3ffa2559911a56e5116",
      "40ae92071a3a548b26af31e116dfc0ba4549210b17e70da16cfbda9ccdad844d94264a9ae65b786b3eaf0de20aa89c6babb448b6f32d07f233584296eefe19316bd979659472ee8567cb01d70b0366cddb3c60eb9e1d789a3691dc254c14de73f4f20100504544ce184d44547e124b1f18303b4859f8f2e2b04423d23a866b43866374d54af41649d25f4a3ec2cecd5d4e6de1b24953440b46fbb74c1dbec6fbb1f16bc21d4aa0e1e936a49c07127e19719bc652a2f0b7f8df4a150b2b3c9e9e353d6ed101970ddc611abad0632c6793f9379c9d06846c311fcbd6f85edd569b8782c4c5f62294c4611ae60f83230a53aa95e3bcbed204f19a7a1db83c0fbfec1edd2c17498fa7b5aa2321248a92592d891e4947df6bcef52f4481797d032ad332046a384abece6454b3e356d7249bfa5696793c7f7d3048dc87fa7409a4691887caaf0982c402b902d699f62dc4d5e153f13e8589e4a6206c7f74eb26ddefbb92309fb753decfea972dec7de02eda9c6d26acd7be53a8aa20f1a93f082ae6eb927a6a1b7bd9153551aedfaf94f61dd4cb9355ad7ab09f615d9f92c21712c732c0e7e117797f38cbdc184e3a65e15a89f46cb3624f5fdb8dbbd275f2c8492f8d95bdbd8d1dc1b9f21107bd433acbbac247239c073a2f24a4a9f8074f325f277d579b6bff0269ff19aed3809a9ddd21dd29c1363c9dc44812dd41d2111f9c2e8342046c14133b853262676f15e94de18660e04ae5c0c661ea43559af5842e161c83dd29f64508b2ec3e635a2134fc0e1a39d3ecb51dcddfcf8382c88ffe2a737842ad1de7fe505b6c4d1673870f6fc2a0f2f7972acaee368a1599d64ba18798f10333f9779bd5b05f9b084d03dab2f3d80c2eb74ec70c9866ea31c18b491cd597aae3e941205fcc38a3a10ce8c0269f02ccc9c51278e25f1a0f0731a9",
      "d2dd45f87ad87801a85ac38187f9023b", "f0a14f808692cef87a3daf70", "0000000000000000"}, 
        {"1400002078367856d3c8cc4e0a95eb98906ca7a48bd3cc7029f48bd4ae0dc91ab903ca8916",
      "fa15e92daa21cd05d8f9c3152a61748d9aaf049da559718e583f95aacecad657b52a6562da09a5819e864d86ac2989360a1eb22795",
      "40e1201d75d419627f04c88530a15c9d", "a0f073f3b35e18f96969696b", "0000000000000000"}, 
        {"040000a60002a3004abe594b00924e535321cadc96238da09caf9b02fecafdd65e3e418f03e43772cf512ed8066100503b1c08abbbf298a9d138ce821dd12fe1710e2137cd12e6a85cd3fd7f73706e7f5dddefb87c1ef83824638464099c9d1363e3c64ed2075c16b8ccd8e524a6bbd7a6a6e34ea1579782b15bbe7dfed5c0c0d980fb330f9d8ab252ffe7be1277d418b6828ead4dae3b30d448442417ef76af0008002e00040002000016",
      "45a6626fa13b66ce2c5b3ef807e299a118296f26a2dd9ec7487a0673e2460d4c79f40087dcd014c59c51379c90d26b4e4f9bb2b78f5b6761594f013ff3e4c78d836905229eac811c4ef8b2faa89867e9ffc586f7f03c216591aa5e620eac3c62dfe60f846036bd7ecc4464b584af184e9644e94ee1d7834dba408a51cbe4248004796ed9c558e0f5f96115a6f6ba487e17d16a2e20a3d3a650a9a070fb53d9da82864b5621d77650bd0c7947e9889917b53d0515627c72b0ded521",
      "3381f6b3f94500f16226de440193e858", "4f1d73cc1d465eb30021c41f", "0000000000000000"}, 
        {"000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303117",
      "e306178ad97f74bb64f35eaf3c39846b83aef8472cbc9046749b81a949dfb12cfbc65cbabd20ade92c1f944605892ceeb12fdee8a927bce77c83036ac5a794a8f54a69",
      "eb23a804904b80ba4fe8399e09b1ce42", "efa8c50c06b9c9b8c483e174", "0000000000000000"}, 
        {"000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303117",
      "467d99a807dbf778e6ffd8be52456c70665f890811ef2f3c495d5bbe983feedab0c251dde596bc7e2b135909ec9f9166fb0152e8c16a84e4b1039256467f9538be4463",
      "3381f6b3f94500f16226de440193e858", "4f1d73cc1d465eb30021c41f", "0000000000000001"}, 
        {"010015",
      "6bdf60847ba6fb650da36e872adc684a4af2e8", "eb23a804904b80ba4fe8399e09b1ce42",
      "efa8c50c06b9c9b8c483e174", "0000000000000001"}, 
        {"010015", "621b7cc1962cd8a70109fee68a52efedf87d2e", "3381f6b3f94500f16226de440193e858",
      "4f1d73cc1d465eb30021c41f", "0000000000000002"}};
#line 271
extern int ( /* missing proto */  strdup)() ;
#line 285
extern int ( /* missing proto */  memcpy)() ;
#line 265 "openssl_df_4.c"
static int load_record(SSL3_RECORD *rec , size_t recnum , unsigned char **key , unsigned char *iv ,
                       size_t ivlen , unsigned char *seq ) 
{ 
  unsigned char *pt ;
  unsigned char *sq ;
  unsigned char *ivtmp ;
  long ptlen ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  unsigned char *tmp___3 ;
  void *tmp___4 ;

  {
#line 268
  pt = (unsigned char *)((void *)0);
#line 268
  sq = (unsigned char *)((void *)0);
#line 268
  ivtmp = (unsigned char *)((void *)0);
#line 271
  tmp = strdup(refdata[recnum].key);
#line 271
  *key = (unsigned char *)tmp;
#line 272
  tmp___0 = strdup(refdata[recnum].iv);
#line 272
  ivtmp = (unsigned char *)tmp___0;
#line 273
  tmp___1 = strdup(refdata[recnum].seq);
#line 273
  sq = (unsigned char *)tmp___1;
#line 274
  tmp___2 = strdup(refdata[recnum].plaintext);
#line 274
  pt = (unsigned char *)tmp___2;
#line 276
  if ((unsigned long )*key == (unsigned long )((void *)0)) {
#line 277
    goto err;
  } else
#line 276
  if ((unsigned long )ivtmp == (unsigned long )((void *)0)) {
#line 277
    goto err;
  } else
#line 276
  if ((unsigned long )sq == (unsigned long )((void *)0)) {
#line 277
    goto err;
  } else
#line 276
  if ((unsigned long )pt == (unsigned long )((void *)0)) {
#line 277
    goto err;
  }
#line 279
  tmp___4 = malloc((size_t )(ptlen + 16L));
#line 279
  tmp___3 = (unsigned char *)tmp___4;
#line 279
  rec->input = tmp___3;
#line 279
  rec->data = tmp___3;
#line 281
  if ((unsigned long )rec->data == (unsigned long )((void *)0)) {
#line 282
    goto err;
  }
#line 284
  rec->length = (size_t )ptlen;
#line 285
  memcpy(rec->data, pt, ptlen);
#line 286
  free((void *)pt);
#line 287
  memcpy(seq, sq, 8);
#line 288
  free((void *)sq);
#line 289
  memcpy(iv, ivtmp, ivlen);
#line 290
  free((void *)ivtmp);
#line 292
  return (1);
  err: 
#line 294
  free((void *)*key);
#line 295
  free((void *)ivtmp);
#line 296
  free((void *)sq);
#line 297
  free((void *)pt);
#line 298
  return (0);
}
}
#line 307
extern int ( /* missing proto */  EVP_aes_128_gcm)() ;
#line 313
extern int ( /* missing proto */  SSL_CTX_new)() ;
#line 313
extern int ( /* missing proto */  TLS_method)() ;
#line 319
extern int ( /* missing proto */  SSL_new)() ;
#line 330
extern int ( /* missing proto */  EVP_CIPHER_iv_length)() ;
#line 331
extern int ( /* missing proto */  RECORD_LAYER_get_read_sequence)() ;
#line 337
extern int ( /* missing proto */  RECORD_LAYER_get_write_sequence)() ;
#line 341
extern int ( /* missing proto */  EVP_CipherInit_ex)() ;
#line 349
extern int ( /* missing proto */  tls13_enc)() ;
#line 354
extern int ( /* missing proto */  test_record)() ;
#line 325
extern int ( /* missing proto */  OSSL_NELEM)() ;
#line 386
extern int ( /* missing proto */  SSL_free)() ;
#line 387
extern int ( /* missing proto */  SSL_CTX_free)() ;
#line 301 "openssl_df_4.c"
static int test_tls13_encryption(void) 
{ 
  SSL_CTX *ctx ;
  SSL *s ;
  SSL3_RECORD rec ;
  unsigned char *key ;
  unsigned char *iv ;
  unsigned char *seq ;
  EVP_CIPHER const   *ciph ;
  int tmp ;
  int ret ;
  size_t ivlen ;
  size_t ctr ;
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
  int tmp___14 ;

  {
#line 303
  ctx = (SSL_CTX *)((void *)0);
#line 304
  s = (SSL *)((void *)0);
#line 306
  key = (unsigned char *)((void *)0);
#line 306
  iv = (unsigned char *)((void *)0);
#line 306
  seq = (unsigned char *)((void *)0);
#line 307
  tmp = EVP_aes_128_gcm();
#line 307
  ciph = (EVP_CIPHER const   *)tmp;
#line 308
  ret = 0;
#line 311
  rec.data = (unsigned char *)((void *)0);
#line 313
  tmp___0 = TLS_method();
#line 313
  tmp___1 = SSL_CTX_new(tmp___0);
#line 313
  ctx = (SSL_CTX *)tmp___1;
#line 314
  if ((unsigned long )ctx == (unsigned long )((void *)0)) {
#line 315
    fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed creating SSL_CTX\n");
#line 316
    goto err;
  }
#line 319
  tmp___2 = SSL_new(ctx);
#line 319
  s = (SSL *)tmp___2;
#line 320
  if ((unsigned long )s == (unsigned long )((void *)0)) {
#line 321
    fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed creating SSL\n");
#line 322
    goto err;
  }
#line 325
  ctr = (size_t )0;
#line 325
  while (1) {
#line 325
    tmp___14 = OSSL_NELEM(refdata);
#line 325
    if (! (ctr < (size_t )tmp___14)) {
#line 325
      break;
    }
#line 330
    tmp___3 = EVP_CIPHER_iv_length(ciph);
#line 330
    ivlen = (size_t )tmp___3;
#line 331
    tmp___4 = RECORD_LAYER_get_read_sequence(& s->rlayer);
#line 331
    tmp___5 = load_record(& rec, ctr, & key, s->read_iv, ivlen, (unsigned char *)tmp___4);
#line 331
    if (! tmp___5) {
#line 333
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed loading key into EVP_CIPHER_CTX\n");
#line 334
      goto err;
    }
#line 337
    tmp___6 = RECORD_LAYER_get_read_sequence(& s->rlayer);
#line 337
    tmp___7 = RECORD_LAYER_get_write_sequence(& s->rlayer);
#line 337
    memcpy(tmp___7, tmp___6, 8);
#line 339
    memcpy(s->write_iv, s->read_iv, ivlen);
#line 341
    tmp___8 = EVP_CipherInit_ex(s->enc_write_ctx, ciph, (void *)0, key, (void *)0,
                                1);
#line 341
    if (tmp___8 <= 0) {
#line 344
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed loading key into EVP_CIPHER_CTX\n");
#line 345
      goto err;
    } else {
#line 341
      tmp___9 = EVP_CipherInit_ex(s->enc_read_ctx, ciph, (void *)0, key, (void *)0,
                                  0);
#line 341
      if (tmp___9 <= 0) {
#line 344
        fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed loading key into EVP_CIPHER_CTX\n");
#line 345
        goto err;
      }
    }
#line 349
    tmp___10 = tls13_enc(s, & rec, 1, 1);
#line 349
    if (tmp___10 != 1) {
#line 350
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed to encrypt record\n");
#line 351
      goto err;
    }
#line 354
    tmp___11 = test_record(& rec, ctr, 1);
#line 354
    if (! tmp___11) {
#line 355
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Record encryption test failed\n");
#line 356
      goto err;
    }
#line 360
    tmp___12 = tls13_enc(s, & rec, 1, 0);
#line 360
    if (tmp___12 != 1) {
#line 361
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Failed to decrypt record\n");
#line 362
      goto err;
    }
#line 365
    tmp___13 = test_record(& rec, ctr, 0);
#line 365
    if (! tmp___13) {
#line 366
      fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Record decryption test failed\n");
#line 367
      goto err;
    }
#line 370
    free((void *)rec.data);
#line 371
    free((void *)key);
#line 372
    free((void *)iv);
#line 373
    free((void *)seq);
#line 374
    rec.data = (unsigned char *)((void *)0);
#line 375
    key = (unsigned char *)((void *)0);
#line 376
    iv = (unsigned char *)((void *)0);
#line 377
    seq = (unsigned char *)((void *)0);
#line 325
    ctr ++;
  }
#line 380
  ret = 1;
  err: 
#line 382
  free((void *)rec.data);
#line 383
  free((void *)key);
#line 384
  free((void *)iv);
#line 385
  free((void *)seq);
#line 386
  SSL_free(s);
#line 387
  SSL_CTX_free(ctx);
#line 389
  return (ret);
}
}
#line 392 "openssl_df_4.c"
int main(void) 
{ 


  {
#line 394
  test_tls13_encryption();
#line 395
  return (0);
}
}
