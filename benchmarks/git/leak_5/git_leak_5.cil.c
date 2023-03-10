/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 218 "../git.h"
typedef unsigned long long uintmax_t;
#line 219 "../git.h"
typedef uintmax_t timestamp_t;
#line 255 "../git.h"
struct object_id {
   unsigned char hash[20] ;
};
#line 267 "../git.h"
struct object {
   unsigned int parsed : 1 ;
   unsigned int type : 3 ;
   unsigned int flags : 27 ;
   struct object_id oid ;
};
#line 274 "../git.h"
struct tree {
   struct object object ;
   void *buffer ;
   unsigned long size ;
};
#line 307
struct commit;
#line 307 "../git.h"
struct commit_list {
   struct commit *item ;
   struct commit_list *next ;
};
#line 312 "../git.h"
struct commit {
   struct object object ;
   void *util ;
   unsigned int index ;
   timestamp_t date ;
   struct commit_list *parents ;
   struct tree *tree ;
};
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 468
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 133 "../git.h"
static unsigned int const   all_flags  =    (unsigned int const   )((((1U << 16) | (1U << 17)) | (1U << 18)) | (1U << 19));
#line 161
extern int ( /* missing proto */  memcpy)() ;
#line 161
extern int ( /* missing proto */  st_mult)() ;
#line 158 "../git.h"
__inline static void copy_array(void *dst , void const   *src , size_t n , size_t size ) 
{ 
  int tmp ;

  {
#line 160
  if (n) {
#line 161
    tmp = st_mult(size, n);
#line 161
    memcpy(dst, src, tmp);
  }
#line 162
  return;
}
}
#line 50 "git_leak_5.c"
extern int ( /* missing proto */  parse_commit)() ;
#line 62
extern int ( /* missing proto */  paint_down_to_common)() ;
#line 68
extern int ( /* missing proto */  clear_commit_marks)() ;
#line 71
void free_commit_list(struct commit_list *list ) ;
#line 32 "git_leak_5.c"
static int remove_redundant(struct commit **array , int cnt ) 
{ 
  struct commit **work ;
  unsigned char *redundant ;
  int *filled_index ;
  int i ;
  int j ;
  int filled ;
  void *tmp ;
  void *tmp___0 ;
  int tmp___1 ;
  void *tmp___2 ;
  struct commit_list *common ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
#line 45
  tmp = calloc((size_t )cnt, sizeof(*work));
#line 45
  work = (struct commit **)tmp;
#line 46
  tmp___0 = calloc((size_t )cnt, (size_t )1);
#line 46
  redundant = (unsigned char *)tmp___0;
#line 47
  tmp___1 = st_mult(sizeof(*filled_index), cnt - 1);
#line 47
  tmp___2 = malloc((size_t )tmp___1);
#line 47
  filled_index = (int *)tmp___2;
#line 49
  i = 0;
#line 49
  while (i < cnt) {
#line 50
    parse_commit(*(array + i));
#line 49
    i ++;
  }
#line 51
  i = 0;
#line 51
  while (i < cnt) {
#line 54
    if (*(redundant + i)) {
#line 55
      goto __Cont;
    }
#line 56
    filled = 0;
#line 56
    j = filled;
#line 56
    while (j < cnt) {
#line 57
      if (i == j) {
#line 58
        goto __Cont___0;
      } else
#line 57
      if (*(redundant + j)) {
#line 58
        goto __Cont___0;
      }
#line 59
      *(filled_index + filled) = j;
#line 60
      tmp___3 = filled;
#line 60
      filled ++;
#line 60
      *(work + tmp___3) = *(array + j);
      __Cont___0: /* CIL Label */ 
#line 56
      j ++;
    }
#line 62
    tmp___4 = paint_down_to_common(*(array + i), filled, work);
#line 62
    common = (struct commit_list *)tmp___4;
#line 63
    if ((*(array + i))->object.flags & (1U << 17)) {
#line 64
      *(redundant + i) = (unsigned char)1;
    }
#line 65
    j = 0;
#line 65
    while (j < filled) {
#line 66
      if ((*(work + j))->object.flags & (1U << 16)) {
#line 67
        *(redundant + *(filled_index + j)) = (unsigned char)1;
      }
#line 65
      j ++;
    }
#line 68
    clear_commit_marks(*(array + i), all_flags);
#line 69
    j = 0;
#line 69
    while (j < filled) {
#line 70
      clear_commit_marks(*(work + j), all_flags);
#line 69
      j ++;
    }
#line 71
    free_commit_list(common);
    __Cont: /* CIL Label */ 
#line 51
    i ++;
  }
#line 75
  copy_array((void *)work, (void const   *)array, (size_t )cnt, sizeof(*work) + (sizeof(char [1]) - 1UL));
#line 76
  filled = 0;
#line 76
  i = filled;
#line 76
  while (i < cnt) {
#line 77
    if (! *(redundant + i)) {
#line 78
      tmp___5 = filled;
#line 78
      filled ++;
#line 78
      *(array + tmp___5) = *(work + i);
    }
#line 76
    i ++;
  }
#line 79
  j = filled;
#line 79
  i = 0;
#line 79
  while (i < cnt) {
#line 80
    if (*(redundant + i)) {
#line 81
      tmp___6 = j;
#line 81
      j ++;
#line 81
      *(array + tmp___6) = *(work + i);
    }
#line 79
    i ++;
  }
#line 82
  free((void *)work);
#line 83
  free((void *)redundant);
#line 84
  free((void *)filled_index);
#line 85
  return (filled);
}
}
#line 88 "git_leak_5.c"
struct commit_list *commit_list_insert(struct commit *item , struct commit_list **list_p ) 
{ 
  struct commit_list *new_list ;
  void *tmp ;

