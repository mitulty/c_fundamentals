/**
 * @author: Mitul
 * @description: Sorting Algorithms
 */
#include <stdint.h>
#include <stdio.h>

void bubbleSort(int *arr, size_t size)
{
    int flag = 0;
    while (1)
    {
        flag = 0;
        for (int i = 0; i < size - 1; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        size--;
        if (flag == 0)
            break;
    }
}

void selectionSort(int *arr, size_t size)
{

    int min = 0;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + i; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertionSort(int *arr, size_t size)
{
    int index = 0;
    int temp;
    for (int i = 1; i < size; i++)
    {
        index = i - 1;
        while (arr[i] < arr[index] && index >= 0)
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index--;
        }
    }
}
// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = low;

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // swap element at i with element at j
            swap(&array[i], &array[j]);

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i], &array[high]);

    // return the partition point
    return i;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {4, 34, 56, 23, 6, 9, 34, 7};

    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < 8; i++)
    {
        printf(" %d ", *(arr + i));
    }

    printf("\n");
    selectionSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < 8; i++)
    {
        printf(" %d ", *(arr + i));
    }

    printf("\n");
    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < 8; i++)
    {
        printf(" %d ", *(arr + i));
    }
    printf("\n");
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < 8; i++)
    {
        printf(" %d ", *(arr + i));
    }
    printf("\n");

    quickSort(arr, 0, size - 1);
    for (int i = 0; i < 8; i++)
    {
        printf(" %d ", *(arr + i));
    }
    printf("\n");

    return 0;
}
