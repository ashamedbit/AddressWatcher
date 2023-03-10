/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 218 "../git.h"
typedef unsigned long long uintmax_t;
#line 219 "../git.h"
typedef uintmax_t timestamp_t;
#line 241 "../git.h"
struct strbuf {
   size_t alloc ;
   size_t len ;
   char *buf ;
};
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
#line 321 "../git.h"
struct commit_dist {
   struct commit *commit ;
   int distance ;
};
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 468
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 386 "../git.h"
extern char strbuf_slopbuf[] ;
#line 12 "git_leak_2.c"
struct commit *pop_commit(struct commit_list **stack ) 
{ 
  struct commit_list *top ;
  struct commit *item ;
  struct commit *tmp ;

  {
#line 14
  top = *stack;
#line 15
  if (top) {
#line 15
    tmp = top->item;
  } else {
#line 15
    tmp = (struct commit *)((void *)0);
  }
#line 15
  item = tmp;
#line 17
  if (top) {
#line 18
    *stack = top->next;
#line 19
    free((void *)top);
  }
#line 21
  return (item);
}
}
#line 24 "git_leak_2.c"
void free_commit_list(struct commit_list *list ) 
{ 


  {
#line 26
  while (list) {
#line 27
    pop_commit(& list);
  }
#line 28
  return;
}
}
#line 30 "git_leak_2.c"
struct commit_list *commit_list_insert(struct commit *item , struct commit_list **list_p ) 
{ 
  struct commit_list *new_list ;
  void *tmp ;

  {
#line 32
  tmp = malloc(sizeof(struct commit_list ));
#line 32
  new_list = (struct commit_list *)tmp;
#line 33
  new_list->item = item;
#line 34
  new_list->next = *list_p;
#line 35
  *list_p = new_list;
#line 36
  return (new_list);
}
}
#line 51
extern int ( /* missing proto */  weight)() ;
#line 39 "git_leak_2.c"
static struct commit_list *best_bisection(struct commit_list *list , int nr ) 
{ 
  struct commit_list *p ;
  struct commit_list *best ;
  int best_distance ;
  int distance ;
  unsigned int flags ;

  {
#line 42
  best_distance = -1;
#line 44
  best = list;
#line 45
  p = list;
#line 45
  while (p) {
#line 47
    flags = (p->item)->object.flags;
#line 49
    if (flags & (1U << 2)) {
#line 50
      goto __Cont;
    }
#line 51
    distance = weight(p);
#line 52
    if (nr - distance < distance) {
#line 53
      distance = nr - distance;
    }
#line 54
    if (distance > best_distance) {
#line 55
      best = p;
#line 56
      best_distance = distance;
    }
    __Cont: /* CIL Label */ 
#line 45
    p = p->next;
  }
#line 60
  return (best);
}
}
#line 86
extern int ( /* missing proto */  strbuf_reset)() ;
#line 87
extern int ( /* missing proto */  strbuf_addf)() ;
#line 88
extern int ( /* missing proto */  add_name_decoration)() ;
#line 96
extern int ( /* missing proto */  strbuf_release)() ;
#line 63 "git_leak_2.c"
static struct commit_list *best_bisection_sorted(struct commit_list *list , int nr ) 
{ 
  struct commit_list *p ;
  struct commit_dist *array ;
  void *tmp ;
  struct strbuf buf ;
  int cnt ;
  int i ;
  int distance ;
  unsigned int flags ;
  struct object *obj ;

