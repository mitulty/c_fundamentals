/**
 * @author: Mitul Tyagi
 * @description: Preprocessor Basics
 */
// gcc -DHDR -DVAL=97 -UVAL test.c
// gcc -DHDR -DVAL=97  test.c
// gcc -DHDR -DVAL=65  test.c
// gcc  -DVAL=60  test.c
// gcc -DHDR -DVAL=a -DLET=97 test.c
#if !defined(HDR)
int s = 0;
#else
int s = 1;
#endif

#if defined(HDR)
#define VAL1 97
#else
#define VAL1 65
#endif

#ifndef HDR
int t = 0;
#else
int t = 1;
#endif

#if VAL == 97
int val = 'a';
#else
int val = 'b';
#endif

#if LET == 'a'
int let = 1;
#else
int let = 0;
#endif

#include <stdio.h>
int google(int d);
int main()
{
    register int p = 4, q = 5;
    q = (q > p++) ? p = (5 ? (q = (2, 4)) : p || q) : (p = (3, 5));
    printf("%d %d\n", q, p);
    printf("%d %d %c %d\n", s, t, val, let);
    return 0;
}

int google(int pk) { printf("%d\n", pk += pk << 2 << 1); }
