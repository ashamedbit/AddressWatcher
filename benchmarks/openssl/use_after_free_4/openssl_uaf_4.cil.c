/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 286 "../openssl.h"
struct asn1_string_st;
#line 301 "../openssl.h"
typedef struct asn1_string_st ASN1_STRING;
#line 431 "../openssl.h"
struct asn1_string_st {
   int length ;
   int type ;
   unsigned char *data ;
   long flags ;
};
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 269 "openssl_uaf_4.c"
static signed char const   tag2nbyte[31]  = 
#line 269 "openssl_uaf_4.c"
  {      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )0,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )1, 
        (signed char const   )1,      (signed char const   )-1,      (signed char const   )1,      (signed char const   )1, 
        (signed char const   )1,      (signed char const   )-1,      (signed char const   )1,      (signed char const   )-1, 
        (signed char const   )4,      (signed char const   )-1,      (signed char const   )2};
#line 286
extern int ( /* missing proto */  ASN1err)() ;
#line 279 "openssl_uaf_4.c"
ASN1_STRING *ASN1_STRING_type_new(int type ) 
{ 
  ASN1_STRING *ret ;
  void *tmp ;

  {
#line 283
  tmp = malloc(sizeof(ASN1_STRING ));
#line 283
  ret = (ASN1_STRING *)tmp;
#line 284
  if ((unsigned long )ret == (unsigned long )((void *)0)) {
#line 286
    ASN1err(130, 65);
#line 287
    return ((ASN1_STRING *)((void *)0));
  }
#line 289
  ret->length = 0;
#line 290
  ret->type = type;
#line 291
  ret->data = (unsigned char *)((void *)0);
#line 292
  ret->flags = 0L;
#line 293
  return (ret);
}
}
#line 300
extern int ( /* missing proto */  skip_prefix)() ;
#line 296 "openssl_uaf_4.c"
static int equal_nocase(unsigned char const   *pattern , size_t pattern_len , unsigned char const   *subject ,
                        size_t subject_len , unsigned int flags ) 
{ 
  unsigned char l ;
  unsigned char r ;

  {
#line 300
  skip_prefix(& pattern, & pattern_len, subject, subject_len, flags);
#line 301
  if (pattern_len != subject_len) {
#line 302
    return (0);
  }
#line 303
  while (pattern_len) {
#line 305
    l = (unsigned char )*pattern;
#line 306
    r = (unsigned char )*subject;
#line 308
    if ((int )l == 0) {
#line 309
      return (0);
    }
#line 310
    if ((int )l != (int )r) {
#line 312
      if (65 <= (int )l) {
#line 312
        if ((int )l <= 90) {
#line 313
          l = (unsigned char )(((int )l - 65) + 97);
        }
      }
#line 314
      if (65 <= (int )r) {
#line 314
        if ((int )r <= 90) {
#line 315
          r = (unsigned char )(((int )r - 65) + 97);
        }
      }
#line 316
      if ((int )l != (int )r) {
#line 317
        return (0);
      }
    }
#line 319
    pattern ++;
#line 320
    subject ++;
#line 321
    pattern_len --;
  }
#line 323
  return (1);
}
}
#line 329
int ASN1_mbstring_ncopy(ASN1_STRING **out , unsigned char const   *in , int len ,
                        int inform , unsigned long mask , long minsize , long maxsize ) ;
