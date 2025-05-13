/**
 * @author: Mitul Tyagi
 * @description: Arrays in C
 */
/*
- Array in C is one of the most used data structures in C programming. It is a
simple and fast way of storing multiple values under a single name. An array in
C is a fixed-size collection of similar data items stored in contiguous memory
locations. It can be used to store the collection of primitive data types such
as int, char, float, etc., and also derived and user-defined data types such
as pointers, structures, etc.
- An array can be declared by specifying its name, the type of its elements, and
the size of its dimensions. The compiler allocates the memory block of the
specified size to the array name.
                  data_type array_name [size];
- The C arrays are static in nature, i.e., they are allocated memory at the
compile time.
- When the array is declared or allocated memory, the elements of the array
contain some garbage value. So, the array is to be initialized to some
meaningful value.There are multiple ways to initialize an array in C.
- Array Initialization with Declaration: An initializer list is used to
initialize elements of the array. An initializer list is the list of values
enclosed within braces {} separated by comma
            data_type array_name [size] = {val1, val2, val3, ....., valN};
- Array Initialization with Declaration without Size: The size of the array
can be skipped when initializing using the initializer list. The compiler
automatically deduces the size.
            data_type array_name [] = {val1, val2, val3, ....., valN};
- Array Initialization after Declaration (Using Loops): The initialization
is done after the declaration by assigning the initial value to each element
individually. Loops can be used.
- Any array element can be accessed in C using the array subscript operator []
and the index value i of the element. array_name[index];
- The indexing in the array always starts with 0, i.e., the first element is at
index 0 and the last element is at N – 1 where N is the number of elements in
the array.
- Any array element can be updated at the given index i using the array
subscript operator [] and assignment operator =.
            array_name[index] = new_value;
- An array can be traversed using the loops and the subscript operator using the
correct index values.
- In C, the words, i.e., a sequence of characters are stored in the form of an
array of characters terminated by a NULL character. These are called strings in
C language.
- There are two types of arrays based on the number of dimensions it has. They
are as follows:
- One Dimensional Array: The One-dimensional arrays, also known as 1-D
arrays in C are those arrays that have only one dimension.
- Multidimensional Array: Multi-dimensional Arrays in C are those arrays
that have more than one dimension. Some of the popular multidimensional arrays
are 2D arrays and 3D arrays.
- A Two-Dimensional array or 2D array in C is an array that has exactly two
dimensions. They can be visualized in the form of rows and columns organized in
a two-dimensional plane.
            array_name[size1][size2]
- A 3D array has exactly three dimensions. It can be visualized as a collection
of 2D arrays stacked on top of each other to create the third dimension.
            array_name[size1][size2][size3];
- An array is always passed as pointers to a function in C. Whenever an arrray
is passed to a function, it decays to the pointer and then passed as a pointer
to the first element of an array.
- To return an array from a function, a pointer to the first element of that
array is used.
- Properties of Arrays in C:
    1. Fixed Size: The array in C is a fixed-size collection of elements. The
       size of the array must be known at the compile time and it cannot be
       changed once it is declared.
    2. Homogeneous Collection: Only one type of element is stored in an array.
       There is no restriction on the number of elements but the type of all of
       these elements must be the same.
    3. Indexing in Array: The array index always starts with 0 in C language.
       It means that the index of the first element of the array will be 0 and
       the last element will be N – 1.
    4. Dimensions of an Array: A dimension of an array is the number of indexes
       required to refer to an element in the array. It is the number of
       directions in which you can grow the array size.
    5. Contiguous Storage: All the elements in the array are stored continuously
       one after another in the memory. It is one of the defining properties of
       the array in C which is also the reason why random access is possible in
       the array.
    6. Random Access: The array in C provides random access to its element i.e
       an access to a random element can be made at any index of the array in
       constant time complexity just by using its index number.
    7. No Index Out of Bounds Checking: There is no index out-of-bounds checking
       in C/C++.
- Advantages of Array in C
    - Random and fast access of elements using the array index.
    - Use of fewer lines of code as it creates a single array of multiple
      elements.
    - Traversal through the array becomes easy using a single loop.
    - Sorting becomes easy as it can be accomplished by writing fewer lines of
      code.
- Disadvantages of Array in C
    - Allows a fixed number of elements to be entered which is decided at the
      time of declaration. Unlike a linked list, an array in C is not dynamic.
    - Insertion and deletion of elements can be costly since the elements are
      needed to be rearranged after insertion and deletion.
*/
#include <stdint.h>
#include <stdio.h>
int *func()
{
    static int arr[5] = {1, 2, 3, 4, 5};

    return arr;
}
void printArray(int arr[])
{
    printf("Size of Array in Functions: %lu\n", sizeof(arr));
    printf("Array Elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    int arr_int[5];
    char arr_char[5];
    // array initialization using initialier list
    int arr[5] = {10, 20, 30, 40, 50};

    // array initialization using initializer list without
    // specifying size
    int arr1[] = {1, 2, 3, 4, 5};

    // array initialization using for loop
    float arr2[5];
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = (float)i * 2.1;
    }
    // accessing element at index 2 i.e 3rd element
    printf("Element at arr[2]: %d\n", arr[2]);

    // accessing element at index 4 i.e last element
    printf("Element at arr[4]: %d\n", arr[4]);

    // accessing element at index 0 i.e first element
    printf("Element at arr[0]: %d\n", arr[0]);

    // modifying element at index 2
    arr[2] = 100;

    // traversing array using for loop
    printf("Elements in Array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    // creating array of character
    char str[6] = {'G', 'e', 'e', 'k', 's', '\0'};

    // printing string
    printf("\nCharacter Array: \n");
    int i = 0;
    while (str[i])
    {
        printf("%c", str[i++]);
    }

    printf("\nSize of Array in main(): %lu\n", sizeof(arr));
    printArray(arr);

    int *ptr = func();

    printf("\nArray Elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *ptr++);
    }
    // declaring and initializing 2d array
    int arr2d[2][3] = {10, 20, 30, 40, 50, 60};

    printf("\n2D Array:\n");
    // printing 2d array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
    printf("\n3D Array:\n");
    // 3D array declaration
    int arr3d[2][2][2] = {10, 20, 30, 40, 50, 60, 70, 80};

    // printing elements
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("%d ", arr3d[i][j][k]);
            }
            printf("\n");
        }
        printf("\n \n");
    }

    return 0;
}
/*
Element at arr[2]: 30
Element at arr[4]: 50
Element at arr[0]: 10
Elements in Array: 10 20 100 40 50
Character Array:
Geeks
Size of Array in main(): 20
Size of Array in Functions: 8
Array Elements: 10 20 100 40 50
Array Elements: 1 2 3 4 5
2D Array:
10 20 30
40 50 60

3D Array:
10 20
30 40


50 60
70 80


*/
