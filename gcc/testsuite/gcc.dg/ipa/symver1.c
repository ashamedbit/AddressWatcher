/* { dg-do compile } */

__attribute__ ((__symver__ ("foo@VER_2")))
__attribute__ ((__symver__ ("foo@VER_3")))
int foo()
{
  return 2;
}

/* { dg-final { scan-assembler ".symver.*foo, foo@VER_2" } } */
/* { dg-final { scan-assembler ".symver.*foo, foo@VER_3" } } */
