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
#line 203 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned long u_int64_t;
#line 196 "../stdio.h"
typedef unsigned int u_int___0;
#line 197 "../stdio.h"
typedef unsigned long u_long___0;
#line 200 "../stdio.h"
typedef int int32_t___0;
#line 207 "../stdio.h"
typedef unsigned char u_char___0;
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
#line 1191
struct Key;
#line 1191 "../openssh.h"
typedef struct Key Key;
#line 1203 "../openssh.h"
struct KeyCert {
   Buffer certblob ;
   u_int___0 type ;
   u_int64_t serial ;
   char *key_id ;
   u_int___0 nprincipals ;
   char **principals ;
   u_int64_t valid_after ;
   u_int64_t valid_before ;
   Buffer critical ;
   Buffer extensions ;
   Key *signature_key ;
};
#line 1216 "../openssh.h"
struct Key {
   int type ;
   int flags ;
   RSA *rsa ;
   DSA *dsa ;
   int ecdsa_nid ;
   void *ecdsa ;
   struct KeyCert *cert ;
   u_char___0 *ed25519_sk ;
   u_char___0 *ed25519_pk ;
};
#line 24 "openssh_df_4.c"
struct __anonstruct_keys_37 {
   char const   *key ;
   char const   *repl ;
};
#line 237 "/usr/include/stdio.h"
extern int fclose(FILE *__stream ) ;
#line 362
extern int printf(char const   * __restrict  __format  , ...) ;
#line 386
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
#line 531
extern int fgetc(FILE *__stream ) ;
#line 622
extern char *fgets(char * __restrict  __s , int __n , FILE * __restrict  __stream ) ;
#line 828
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof)(FILE *__stream ) ;
#line 483 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 50 "openssh_df_4.c"
extern int ( /* missing proto */  strlcat)() ;
#line 49
extern int ( /* missing proto */  strchr)() ;
#line 59
extern int ( /* missing proto */  strdup)() ;
#line 20 "openssh_df_4.c"
char *percent_expand(char const   *string  , ...) 
{ 
  struct __anonstruct_keys_37 keys[16] ;
  u_int___0 num_keys ;
  u_int___0 i ;
  u_int___0 j ;
  char buf[4096] ;
  u_int___0 tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 31
  if (num_keys >= 16U) {
#line 32
    printf((char const   * __restrict  )"percent_expand: too many keys%s", "");
#line 32
    exit(1);
  }
#line 35
  buf[0] = (char )'\000';
#line 36
  i = (u_int___0 )0;
#line 36
  while ((int const   )*string != 0) {
#line 37
    if ((int const   )*string != 37) {
      append: 
#line 39
      tmp = i;
#line 39
      i ++;
#line 39
      buf[tmp] = (char )*string;
#line 40
      if ((unsigned long )i >= sizeof(buf)) {
#line 41
        printf((char const   * __restrict  )"percent_expand: string too long%s", "");
#line 41
        exit(1);
      }
#line 42
      buf[i] = (char )'\000';
#line 43
      goto __Cont;
    }
#line 45
    string ++;
#line 46
    if ((int const   )*string == 37) {
#line 47
      goto append;
    }
#line 48
    j = (u_int___0 )0;
#line 48
    while (j < num_keys) {
#line 49
      tmp___1 = strchr(keys[j].key, (int const   )*string);
#line 49
      if ((unsigned long )tmp___1 != (unsigned long )((void *)0)) {
#line 50
        tmp___0 = strlcat(buf, keys[j].repl, sizeof(buf));
#line 50
        i = (u_int___0 )tmp___0;
#line 51
        if ((unsigned long )i >= sizeof(buf)) {
#line 52
          printf((char const   * __restrict  )"percent_expand: string too long%s",
                 "");
#line 52
          exit(1);
        }
#line 53
        break;
      }
#line 48
      j ++;
    }
#line 56
    if (j >= num_keys) {
#line 57
      printf((char const   * __restrict  )"percent_expand: unknown key %c", (int const   )*string);
#line 57
      exit(1);
    }
    __Cont: /* CIL Label */ 
#line 36
    string ++;
  }
#line 59
  tmp___2 = strdup(buf);
#line 59
  return ((char *)tmp___2);
}
}
#line 71 "openssh_df_4.c"
static char *expand_authorized_keys(char const   *filename , struct passwd *pw ) 
{ 
  char *file ;
  char ret[64] ;
  int i ;
  int tmp ;

  {
#line 77
  file = percent_expand(filename, "h", pw->pw_dir, "u", pw->pw_name, (char *)((void *)0));
#line 84
  if ((int )*file == 47) {
#line 85
    return (file);
  }
#line 87
  i = snprintf((char * __restrict  )(ret), sizeof(ret), (char const   * __restrict  )"%s/%s",
               pw->pw_dir, file);
#line 88
  if (i < 0) {
#line 89
    printf((char const   * __restrict  )"expand_authorized_keys: path too long%s",
           "");
#line 89
    exit(1);
  } else
#line 88
  if ((size_t )i >= sizeof(ret)) {
#line 89
    printf((char const   * __restrict  )"expand_authorized_keys: path too long%s",
           "");
#line 89
    exit(1);
  }
#line 90
  free((void *)file);
#line 91
  tmp = strdup(ret);
#line 91
  return ((char *)tmp);
}
}
#line 109
extern int ( /* missing proto */  debug)() ;
#line 106
extern int ( /* missing proto */  strlen)() ;
#line 98 "openssh_df_4.c"
int read_keyfile_line(FILE *f , char const   *filename , char *buf , size_t bufsz ,
                      u_long___0 *lineno ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  char *tmp___3 ;

  {
#line 102
  while (1) {
#line 102
    tmp___3 = fgets((char * __restrict  )buf, (int )bufsz, (FILE * __restrict  )f);
#line 102
    if (! ((unsigned long )tmp___3 != (unsigned long )((void *)0))) {
#line 102
      break;
    }
#line 103
    if ((int )*(buf + 0) == 0) {
#line 104
      continue;
    }
#line 105
    (*lineno) ++;
#line 106
    tmp___1 = strlen(buf);
#line 106
    if ((int )*(buf + (tmp___1 - 1)) == 10) {
#line 107
      return (0);
    } else {
#line 106
      tmp___2 = feof(f);
#line 106
      if (tmp___2) {
#line 107
        return (0);
      } else {
#line 109
        debug("%s: %s line %lu exceeds size limit", "read_keyfile_line", filename,
              *lineno);
#line 112
        while (1) {
#line 112
          tmp = fgetc(f);
#line 112
          if (tmp != 10) {
#line 112
            tmp___0 = feof(f);
#line 112
            if (tmp___0) {
#line 112
              break;
            }
          } else {
#line 112
            break;
          }
        }
      }
    }
  }
#line 116
  return (-1);
}
}
#line 120 "openssh_df_4.c"
char *authorized_keys_file(struct passwd *pw ) 
{ 
  char *tmp ;

  {
#line 123
  tmp = expand_authorized_keys("filename", pw);
#line 123
  return (tmp);
}
}
#line 139
extern int ( /* missing proto */  temporarily_use_uid)() ;
#line 142
extern int ( /* missing proto */  auth_openkeyfile)() ;
#line 146
extern int ( /* missing proto */  restore_uid)() ;
#line 151
extern int ( /* missing proto */  key_new)() ;
#line 165
extern int ( /* missing proto */  debug2)() ;
#line 176
extern int ( /* missing proto */  key_read)() ;
#line 187
extern int ( /* missing proto */  key_fingerprint)() ;
#line 188
extern int ( /* missing proto */  verbose)() ;
#line 188
extern int ( /* missing proto */  key_type)() ;
#line 182
extern int ( /* missing proto */  key_equal)() ;
#line 182
extern int ( /* missing proto */  auth_parse_options)() ;
#line 196
extern int ( /* missing proto */  key_free)() ;
#line 128 "openssh_df_4.c"
static int user_key_allowed2(struct passwd *pw , Key *key , char *file ) 
{ 
  char line[16384] ;
  int found_key ;
  FILE *f ;
  u_long___0 linenum ;
  Key *found ;
  char *fp ;
  int tmp ;
  int tmp___0 ;
  char *cp ;
  char *key_options ;
  int quoted ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
#line 132
  found_key = 0;
#line 134
  linenum = (u_long___0 )0;
#line 139
  temporarily_use_uid(pw);
#line 141
  debug("trying public key file %s", file);
#line 142
  tmp = auth_openkeyfile(file, pw, 0);
#line 142
  f = (FILE *)tmp;
#line 144
  if (! f) {
#line 145
    free((void *)file);
#line 146
    restore_uid();
#line 147
    return (0);
  }
#line 150
  found_key = 0;
#line 151
  tmp___0 = key_new(key->type);
#line 151
  found = (Key *)tmp___0;
#line 153
  while (1) {
#line 153
    tmp___7 = read_keyfile_line(f, (char const   *)file, line, sizeof(line), & linenum);
#line 153
    if (! (tmp___7 != -1)) {
#line 153
      break;
    }
#line 154
    key_options = (char *)((void *)0);
#line 157
    cp = line;
#line 157
    while (1) {
#line 157
      if (! ((int )*cp == 32)) {
#line 157
        if (! ((int )*cp == 9)) {
#line 157
          break;
        }
      }
#line 157
      cp ++;
    }
#line 159
    if (! *cp) {
#line 160
      continue;
    } else
#line 159
    if ((int )*cp == 10) {
#line 160
      continue;
    } else
#line 159
    if ((int )*cp == 35) {
#line 160
      continue;
    }
#line 162
    tmp___2 = key_read(found, & cp);
#line 162
    if (tmp___2 != 1) {
#line 164
      quoted = 0;
#line 165
      debug2("user_key_allowed: check options: \'%s\'", cp);
#line 166
      key_options = cp;
#line 167
      while (1) {
#line 167
        if (*cp) {
#line 167
          if (! quoted) {
#line 167
            if ((int )*cp != 32) {
#line 167
              if (! ((int )*cp != 9)) {
#line 167
                break;
              }
            } else {
#line 167
              break;
            }
          }
        } else {
#line 167
          break;
        }
#line 168
        if ((int )*cp == 92) {
#line 168
          if ((int )*(cp + 1) == 34) {
#line 169
            cp ++;
          } else {
#line 168
            goto _L;
          }
        } else
        _L: /* CIL Label */ 
#line 170
        if ((int )*cp == 34) {
#line 171
          quoted = ! quoted;
        }
#line 167
        cp ++;
      }
#line 174
      while (1) {
#line 174
        if (! ((int )*cp == 32)) {
#line 174
          if (! ((int )*cp == 9)) {
#line 174
            break;
          }
        }
#line 174
        cp ++;
      }
#line 176
      tmp___1 = key_read(found, & cp);
#line 176
      if (tmp___1 != 1) {
#line 177
        debug2("user_key_allowed: advance: \'%s\'", cp);
#line 179
        continue;
      }
    }
#line 182
    tmp___5 = key_equal(found, key);
#line 182
    if (tmp___5) {
#line 182
      tmp___6 = auth_parse_options(pw, key_options, file, linenum);
#line 182
      if (tmp___6 == 1) {
#line 184
        found_key = 1;
#line 185
        debug("matching key found: file %s, line %lu", file, linenum);
#line 187
        tmp___3 = key_fingerprint(found, 1, 1);
#line 187
        fp = (char *)tmp___3;
#line 188
        tmp___4 = key_type(found);
#line 188
        verbose("Found matching %s key: %s", tmp___4, fp);
#line 190
        free((void *)fp);
#line 191
        break;
      }
    }
  }
#line 194
  restore_uid();
#line 195
  fclose(f);
#line 196
  key_free(found);
#line 197
  if (! found_key) {
#line 198
    debug2("key not found");
  }
#line 199
  return (found_key);
}
}
#line 216
extern int ( /* missing proto */  authorized_keys_file2)() ;
#line 203 "openssh_df_4.c"
int user_key_allowed(struct passwd *pw , Key *key ) 
{ 
  int success ;
  char *file ;
  int tmp ;

  {
#line 209
  file = authorized_keys_file(pw);
#line 210
  success = user_key_allowed2(pw, key, file);
#line 211
  free((void *)file);
#line 212
  if (success) {
#line 213
    return (success);
  }
#line 216
  tmp = authorized_keys_file2(pw);
#line 216
  file = (char *)tmp;
#line 217
  success = user_key_allowed2(pw, key, file);
#line 218
  free((void *)file);
#line 219
  return (success);
}
}
#line 222 "openssh_df_4.c"
int main(void) 
{ 
  struct passwd pw ;
  Key key ;

  {
#line 226
  user_key_allowed(& pw, & key);
#line 227
  return (0);
}
}