  {
#line 66
  tmp = calloc((size_t )nr, sizeof(*array));
#line 66
  array = (struct commit_dist *)tmp;
#line 67
  buf.alloc = (size_t )0;
#line 67
  buf.len = (size_t )0;
#line 67
  buf.buf = strbuf_slopbuf;
#line 70
  p = list;
#line 70
  cnt = 0;
#line 70
  while (p) {
#line 72
    flags = (p->item)->object.flags;
#line 74
    if (flags & (1U << 2)) {
#line 75
      goto __Cont;
    }
#line 76
    distance = weight(p);
#line 77
    if (nr - distance < distance) {
#line 78
      distance = nr - distance;
    }
#line 79
    (array + cnt)->commit = p->item;
#line 80
    (array + cnt)->distance = distance;
#line 81
    cnt ++;
    __Cont: /* CIL Label */ 
#line 70
    p = p->next;
  }
#line 83
  p = list;
#line 83
  i = 0;
#line 83
  while (i < cnt) {
#line 84
    obj = & ((array + i)->commit)->object;
#line 86
    strbuf_reset(& buf);
#line 87
    strbuf_addf(& buf, "dist=%d", (array + i)->distance);
#line 88
    add_name_decoration(0, buf.buf, obj);
#line 90
    p->item = (array + i)->commit;
#line 91
    if (i < cnt - 1) {
#line 92
      p = p->next;
    }
#line 83
    i ++;
  }
#line 94
  free_commit_list(p->next);
#line 95
  p->next = (struct commit_list *)((void *)0);
#line 96
  strbuf_release(& buf);
#line 97
  free((void *)array);
#line 98
  return (list);
}
}
#line 116
extern int ( /* missing proto */  count_interesting_parents)() ;
#line 119
extern int ( /* missing proto */  weight_set)() ;
#line 121
extern int ( /* missing proto */  show_list)() ;
#line 159
extern int ( /* missing proto */  count_distance)() ;
#line 160
extern int ( /* missing proto */  clear_distance)() ;
#line 163
extern int ( /* missing proto */  halfway)() ;
#line 102 "git_leak_2.c"
static struct commit_list *do_find_bisection(struct commit_list *list , int nr , int *weights ,
                                             int find_all ) 
{ 
  int n ;
  int counted ;
  struct commit_list *p ;
  struct commit *commit ;
  unsigned int flags ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  struct commit_list *q ;
  unsigned int flags___0 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  struct commit_list *tmp___9 ;
  struct commit_list *tmp___10 ;

  {
#line 109
  counted = 0;
#line 111
  n = 0;
#line 111
  p = list;
#line 111
  while (p) {
#line 112
    commit = p->item;
#line 113
    flags = commit->object.flags;
#line 115
    tmp = n;
#line 115
    n ++;
#line 115
    (p->item)->util = (void *)(weights + tmp);
#line 116
    tmp___0 = count_interesting_parents(commit);
#line 116
    switch (tmp___0) {
    case 0: 
#line 118
    if (! (flags & (1U << 2))) {
#line 119
      weight_set(p, 1);
#line 120
      counted ++;
#line 121
      show_list("bisection 2 count one", counted, nr, list);
    }
#line 128
    break;
    case 1: 
#line 130
    weight_set(p, -1);
#line 131
    break;
    default: 
#line 133
    weight_set(p, -2);
#line 134
    break;
    }
#line 111
    p = p->next;
  }
#line 138
  show_list("bisection 2 initialize", counted, nr, list);
#line 154
  p = list;
#line 154
  while (p) {
#line 155
    if ((p->item)->object.flags & (1U << 1)) {
#line 156
      goto __Cont;
    }
#line 157
    tmp___1 = weight(p);
#line 157
    if (tmp___1 != -2) {
#line 158
      goto __Cont;
    }
#line 159
    tmp___2 = count_distance(p);
#line 159
    weight_set(p, tmp___2);
#line 160
    clear_distance(list);
#line 163
    if (! find_all) {
#line 163
      tmp___3 = halfway(p, nr);
#line 163
      if (tmp___3) {
#line 164
        return (p);
      }
    }
#line 165
    counted ++;
    __Cont: /* CIL Label */ 
#line 154
    p = p->next;
  }
#line 168
  show_list("bisection 2 count_distance", counted, nr, list);
#line 170
  while (counted < nr) {
#line 171
    p = list;
#line 171
    while (p) {
#line 173
      flags___0 = (p->item)->object.flags;
#line 175
      tmp___4 = weight(p);
#line 175
      if (0 <= tmp___4) {
#line 176
        goto __Cont___0;
      }
#line 177
      q = (p->item)->parents;
#line 177
      while (q) {
#line 178
        if ((q->item)->object.flags & (1U << 1)) {
#line 179
          goto __Cont___1;
        }
#line 180
        tmp___5 = weight(q);
#line 180
        if (0 <= tmp___5) {
#line 181
          break;
        }
        __Cont___1: /* CIL Label */ 
#line 177
        q = q->next;
      }
#line 183
      if (! q) {
#line 184
        goto __Cont___0;
      }
#line 191
      if (! (flags___0 & (1U << 2))) {
#line 192
        tmp___6 = weight(q);
#line 192
        weight_set(p, tmp___6 + 1);
#line 193
        counted ++;
#line 194
        show_list("bisection 2 count one", counted, nr, list);
      } else {
#line 198
        tmp___7 = weight(q);
#line 198
        weight_set(p, tmp___7);
      }
#line 201
      if (! find_all) {
#line 201
        tmp___8 = halfway(p, nr);
#line 201
        if (tmp___8) {
#line 202
          return (p);
        }
      }
      __Cont___0: /* CIL Label */ 
#line 171
      p = p->next;
    }
  }
#line 206
  show_list("bisection 2 counted all", counted, nr, list);
#line 208
  if (! find_all) {
#line 209
    tmp___9 = best_bisection(list, nr);
#line 209
    return (tmp___9);
  } else {
#line 211
    tmp___10 = best_bisection_sorted(list, nr);
#line 211
    return (tmp___10);
  }
}
}
#line 214 "git_leak_2.c"
void find_bisection(struct commit_list **commit_list , int *reaches , int *all , int find_all ) 
{ 
  int nr ;
  int on_list ;
  struct commit_list *list ;
  struct commit_list *p ;
  struct commit_list *best ;
  struct commit_list *next ;
  struct commit_list *last ;
  int *weights ;
  unsigned int flags ;
  void *tmp ;

  {
#line 221
  show_list("bisection 2 entry", 0, 0, *commit_list);
#line 227
  on_list = 0;
#line 227
  nr = on_list;
#line 227
  last = (struct commit_list *)((void *)0);
#line 227
  p = *commit_list;
#line 227
  while (p) {
#line 230
    flags = (p->item)->object.flags;
#line 232
    next = p->next;
#line 233
    if (flags & (1U << 1)) {
#line 234
      free((void *)p);
#line 235
      goto __Cont;
    }
#line 237
    p->next = last;
#line 238
    last = p;
#line 239
    if (! (flags & (1U << 2))) {
#line 240
      nr ++;
    }
#line 241
    on_list ++;
    __Cont: /* CIL Label */ 
#line 227
    p = next;
  }
#line 243
  list = last;
#line 244
  show_list("bisection 2 sorted", 0, nr, list);
#line 246
  *all = nr;
#line 247
  tmp = calloc((size_t )on_list, sizeof(*weights));
#line 247
  weights = (int *)tmp;
#line 250
  best = do_find_bisection(list, nr, weights, find_all);
#line 251
  if (best) {
#line 252
    if (! find_all) {
#line 253
      best->next = (struct commit_list *)((void *)0);
    }
#line 254
    *reaches = weight(best);
  }
#line 256
  free((void *)weights);
#line 257
  *commit_list = best;
#line 258
  return;
}
}
#line 259 "git_leak_2.c"
int main(void) 
{ 
  struct commit_list *list ;
  int reaches ;
  int all ;
  int find_all ;
  int i ;

  {
#line 263
  i = 0;
#line 263
  while (i < 10) {
#line 265
    commit_list_insert((struct commit *)((void *)0), & list);
#line 263
    i ++;
  }
#line 267
  find_bisection(& list, & reaches, & all, find_all);
#line 268
  free_commit_list(list);
#line 269
  return (0);
}
}
