/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mdejagnu-cpu=power9" } */

#include <stddef.h>
#include <altivec.h>

signed char
fetch_data (unsigned int offset, vector signed char *datap)
{
  vector signed char data = *datap;

  return vec_xrx (offset, data);
}

/* { dg-final { scan-assembler "vextubrx" } } */