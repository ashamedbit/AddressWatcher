// PR c++/69795
// { dg-do compile { target c++11 } }
// { dg-options "-w" }

int foo ( foo += *[ // { dg-error "expected" }
// { dg-error "-:invalid|expected" "" { target *-*-* } .+1 }
