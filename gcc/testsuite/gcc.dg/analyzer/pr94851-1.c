/* { dg-additional-options "-O2" } */

#include <stdio.h>
#include <stdlib.h>

typedef struct AMARK {
  struct AMARK *m_next;
  char m_name;
} AMARK;

struct buf {
  AMARK *b_amark;
};

struct buf *curbp;

int pamark(void) {
  int c;
  AMARK *p = curbp->b_amark;
  AMARK *last = curbp->b_amark;

  c = getchar();

  while (p != (AMARK *)NULL && p->m_name != (char)c) {
    last = p;
    p = p->m_next;
  }

  if (p != (AMARK *)NULL) {
    printf("over writing mark %c\n", c);
  } else {
    if ((p = (AMARK *)malloc(sizeof(AMARK))) == (AMARK *)NULL)
      return 0;

    p->m_next = (AMARK *)NULL;

    if (curbp->b_amark == (AMARK *)NULL)
      curbp->b_amark = p;
    else
      last->m_next = p;
  }

  p->m_name = (char)c; /* { dg-bogus "leak of 'p'" "bogus leak" { xfail *-*-* } } */
  // TODO(xfail): related to PR analyzer/97072 and PR analyzer/97074

  return 1;
}
