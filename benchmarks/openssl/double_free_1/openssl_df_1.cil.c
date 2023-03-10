/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 15 "openssl_df_1.c"
struct stack_st {
   int num ;
   void const   **data ;
   int sorted ;
   int num_alloc ;
};
#line 22 "openssl_df_1.c"
typedef struct stack_st OPENSSL_STACK;
#line 24 "openssl_df_1.c"
struct __anonstruct_CONF_VALUE_27 {
   char *section ;
   char *name ;
   char *value ;
};
#line 24 "openssl_df_1.c"
typedef struct __anonstruct_CONF_VALUE_27 CONF_VALUE;
#line 112
struct stack_st_CONF_VALUE;
#line 112
struct stack_st_CONF_VALUE;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 60 "openssl_df_1.c"
OPENSSL_STACK *OPENSSL_sk_new_null(void) 
{ 
  void *tmp ;

  {
#line 62
  tmp = malloc(sizeof(OPENSSL_STACK ));
#line 62
  return ((OPENSSL_STACK *)tmp);
}
}
#line 69
int OPENSSL_sk_insert(OPENSSL_STACK *st , void const   *data , int loc ) ;
#line 65 "openssl_df_1.c"
int OPENSSL_sk_push(OPENSSL_STACK *st , void const   *data ) 
{ 
  int tmp ;

  {
#line 67
  if ((unsigned long )st == (unsigned long )((void *)0)) {
#line 68
    return (-1);
  }
#line 69
  tmp = OPENSSL_sk_insert(st, data, st->num);
#line 69
  return (tmp);
}
}
#line 77
extern int ( /* missing proto */  sk_reserve)() ;
#line 83
extern int ( /* missing proto */  memmove)() ;
#line 72 "openssl_df_1.c"
int OPENSSL_sk_insert(OPENSSL_STACK *st , void const   *data , int loc ) 
{ 
  int tmp ;

  {
#line 74
  if ((unsigned long )st == (unsigned long )((void *)0)) {
#line 75
    return (0);
  } else
#line 74
  if (st->num == 255) {
#line 75
    return (0);
  }
#line 77
  tmp = sk_reserve(st, 1, 0);
#line 77
  if (! tmp) {
#line 78
    return (0);
  }
#line 80
  if (loc >= st->num) {
#line 81
    *(st->data + st->num) = data;
  } else
#line 80
  if (loc < 0) {
#line 81
    *(st->data + st->num) = data;
  } else {
#line 83
    memmove(st->data + (loc + 1), st->data + loc, sizeof(*(st->data + 0)) * (unsigned long )(st->num - loc));
#line 85
    *(st->data + loc) = data;
  }
#line 87
  (st->num) ++;
#line 88
  st->sorted = 0;
#line 89
  return (st->num);
}
}
#line 101
void OPENSSL_sk_free(OPENSSL_STACK *st ) ;
#line 92 "openssl_df_1.c"
void OPENSSL_sk_pop_free(OPENSSL_STACK *st , void (*func)(void * ) ) 
{ 
  int i ;

  {
#line 96
  if ((unsigned long )st == (unsigned long )((void *)0)) {
#line 97
    return;
  }
#line 98
  i = 0;
#line 98
  while (i < st->num) {
#line 99
    if ((unsigned long )*(st->data + i) != (unsigned long )((void *)0)) {
#line 100
      (*func)((void *)((char *)*(st->data + i)));
    }
#line 98
    i ++;
  }
#line 101
  OPENSSL_sk_free(st);
#line 102
  return;
}
}
#line 104 "openssl_df_1.c"
void OPENSSL_sk_free(OPENSSL_STACK *st ) 
{ 


  {
#line 106
  if ((unsigned long )st == (unsigned long )((void *)0)) {
#line 107
    return;
  }
#line 108
  free((void *)st->data);
#line 109
  free((void *)st);
#line 110
  return;
}
}
#line 112 "openssl_df_1.c"
static struct stack_st_CONF_VALUE *sk_CONF_VALUE_new_null(void) 
{ 
  OPENSSL_STACK *tmp ;

