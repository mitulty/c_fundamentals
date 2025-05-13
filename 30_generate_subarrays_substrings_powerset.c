/**
 * @author: Mitul Tyagi
 * @description: Generate Subarrays, Substrings and Powerset
 */

#include <stdio.h>

void printsubarray(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
        printf("%d ", arr[i]);
}
void printsubstring(char *arr, int start, int end)
{
    for (int i = start; i < end; i++)
        printf("%c ", arr[i]);
}
void generatesubarrays(char *arr, int size)
{
    printf("Generating for length: %d", size);
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            printsubarray(arr, i, j);
            printf("\n");
        }
}
void generatesubstrings(char *arr, int size)
{
    printf("Generating for length: %d", size);
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            printsubstring(arr, i, j);
            printf("\n");
        }
}
void powerset(int *arr, int size)
{
    printf("Generating for length: %d\n", size);
    for (int i = 0; i < (1 << size); i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("\ni: %d, j: %d, i & (1 << j): %d\n", i, j, i & (1 << j));
            if (i & (1 << j))
                printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[] = {1, 3, 4, 6, 7, 8, 3, 4};
    generatesubarrays(arr, sizeof(arr) / sizeof(arr[0]));
    char *s = "Hello";
    generatesubstrings(s, strlen(s) + 1);
    int arr1[] = {1, 2, 3};

    powerset(arr1, sizeof(arr1) / sizeof(arr1[0]));

    return 0;
}