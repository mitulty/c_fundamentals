/**
 * @author: Mitul Tyagi
 * @description: Arrays and Pointers in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {9};
    printf("Arrays and Pointers in C\n");
    for (int i = 0; i < 5; i++)
        printf("%d \t", arr[i]);
    printf("\n");
    printf("        arr = %p\n", arr);
    printf("    arr + 1 = %p\n", arr + 1);
    printf("\n");
    printf("       &arr = %p\n", &arr);
    printf("   &arr + 1 = %p\n", &arr + 1);
    printf("\n");
    printf("    &arr[0] = %p\n", &arr[0]);
    printf("&arr[0] + 1 = %p\n", &arr[0] + 1);
    printf("\n");

    int *r = &arr; //  warning: initialization of ‘int *’ from incompatible pointer type ‘int (*)[5]’ [-Wincompatible-pointer-types]
    int *s = (int *)&arr;
    printf("(r, r + 1) = %p, %p\n", r, r + 1);
    printf("(s, s + 1) = %p, %p\n", s, s + 1);

    int(*t)[5] = &arr;
    printf("(t, t + 1) = %p, %p\n", t, t + 1);
    printf(" (*t, **t) = %p, %d\n", *t, **t);

    // int **u = &arr; // warning: initialization of ‘int **’ from incompatible pointer type ‘int (*)[5]’ [-Wincompatible-pointer-types]
    int **u = (int **)&arr;
    printf("(u, u + 1) = %p, %p\n", u, u + 1);
    // printf("   (u, *u) = %p, %ls\n", u, *u);

    int matrix[3][2] = {
        {4, 5},
        {7, 8},
        {3, 8}};

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n    &matrix = %p\n", &matrix);
    printf("  &matrix + 1 = %p\n", &matrix + 1);
    printf("\n");

    printf("    matrix = %p\n", matrix);
    printf("matrix + 1 = %p\n", matrix + 1);

    printf("\n  &matrix[0] = %p\n", &matrix[0]);
    printf("&matrix[0] + 1 = %p\n", &matrix[0] + 1);

    printf("\n  matrix[2] = %p\n", matrix[2]);
    printf("matrix[2] + 1 = %p\n", matrix[2] + 1);

    printf("\n  matrix[0] = %p\n", matrix[0]);
    printf("matrix[0] + 1 = %p\n", matrix[0] + 1);

    printf("\n  &matrix[0][0] = %p\n", &matrix[0][0]);
    printf("&matrix[0][0] + 1 = %p\n", &matrix[0][0] + 1);

    printf("\n");

    printf("*matrix = %p\n", *matrix);
    printf("**matrix = %d\n", **matrix);

    printf("&*matrix = %p\n", &*matrix);
    printf("&**matrix = %p\n", &**matrix);

    printf("*&matrix = %p\n", *&matrix);
    printf("*&*matrix = %p\n", *&*matrix);

    return 0;
}
/*Output:
Arrays and Pointers in C
9       0       0       0       0
        arr = 0x7ffed2490e30
    arr + 1 = 0x7ffed2490e34

       &arr = 0x7ffed2490e30
   &arr + 1 = 0x7ffed2490e44

    &arr[0] = 0x7ffed2490e30
&arr[0] + 1 = 0x7ffed2490e34

(r, r + 1) = 0x7ffed2490e30, 0x7ffed2490e34
(s, s + 1) = 0x7ffed2490e30, 0x7ffed2490e34
(t, t + 1) = 0x7ffed2490e30, 0x7ffed2490e44
 (*t, **t) = 0x7ffed2490e30, 9
(u, u + 1) = 0x7ffed2490e30, 0x7ffed2490e38

4 5
7 8
3 8

    &matrix = 0x7ffed2490e50
  &matrix + 1 = 0x7ffed2490e68

    matrix = 0x7ffed2490e50
matrix + 1 = 0x7ffed2490e58

  &matrix[0] = 0x7ffed2490e50
&matrix[0] + 1 = 0x7ffed2490e58

  matrix[3] = 0x7ffed2490e68
matrix[3] + 1 = 0x7ffed2490e6c

  matrix[0] = 0x7ffed2490e50
matrix[0] + 1 = 0x7ffed2490e54

  &matrix[0][0] = 0x7ffed2490e50
&matrix[0][0] + 1 = 0x7ffed2490e54

*matrix = 0x7ffed2490e50
**matrix = 4
&*matrix = 0x7ffed2490e50
&**matrix = 0x7ffed2490e50
*&matrix = 0x7ffed2490e50
*&*matrix = 0x7ffed2490e50
 */