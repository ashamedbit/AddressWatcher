/*
	buggy parent : 141e470
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../openssl.h"

extern const BIGNUM _bignum_ffdhe2048_p;
extern const BIGNUM _bignum_ffdhe3072_p;
extern const BIGNUM _bignum_ffdhe4096_p;
extern const BIGNUM _bignum_ffdhe6144_p;
extern const BIGNUM _bignum_ffdhe8192_p;
extern const BIGNUM _bignum_const_2;

int BN_cmp(const BIGNUM *a, const BIGNUM *b)
{
    int i;
    int gt, lt;
    BN_ULONG t1, t2;

    if ((a == NULL) || (b == NULL)) {
        if (a != NULL)
            return (-1);
        else if (b != NULL)
            return 1;
        else
            return (0);
    }

    if (a->neg != b->neg) {
        if (a->neg)
            return (-1);
        else
            return 1;
    }
    if (a->neg == 0) {
        gt = 1;
        lt = -1;
    } else {
        gt = -1;
        lt = 1;
    }

    if (a->top > b->top)
        return (gt);
    if (a->top < b->top)
        return (lt);
    for (i = a->top - 1; i >= 0; i--) {
        t1 = a->d[i];
        t2 = b->d[i];
        if (t1 > t2)
            return (gt);
        if (t1 < t2)
            return (lt);
    }
    return (0);
}

int BN_rshift1(BIGNUM *r, const BIGNUM *a)
{
    BN_ULONG *ap, *rp, t, c;
    int i, j;

    i = 2;
    ap = a->d;
    j = 2;
    if (a != r) {
        r->neg = a->neg;
    }
    rp = r->d;
    t = 2;
    c = (t & 1) ? BN_TBIT : 0;
    r->top = j;


    if (!r->top)
        r->neg = 0; /* don't allow negative zero */
    return 1;
}

int DH_get_nid(const DH *dh)
{
    int nid;

    if (dh->q != NULL) {
        BIGNUM *q = malloc(sizeof(BIGNUM));	/* allocation site */

        /* Check q = p * 2 + 1 we already know q is odd, so just shift right */
        if (q == NULL || !BN_rshift1(q, q) || !BN_cmp(dh->q, q)) {
            free(q);
            return NID_undef;
        }
    }
    return nid;	/* memory leak */
}

int main()
{
	DH dh;
    dh.q = malloc(sizeof(BIGNUM));
	DH_get_nid(&dh);
	return 0;
}
