/**
 * @author: Mitul Tyagi
 * @description: Heaps
 */
/**
- Heap is a special tree-based data structure that satisfies the heap property.
The heap property states that the key of the parent node is either always
greater than or always less than the keys of its child nodes. Based on this
property, heaps are classified into two types:
    - Max Heap: In a max heap, the key of the parent node is always greater than
      the keys of its child nodes.
    - Min Heap: In a min heap, the key of the parent node is always less than
      the keys of its child nodes.
- Heaps are used to implement priority queues, which are data structures that
store elements along with their priorities. The elements are stored in the heap
based on their priority, and the element with the highest/lowest priority can be
accessed and removed from the heap.
- Heaps are also used in algorithms such as heap sort, which is an efficient
sorting algorithm that uses the heap data structure to sort elements in
ascending or descending order.
- Heaps are implemented using arrays, where the parent-child relationships are
maintained using the indices of the array elements. The root node is stored at
index 0, and the child nodes of a parent node at index i are stored at indices
2i+1 and 2i+2.
- The heap data structure supports the following operations:
    - Insert: Inserts a new element into the heap.
    - Delete: Deletes an element from the heap.
    - Extract-Min/Max: Removes and returns the element with the minimum/maximum
      key from the heap.
    - Heapify: Converts an array of elements into a heap.
    - Build-Heap: Builds a heap from an array of elements.
- The time complexity of the heap operations is as follows:
    - Insert: O(log n)
    - Delete: O(log n)
    - Extract Min/Max: O(log n)
    - Heapify: O(n)
    - Build-Heap: O(n)
- Heaps are used in various applications such as priority queues, graph
algorithms, and sorting algorithms.
- Heap using linked list is not efficient as compared to heap using arrays.
- Heap using trees is not efficient as compared to heap using arrays.
- If heap size is n, then the last non-leaf node is at index [n/2] - 1 and the
range of leaf nodes is from [n/2] to (n - 1). The range of non-leaf nodes is
from 0 to [n/2] - 1.
- If the left child or right child is at index i then the parent is at index
int((i-1)/2) for the 0th indexed array.
- Heap Sort is an in-place sorting algorithm that uses a binary heap data
structure to sort elements in ascending or descending order. The heap sort
algorithm consists of two main steps:
- Build Heap: Convert the input array into a binary heap data structure.
- Heapify: Repeatedly extract the root element of the heap and heapify the
remaining elements to maintain the heap property.
- The time complexity of the heap sort algorithm is O(n*logn), where n is the
number of elements in the input array. The space complexity of the heap sort
algorithm is O(1), as it is an in-place sorting algorithm.
- Heap sort is a comparison-based sorting algorithm that is efficient for large
datasets and is not stable. It is used in various applications such as operating
systems, network routing algorithms, and database systems.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap
{
    int *array;
    int capacity;
    int size;
} Heap;

Heap *createHeap(int capacity)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap)
    {
        printf("Memory error\n");
        return NULL;
    }
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int *)malloc(heap->capacity * sizeof(int));
    if (!heap->array)
    {
        printf("Memory error\n");
        return NULL;
    }
    return heap;
}

void heapify(Heap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->array[left] > heap->array[largest])
    {
        largest = left;
    }
    if (right < heap->size && heap->array[right] > heap->array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = temp;
        heapify(heap, largest);
    }
}

void insert(Heap *heap, int data)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = data;
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i])
    {
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void delete(Heap *heap, int data)
{
    if (heap->size == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    int i;
    for (i = 0; i < heap->size; i++)
    {
        if (heap->array[i] == data)
        {
            break;
        }
    }
    if (i == heap->size)
    {
        printf("Element not found\n");
        return;
    }
    heap->array[i] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, i);
}
void heapSort(int *array, int size)
{
    Heap *heap = createHeap(size);
    for (int i = 0; i < size; i++)
    {
        insert(heap, array[i]);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        // Deleting the root element and placing it at the end of the array
        array[i] = heap->array[0];
        heap->array[0] = heap->array[heap->size - 1];
        heap->size--;
        heapify(heap, 0);
    }
    free(heap->array);
    free(heap);
}

int main(int argc, char const *argv[])
{
    Heap *heap = createHeap(10);
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 40);
    insert(heap, 50);
    insert(heap, 100);
    insert(heap, 25);
    insert(heap, 45);
    insert(heap, 60);
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
    delete(heap, 40);
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }

    printf("\n\n------Sorting the array---------\n");
    heapSort(heap->array, heap->size);
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");

    free(heap->array);
    free(heap);
    return 0;
}