#line 326 "openssl_uaf_4.c"
int ASN1_mbstring_copy(ASN1_STRING **out , unsigned char const   *in , int len , int inform ,
                       unsigned long mask ) 
{ 
  int tmp ;

  {
#line 329
  tmp = ASN1_mbstring_ncopy(out, in, len, inform, mask, 0, 0);
#line 329
  return (tmp);
}
}
#line 345
extern int ( /* missing proto */  strlen)() ;
#line 385
extern int ( /* missing proto */  BIO_snprintf)() ;
#line 386
extern int ( /* missing proto */  ERR_add_error_data)() ;
#line 435
extern int ( /* missing proto */  ASN1_STRING_set)() ;
#line 443
extern int ( /* missing proto */  ASN1_STRING_free)() ;
#line 450
extern int ( /* missing proto */  traverse_string)() ;
#line 332 "openssl_uaf_4.c"
int ASN1_mbstring_ncopy(ASN1_STRING **out , unsigned char const   *in , int len ,
                        int inform , unsigned long mask , long minsize , long maxsize ) 
{ 
  int str_type ;
  char free_out ;
  int outform ;
  int outlen ;
  ASN1_STRING *dest ;
  unsigned char *p ;
  int nchar ;
  char strbuf[32] ;
  int (*cpyfunc)(unsigned long  , void * ) ;
  int tmp ;
  void *tmp___0 ;

  {
#line 339
  outlen = 0;
#line 344
  cpyfunc = (int (*)(unsigned long  , void * ))((void *)0);
#line 345
  if (len == -1) {
#line 345
    len = strlen((char const   *)in);
  }
#line 346
  if (! mask) {
#line 346
    mask = 10246UL;
  }
#line 349
  switch (inform) {
  case 4098: 
#line 352
  if (len & 1) {
#line 353
    ASN1err(122, 129);
#line 355
    return (-1);
  }
#line 357
  nchar = len >> 1;
#line 358
  break;
  case 4100: 
#line 361
  if (len & 3) {
#line 362
    ASN1err(122, 133);
#line 364
    return (-1);
  }
#line 366
  nchar = len >> 2;
#line 367
  break;
  case 4096: 
#line 370
  nchar = 0;
#line 372
  break;
  case 4097: 
#line 375
  nchar = len;
#line 376
  break;
  default: 
#line 379
  ASN1err(122, 160);
#line 380
  return (-1);
  }
#line 383
  if (minsize > 0L) {
#line 383
    if ((long )nchar < minsize) {
#line 384
      ASN1err(122, 152);
#line 385
      BIO_snprintf(strbuf, sizeof(strbuf), "%ld", minsize);
#line 386
      ERR_add_error_data(2, "minsize=", strbuf);
#line 387
      return (-1);
    }
  }
#line 390
  if (maxsize > 0L) {
#line 390
    if ((long )nchar > maxsize) {
#line 391
      ASN1err(122, 151);
#line 392
      BIO_snprintf(strbuf, sizeof(strbuf), "%ld", maxsize);
#line 393
      ERR_add_error_data(2, "maxsize=", strbuf);
#line 394
      return (-1);
    }
  }
#line 399
  outform = 4097;
#line 400
  if (mask & 2UL) {
#line 400
    str_type = 19;
  } else
#line 401
  if (mask & 16UL) {
#line 401
    str_type = 22;
  } else
#line 402
  if (mask & 4UL) {
#line 402
    str_type = 20;
  } else
#line 403
  if (mask & 2048UL) {
#line 404
    str_type = 30;
#line 405
    outform = 4098;
  } else
#line 406
  if (mask & 256UL) {
#line 407
    str_type = 28;
#line 408
    outform = 4100;
  } else {
#line 410
    str_type = 12;
#line 411
    outform = 4096;
  }
#line 413
  if (! out) {
#line 413
    return (str_type);
  }
#line 414
  if (*out) {
#line 415
    free_out = (char)0;
#line 416
    dest = *out;
#line 417
    if (dest->data) {
#line 418
      dest->length = 0;
#line 419
      free((void *)dest->data);
#line 420
      dest->data = (unsigned char *)((void *)0);
    }
#line 422
    dest->type = str_type;
  } else {
#line 424
    free_out = (char)1;
#line 425
    dest = ASN1_STRING_type_new(str_type);
#line 426
    if (! dest) {
#line 427
      ASN1err(122, 65);
#line 429
      return (-1);
    }
#line 431
    *out = dest;
  }
#line 434
  if (inform == outform) {
#line 435
    tmp = ASN1_STRING_set(dest, in, len);
#line 435
    if (! tmp) {
#line 436
      ASN1err(122, 65);
#line 437
      return (-1);
    }
#line 439
    return (str_type);
  }
#line 442
  tmp___0 = malloc((size_t )(outlen + 1));
#line 442
  p = (unsigned char *)tmp___0;
#line 442
  if (! p) {
#line 443
    if (free_out) {
#line 443
      ASN1_STRING_free(dest);
    }
#line 444
    ASN1err(122, 65);
#line 445
    return (-1);
  }
#line 447
  dest->length = outlen;
#line 448
  dest->data = p;
#line 449
  *(p + outlen) = (unsigned char)0;
#line 450
  traverse_string(in, len, inform, cpyfunc, & p);
#line 451
  return (str_type);
}
}
#line 458 "openssl_uaf_4.c"
int ASN1_STRING_to_UTF8(unsigned char **out , ASN1_STRING *in ) 
{ 
  ASN1_STRING stmp ;
  ASN1_STRING *str ;
  int mbflag ;
  int type ;
  int ret ;

  {
#line 460
  str = & stmp;
#line 462
  if (! in) {
#line 462
    return (-1);
  }
#line 463
  type = in->type;
#line 464
  if (type < 0) {
#line 464
    return (-1);
  } else
#line 464
  if (type > 30) {
#line 464
    return (-1);
  }
#line 465
  mbflag = (int )tag2nbyte[type];
#line 466
  if (mbflag == -1) {
#line 466
    return (-1);
  }
#line 467
  mbflag |= 4096;
#line 468
  stmp.data = (unsigned char *)((void *)0);
#line 469
  stmp.length = 0;
#line 470
  ret = ASN1_mbstring_copy(& str, (unsigned char const   *)in->data, in->length, mbflag,
                           8192UL);
#line 471
  if (ret < 0) {
#line 471
    return (ret);
  }
#line 472
  *out = stmp.data;
#line 473
  return (stmp.length);
}
}
#line 495
extern int ( /* missing proto */  memcmp)() ;
#line 498
extern int ( /* missing proto */  BUF_strndup)() ;
#line 480 "openssl_uaf_4.c"
static int do_check_string(ASN1_STRING *a , int cmp_type , int (*equal)(unsigned char const   *pattern ,
                                                                        size_t pattern_len ,
                                                                        unsigned char const   *subject ,
                                                                        size_t subject_len ,
                                                                        unsigned int flags ) ,
                           unsigned int flags , char const   *b , size_t blen , char **peername ) 
{ 
  int rv ;
  int tmp ;
  int tmp___0 ;
  int astrlen ;
  unsigned char *astr ;
  int tmp___1 ;

  {
#line 484
  rv = 0;
#line 486
  if (! a->data) {
#line 487
    return (0);
  } else
#line 486
  if (! a->length) {
#line 487
    return (0);
  }
#line 488
  if (cmp_type > 0) {
#line 490
    if (cmp_type != a->type) {
#line 491
      return (0);
    }
#line 492
    if (cmp_type == 22) {
#line 493
      rv = (*equal)((unsigned char const   *)a->data, (size_t )a->length, (unsigned char const   *)((unsigned char *)b),
                    blen, flags);
    } else
#line 495
    if (a->length == (int )blen) {
#line 495
      tmp = memcmp(a->data, b, blen);
#line 495
      if (! tmp) {
#line 496
        rv = 1;
      }
    }
#line 497
    if (rv > 0) {
#line 497
      if (peername) {
#line 498
        tmp___0 = BUF_strndup((char *)a->data, a->length);
#line 498
        *peername = (char *)tmp___0;
      }
    }
  } else {
#line 504
    astrlen = ASN1_STRING_to_UTF8(& astr, a);
#line 505
    if (astrlen < 0) {
#line 506
      return (-1);
    }
#line 507
    rv = (*equal)((unsigned char const   *)astr, (size_t )astrlen, (unsigned char const   *)((unsigned char *)b),
                  blen, flags);
#line 508
    free((void *)astr);
#line 509
    if (rv > 0) {
#line 509
      if (peername) {
#line 510
        tmp___1 = BUF_strndup((char *)astr, astrlen);
#line 510
        *peername = (char *)tmp___1;
      }
    }
  }
#line 512
  return (rv);
}
}
#line 515 "openssl_uaf_4.c"
int main(void) 
{ 
  ASN1_STRING a ;
  int cmp_type ;
  unsigned int flags ;
  char const   *b ;
  char *peername ;
  size_t blen ;
  int tmp ;

  {
#line 520
  b = "bbbb";
#line 521
  peername = (char *)b;
#line 522
  tmp = strlen(b);
#line 522
  blen = (size_t )tmp;
#line 523
  do_check_string(& a, cmp_type, & equal_nocase, flags, b, blen, & peername);
#line 524
  return (0);
}
}