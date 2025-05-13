/**
 * @author: Mitul Tyagi
 * @description: Callback Functions
 */
/*
- A callback function is a function that is passed to another function as an
argument. There are two types of callback functions: Synchronous which are
executed immediately and Asychronous which are exeuted later.
- These are commonly used in event-driven systems.
- In C, these are implemented using function pointers.
*/
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
float cb_sqaure(int num) { return num * num; }
float cb_cube(int num) { return num * num * num; }

float cb_sqaure_root(int num) { return sqrt(num); }

typedef float (*op_t)(int);
// float calc(int num, float (*op)(int))
float calc(int num, op_t op) { return op(num); }
int compare(const void *p1, const void *p2)
{
    int i1 = *(int *)p1;
    int i2 = *(int *)p2;
    return (i1 < i2) ? -1 : ((i1 > i2) ? 1 : 0);
}
int main(int argc, char const *argv[])
{
    printf("square:\t%.2f\n", calc(5, cb_sqaure));
    printf("cube:\t%.2f\n", calc(5, &cb_cube));
    printf("square_root:\t%.2f\n", calc(5, cb_sqaure_root));
    int arr[5] = {4, 5, 7, 0, -1};
    printf("Initial Array\n");
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);
    printf("Sorted Array\n");
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}