  {
#line 112
  tmp = OPENSSL_sk_new_null();
#line 112
  return ((struct stack_st_CONF_VALUE *)tmp);
}
}
#line 112 "openssl_df_1.c"
static void sk_CONF_VALUE_free(struct stack_st_CONF_VALUE *sk ) 
{ 


  {
#line 112
  OPENSSL_sk_free((OPENSSL_STACK *)sk);
#line 112
  return;
}
}
#line 112 "openssl_df_1.c"
static int sk_CONF_VALUE_push(struct stack_st_CONF_VALUE *sk , CONF_VALUE *ptr ) 
{ 
  int tmp ;

  {
#line 112
  tmp = OPENSSL_sk_push((OPENSSL_STACK *)sk, (void const   *)ptr);
#line 112
  return (tmp);
}
}
#line 112 "openssl_df_1.c"
static void sk_CONF_VALUE_pop_free(struct stack_st_CONF_VALUE *sk , void (*freefunc)(CONF_VALUE *a ) ) 
{ 


  {
#line 112
  OPENSSL_sk_pop_free((OPENSSL_STACK *)sk, (void (*)(void * ))freefunc);
#line 112
  return;
}
}
#line 114 "openssl_df_1.c"
void X509V3_conf_free(CONF_VALUE *conf ) 
{ 


  {
#line 116
  if (! conf) {
#line 117
    return;
  }
#line 118
  free((void *)conf->name);
#line 119
  free((void *)conf->value);
#line 120
  free((void *)conf->section);
#line 121
  free((void *)conf);
#line 122
  return;
}
}
#line 134
extern int ( /* missing proto */  OPENSSL_strdup)() ;
#line 127 "openssl_df_1.c"
int X509V3_add_value(char const   *name , char const   *value , struct stack_st_CONF_VALUE **extlist ) 
{ 
  CONF_VALUE *vtmp ;
  char *tname ;
  char *tvalue ;
  int sk_allocated ;
  int tmp ;
  int tmp___0 ;
  void *tmp___1 ;
  struct stack_st_CONF_VALUE *tmp___2 ;
  int tmp___3 ;

  {
#line 130
  vtmp = (CONF_VALUE *)((void *)0);
#line 131
  tname = (char *)((void *)0);
#line 131
  tvalue = (char *)((void *)0);
#line 132
  sk_allocated = (unsigned long )*extlist == (unsigned long )((void *)0);
#line 134
  if (name) {
#line 134
    tmp = OPENSSL_strdup(name);
#line 134
    tname = (char *)tmp;
#line 134
    if ((unsigned long )tname == (unsigned long )((void *)0)) {
#line 135
      goto err;
    }
  }
#line 136
  if (value) {
#line 136
    tmp___0 = OPENSSL_strdup(value);
#line 136
    tvalue = (char *)tmp___0;
#line 136
    if ((unsigned long )tvalue == (unsigned long )((void *)0)) {
#line 137
      goto err;
    }
  }
#line 138
  tmp___1 = malloc(sizeof(*vtmp));
#line 138
  vtmp = (CONF_VALUE *)tmp___1;
#line 138
  if ((unsigned long )vtmp == (unsigned long )((void *)0)) {
#line 139
    goto err;
  }
#line 140
  if (sk_allocated) {
#line 140
    tmp___2 = sk_CONF_VALUE_new_null();
#line 140
    *extlist = tmp___2;
#line 140
    if ((unsigned long )tmp___2 == (unsigned long )((void *)0)) {
#line 141
      goto err;
    }
  }
#line 142
  vtmp->section = (char *)((void *)0);
#line 143
  vtmp->name = tname;
#line 144
  vtmp->value = tvalue;
#line 145
  tmp___3 = sk_CONF_VALUE_push(*extlist, vtmp);
#line 145
  if (! tmp___3) {
#line 146
    goto err;
  }
#line 147
  return (1);
  err: 
#line 149
  if (sk_allocated) {
#line 150
    sk_CONF_VALUE_free(*extlist);
  }
#line 152
  free((void *)vtmp);
#line 153
  free((void *)tname);
#line 154
  free((void *)tvalue);
#line 155
  return (0);
}
}
#line 181
extern int ( /* missing proto */  strip_spaces)() ;
#line 158 "openssl_df_1.c"
struct stack_st_CONF_VALUE *X509V3_parse_list(char const   *line ) 
{ 
  char *p ;
  char *q ;
  char c ;
  char *ntmp ;
  char *vtmp ;
  struct stack_st_CONF_VALUE *values ;
  char *linebuf ;
  int state ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {
#line 162
  values = (struct stack_st_CONF_VALUE *)((void *)0);
#line 166
  tmp = OPENSSL_strdup(line);
#line 166
  linebuf = (char *)tmp;
#line 167
  if ((unsigned long )linebuf == (unsigned long )((void *)0)) {
#line 168
    goto err;
  }
#line 170
  state = 1;
#line 171
  ntmp = (char *)((void *)0);
#line 173
  p = linebuf;
#line 173
  q = linebuf;
#line 173
  while (1) {
#line 173
    c = *p;
#line 173
    if (c) {
#line 173
      if ((int )c != 13) {
#line 173
        if (! ((int )c != 10)) {
#line 173
          break;
        }
      } else {
#line 173
        break;
      }
    } else {
#line 173
      break;
    }
#line 176
    switch (state) {
    case 1: 
#line 178
    if ((int )c == 58) {
#line 179
      state = 2;
#line 180
      *p = (char)0;
#line 181
      tmp___0 = strip_spaces(q);
#line 181
      ntmp = (char *)tmp___0;
#line 182
      if (! ntmp) {
#line 183
        goto err;
      }
#line 185
      q = p + 1;
    } else
#line 186
    if ((int )c == 44) {
#line 187
      *p = (char)0;
#line 188
      tmp___1 = strip_spaces(q);
#line 188
      ntmp = (char *)tmp___1;
#line 189
      q = p + 1;
#line 190
      if (! ntmp) {
#line 191
        goto err;
      }
#line 193
      X509V3_add_value((char const   *)ntmp, (char const   *)((void *)0), & values);
    }
#line 195
    break;
    case 2: 
#line 198
    if ((int )c == 44) {
#line 199
      state = 1;
#line 200
      *p = (char)0;
#line 201
      tmp___2 = strip_spaces(q);
#line 201
      vtmp = (char *)tmp___2;
#line 202
      if (! vtmp) {
#line 203
        goto err;
      }
#line 205
      X509V3_add_value((char const   *)ntmp, (char const   *)vtmp, & values);
#line 206
      ntmp = (char *)((void *)0);
#line 207
      q = p + 1;
    }
    }
#line 173
    p ++;
  }
#line 213
  if (state == 2) {
#line 214
    tmp___3 = strip_spaces(q);
#line 214
    vtmp = (char *)tmp___3;
#line 215
    if (! vtmp) {
#line 216
      goto err;
    }
#line 218
    X509V3_add_value((char const   *)ntmp, (char const   *)vtmp, & values);
  } else {
#line 220
    tmp___4 = strip_spaces(q);
#line 220
    ntmp = (char *)tmp___4;
#line 221
    if (! ntmp) {
#line 222
      goto err;
    }
#line 224
    X509V3_add_value((char const   *)ntmp, (char const   *)((void *)0), & values);
  }
#line 226
  free((void *)linebuf);
#line 227
  return (values);
  err: 
#line 230
  free((void *)linebuf);
#line 231
  sk_CONF_VALUE_pop_free(values, & X509V3_conf_free);
#line 232
  return ((struct stack_st_CONF_VALUE *)((void *)0));
}
}
#line 236 "openssl_df_1.c"
int main(int argc , char **argv ) 
{ 
  struct stack_st_CONF_VALUE *values ;

  {
#line 238
  values = (struct stack_st_CONF_VALUE *)((void *)0);
#line 239
  values = X509V3_parse_list((char const   *)*(argv + 0));
#line 240
  if ((unsigned long )values != (unsigned long )((void *)0)) {
#line 241
    sk_CONF_VALUE_pop_free(values, & X509V3_conf_free);
  }
#line 242
  return (0);
}
}
