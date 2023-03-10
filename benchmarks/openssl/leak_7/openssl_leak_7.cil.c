/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 76 "../stdio.h"
typedef unsigned long long uint64_t;
#line 14 "openssl_leak_7.c"
struct thread_local_inits_st {
   int async ;
   int err_state ;
};
#line 23 "openssl_leak_7.c"
typedef int CRYPTO_THREAD_LOCAL;
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 483 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 24 "openssl_leak_7.c"
static CRYPTO_THREAD_LOCAL threadstopkey  ;
#line 26 "openssl_leak_7.c"
static void *thread_local_storage[256]  ;
#line 30
int CRYPTO_THREAD_init_local(CRYPTO_THREAD_LOCAL *key , void (*cleanup)(void * ) ) ;
#line 30 "openssl_leak_7.c"
static unsigned int thread_local_key  =    0U;
#line 28 "openssl_leak_7.c"
int CRYPTO_THREAD_init_local(CRYPTO_THREAD_LOCAL *key , void (*cleanup)(void * ) ) 
{ 
  unsigned int tmp ;

  {
#line 32
  if (thread_local_key >= 256U) {
#line 33
    return (0);
  }
#line 35
  tmp = thread_local_key;
#line 35
  thread_local_key ++;
#line 35
  *key = (CRYPTO_THREAD_LOCAL )tmp;
#line 37
  thread_local_storage[*key] = (void *)0;
#line 39
  return (1);
}
}
#line 42 "openssl_leak_7.c"
void *CRYPTO_THREAD_get_local(CRYPTO_THREAD_LOCAL *key ) 
{ 


  {
#line 44
  if (*key >= 256) {
#line 45
    return ((void *)0);
  }
#line 47
  return (thread_local_storage[*key]);
}
}
#line 50 "openssl_leak_7.c"
int CRYPTO_THREAD_set_local(CRYPTO_THREAD_LOCAL *key , void *val ) 
{ 


  {
#line 52
  if (*key >= 256) {
#line 53
    return (0);
  }
#line 55
  thread_local_storage[*key] = val;
#line 57
  return (1);
}
}
#line 66
extern int ( /* missing proto */  OPENSSL_zalloc)() ;
#line 60 "openssl_leak_7.c"
static struct thread_local_inits_st *ossl_init_get_thread_local(int alloc ) 
{ 
  struct thread_local_inits_st *local ;
  void *tmp ;
  int tmp___0 ;

  {
#line 62
  tmp = CRYPTO_THREAD_get_local(& threadstopkey);
#line 62
  local = (struct thread_local_inits_st *)tmp;
#line 65
  if ((unsigned long )local == (unsigned long )((void *)0)) {
#line 65
    if (alloc) {
#line 66
      tmp___0 = OPENSSL_zalloc(sizeof(*local));
#line 66
      local = (struct thread_local_inits_st *)tmp___0;
#line 67
      CRYPTO_THREAD_set_local(& threadstopkey, (void *)local);
    }
  }
#line 69
  if (! alloc) {
#line 70
    CRYPTO_THREAD_set_local(& threadstopkey, (void *)0);
  }
#line 73
  return (local);
}
}
#line 76 "openssl_leak_7.c"
int ossl_init_thread_start(uint64_t opts ) 
{ 
  struct thread_local_inits_st *locals ;
  struct thread_local_inits_st *tmp ;

  {
#line 78
  tmp = ossl_init_get_thread_local(1);
#line 78
  locals = tmp;
#line 80
  if ((unsigned long )locals == (unsigned long )((void *)0)) {
#line 81
    return (0);
  }
#line 83
  if (opts & 1ULL) {
#line 88
    locals->async = 1;
  }
#line 91
  if (opts & 2ULL) {
#line 96
    locals->err_state = 1;
  }
#line 99
  return (1);
}
}
#line 102 "openssl_leak_7.c"
int main(void) 
{ 
  int i ;
  int i___0 ;

  {
#line 104
  i = 0;
#line 104
  while (i < 10) {
#line 106
    CRYPTO_THREAD_init_local(& threadstopkey, (void (*)(void * ))((void *)0));
#line 107
    ossl_init_thread_start((uint64_t )2);
#line 104
    i ++;
  }
#line 109
  i___0 = 0;
#line 109
  while (i___0 < 10) {
#line 110
    printf((char const   * __restrict  )"%d\n", thread_local_storage[i___0]);
#line 111
    free(thread_local_storage[i___0]);
#line 109
    i___0 ++;
  }
#line 113
  return (0);
}
}