  {
#line 90
  tmp = malloc(sizeof(struct commit_list ));
#line 90
  new_list = (struct commit_list *)tmp;
#line 91
  new_list->item = item;
#line 92
  new_list->next = *list_p;
#line 93
  *list_p = new_list;
#line 94
  return (new_list);
}
}
#line 97 "git_leak_5.c"
struct commit *pop_commit(struct commit_list **stack ) 
{ 
  struct commit_list *top ;
  struct commit *item ;
  struct commit *tmp ;

  {
#line 99
  top = *stack;
#line 100
  if (top) {
#line 100
    tmp = top->item;
  } else {
#line 100
    tmp = (struct commit *)((void *)0);
  }
#line 100
  item = tmp;
#line 102
  if (top) {
#line 103
    *stack = top->next;
#line 104
    free((void *)top);
  }
#line 106
  return (item);
}
}
#line 110 "git_leak_5.c"
void free_commit_list(struct commit_list *list ) 
{ 


  {
#line 112
  while (list) {
#line 113
    pop_commit(& list);
  }
#line 114
  return;
}
}
#line 116 "git_leak_5.c"
struct commit_list *reduce_heads(struct commit_list *heads ) 
{ 
  struct commit_list *p ;
  struct commit_list *result ;
  struct commit_list **tail ;
  struct commit **array ;
  int num_head ;
  int i ;
  void *tmp ;
  int tmp___0 ;
  struct commit_list *tmp___1 ;

  {
#line 119
  result = (struct commit_list *)((void *)0);
#line 119
  tail = & result;
#line 123
  if (! heads) {
#line 124
    return ((struct commit_list *)((void *)0));
  }
#line 127
  p = heads;
#line 127
  while (p) {
#line 128
    (p->item)->object.flags &= ~ (1U << 18);
#line 127
    p = p->next;
  }
#line 129
  p = heads;
#line 129
  num_head = 0;
#line 129
  while (p) {
#line 130
    if ((p->item)->object.flags & (1U << 18)) {
#line 131
      goto __Cont;
    }
#line 132
    (p->item)->object.flags |= 1U << 18;
#line 133
    num_head ++;
    __Cont: /* CIL Label */ 
#line 129
    p = p->next;
  }
#line 135
  tmp = calloc((size_t )num_head, sizeof(*array));
#line 135
  array = (struct commit **)tmp;
#line 136
  p = heads;
#line 136
  i = 0;
#line 136
  while (p) {
#line 137
    if ((p->item)->object.flags & (1U << 18)) {
#line 138
      tmp___0 = i;
#line 138
      i ++;
#line 138
      *(array + tmp___0) = p->item;
#line 139
      (p->item)->object.flags &= ~ (1U << 18);
    }
#line 136
    p = p->next;
  }
#line 142
  num_head = remove_redundant(array, num_head);
#line 143
  i = 0;
#line 143
  while (i < num_head) {
#line 144
    tmp___1 = commit_list_insert(*(array + i), tail);
#line 144
    tail = & tmp___1->next;
#line 143
    i ++;
  }
#line 146
  return (result);
}
}
#line 149 "git_leak_5.c"
int main(void) 
{ 
  struct commit_list *list ;
  struct commit_list *reduced_list ;
  int i ;

  {
#line 153
  i = 0;
#line 153
  while (i < 10) {
#line 155
    commit_list_insert((struct commit *)((void *)0), & list);
#line 153
    i ++;
  }
#line 157
  reduced_list = reduce_heads(list);
#line 159
  free_commit_list(list);
#line 160
  return (0);
}
}
