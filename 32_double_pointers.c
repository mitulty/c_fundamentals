/**
 * @author: Mitul Tyagi
 * @description: Use of Double Pointers in C
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    // This is dynamic memory allocation for the matrix
    // int **arr;
    // arr = (int**)malloc(sizeof(int*)*5);

    // The arr is a part of the stack memory
    // arr is an array of 5 integer pointers.
    int *arr[5];
    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = (int *)malloc(sizeof(int) * 4);
        // arr[i] = (int *)malloc(sizeof(int) * 4);
    }
    for (int i = 0; i < 4; i++)
    {
        *(*(arr + 0) + i) = 100 * i + 200;
        // arr[0][i] = 100 * i + 200;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i][j]);
            // printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("         arr = %p\n", arr);
    printf("     arr + 1 = %p\n", arr + 1);
    printf("     arr + 2 = %p\n", arr + 2);
    printf("     arr + 3 = %p\n", arr + 3);
    printf("        *arr = %p\n", *arr);
    printf("  *(arr + 1) = %p\n", *(arr + 1));
    printf("  *(arr + 2) = %p\n", *(arr + 2));
    printf("  *(arr + 3) = %p\n", *(arr + 3));

    printf("*(*(arr)) = %d\n", *(*(arr)));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++)
        {
            // arr[i][j] = i*100 + j;
            *(*(arr + i) + j) = i * 100 + j;
        }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i][j]);
            // printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}