/**
 * @author: Mitul Tyagi
 * @description: Pointers and References in C
 */
/*
- A pointer is a varaible that contains the address of a variable. It is a group
of cells that can hold an address. A pointer can be used to store the memory
address of other variables, functions, or even other pointers. The use of
pointers allows low-level memory access, dynamic memory allocation, and many
other functionality in C.
- A pointer is defined as a derived data type that can store the address of
other C variables or a memory location. We can access and manipulate the data
stored in that memory location using pointers.
- As the pointers in C store the memory addresses, their size is independent of
the type of data they are pointing to. The size of pointers in C only depends on
the system architecture.
- The declaration of a pointer is done using the dereference operator "*". The
pointers that are not initialized, point to random memory address and are called
wild pointers.
                                datatype *ptr;
- The pointer is initialized with the addressof operator "&" to get the memory
address of a variable and then store it in the pointer variable. The unary
operator & gives the address of an object. It only applies to objects in
memory: variables and array elements. It can not be applied to expressions,
constants, or register variables.
- The unary operator * is the indirection or dereferencing operator; when
applied to a pointer, it accesses the object the pointer points to.
Dereferencing a pointer is the process of accessing the value stored in the
memory address specified in the pointer.
- If p is a pointer to some element of an array, then p++ increments p to point
to the next element, and p+=i increments it to point i elements beyond where it
currently is.
- Pointers and integers are not interchangeable. Zero is the sole exception. The
constant zero may be assigned to a pointer, and a pointer may be compared with
constant zero. The symbolic constant NULL is often used in place of zero.
- %p or %ls can be used as specifiers for the value of a pointer (an address).
- Pointers may be compared under certain circumstances. If p and q point to
members of the same array, then relations like ==, !=, <, >-=, etc., work
properly.
- Pointer arithmetic is constant. All the pointer manipulations automatically
take into account the size of the object pointed to. The valid pointer
operations are assignment of pointers of the same type, adding or subtracting a
pointer and an integer, subtracting or comparing two pointers to members of the
same array, and assigning or comparing to zero. All other pointer arithemtics
are illegal.
- A string literal or a character array is accessed using a character pointer. A
string constant is accessed by a pointer to its first element.
- Pointers and Arrays are closely related to each other. Even an array name is a
pointer to its first element. It is also known as Pointer to an Array. A pointer
to an array can be created using the following syntax:
            datatype array_name[] ={};
            datatype *ptr_val = array_name;
- Any operation that can be achieved by array subscripting can also be done with
pointers. If pa is pointer to an array then (pa+i) is the address of a[i] and
*(pa+i) is the contents of a[i]. The name of an array is a synonym for the
location of the first element. Thus pa = &a[0] is equivalent to pa = a.
- A reference to a[i] can also be written as *(a+i). Also &a[i] and (a+i) are
identical. An array-and-index expression is equivalent to one written as a
pointer and offset. A pointer is a variable, so pa = a and pa++ are legal. But
an array name is not a variable; constructions like a = pa and a++ are illegal.
- When an array name is passed to a function, what is passed is the location of
the initial element. Within the called function, this argument is a local
variable, and so an array name parameter is a pointer, that is, a variable
containing an address. As formal parameters in a function definition, char s[]
and char *s are equivalent. When an array name is passed to a function, the
function can at its convenience believe that it has been handed either an array
or a pointer, and manipulate it accordingly. It is possible to pass part of an
array to a function, by passing a pointer to the beginning of the subarray.
- Since pointers are variables themselves, they can be stored in arrays just as
other variables can. Most frequent use of arrays of pointers is to store
character strings of diverse lengths.
- If a two dimensional array is to be passed to a function, the parameter
declaration in the function must include the number of columns; the number of
rows is not relevant, since what is passed is a pointer to an array of rows.
Only the first dimension of an array is free; all others have to be specified in
case  of multidimensional arrays.
- The pointer pointing to the structure type is called struture pointer or
pointer to structure.
             struct struct_name *ptr_name.
- In C language, a pointer can be defined that stores the memory address of
another pointer. Such pointers are called double-pointers or
pointers-to-pointer. Instead of pointing to a data value, they point to another
pointer.

 datatype** ptr_name;
 *ptr_name;      // get the address stored in the inner level pointer
 **pointer_name; // get the value pointed by inner level pointer
- The Null Pointers are those pointers that do not point to any memory location.
They can be created by assigning a NULL value to the pointer. A pointer of any
type can be assigned the NULL value.
                        data_type *pointer_name = NULL;
                                or
                        pointer_name = NULL
- The Void pointers in C are the pointers of type void. It means that they do
not have any associated data type. They are also called generic pointers as they
can point to any type and can be typecasted to any type.
                        void * pointer_name;
- In constant pointers, the memory address stored inside the pointer is constant
and cannot be modified once it is defined. It will always point to the same
memory address.
                        data_type * const pointer_name;
- The pointers pointing to a constant value that cannot be modified are called
pointers to a constant. Here the data can be only accessed pointed by the
pointer, but cannot modify it. Although, the address stored in the pointer to
a constant can be changed. const data_type * pointer_name;
- Far pointer: A far pointer is typically 32-bit that can access memory outside
the current segment.
- Dangling pointer: A pointer pointing to a memory location that has been
deleted (or freed) is called a dangling pointer.
- Huge pointer: A huge pointer is 32-bit long containing segment address and
offset address.
- Complex pointer: Pointers with multiple levels of indirection.
- Near pointer: Near pointer is used to store 16-bit addresses means within the
current segment on a 16-bit machine.
- Normalized pointer: It is a 32-bit pointer, which has as much of its value in
the segment register as possible.
- File Pointer: The pointer to a FILE data type is called a stream pointer or a
file pointer.
- The size of the pointers in C is equal for every pointer type. The size of the
pointer does not depend on the type it is pointing to. It only depends on the
operating system and CPU architecture. The size of pointers in C is 8 bytes
for a 64-bit System and 4 bytes for a 32-bit System. The reason for the same
size is that the pointers store the memory addresses, no matter what type they
are. As the space required to store the addresses of the different memory
locations is the same, the memory required by one pointer type will be equal to
the memory required by other pointer types.
- Pointer arguments enable a function to access and change objects in the
function that called it.
- The call by reference method of passing arguments to a function copies the
address of an argument into the formal parameter. Inside the function, the
address is used to access the actual argument used in the call. It means the
changes made to the parameter affect the passed argument.
- The address operator returns a pointer to the type of the operand.
- Function pointers are a pointer that points to a memory region which has
codes. They point to instructions.
- An array name is always a pointer to the first element of the array. For int
arr[4], arr is a pointer to the first integer. This is equivalent to &arr[0].
But &arr is a pointer to an array of 4 intergers. For matrix[4][6], matrix is a
pointer to an array of 6 integers. This is equivalent to &matrix[0]. But &matrix
is a pointer to an array of 24 integers. Also matrix[3] is a pointer to the
first integer of the 4th array whereas &matrix[3] is a pointer to an array of 6
integers pointing to the 4th array.
- The * operator takes into the inner level in the chain while & operator takes
into the outer level. The golden rule is
          -> a[i]  = *(a + i)
          -> &a[i] = (a + i)
          -> a[i][j][k] = *(*(*(a + i) + j) + k)
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// dummy structure
struct str
{
};

// dummy function
void func(int a, int b) {}
// Poitner Arithmetic
int strlen_func(char *s) // call by reference
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s; // P and S denote to the same object
}
void f(int arr[]) // equivalent to int* arr
{
    printf("Array elment: %d\n", *arr);
}
void geeks()
{
    int var = 10;

    // declare pointer variable
    int *ptr;

    // note that data type of ptr and var must be same
    ptr = &var;

    // assign the address of a variable to a pointer
    printf("Value at ptr = %p \n", ptr);
    printf("Value at var = %d \n", var);
    printf("Value at *ptr = %d \n", *ptr);
}
int *change_var(int *val)
{
    *val = 121;
    static int t = 786;
    return &t;
}
void strcpy_array(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
void strcpy_pointer(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}
char *month_name(int n)
{
    static char *name[] = {"Illegal Month", "January", "February", "March",
                           "April", " May", "June", " July",
                           "August", "September", "October", "November",
                           "December"};
    return ((n < 1) || (n > 12)) ? name[0] : name[n];
}

int **malloc2dIntArray(int row, int col)
{
    int **malloced2darray = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        malloced2darray[i] = (int *)malloc(col * sizeof(int));
    }
    return malloced2darray;
}

int main(int argc, char const *argv[])
{
    geeks();
    int a = 10;
    char c = 'G';
    struct str xstruct;

    // pointer definitions of different types
    int *ptr_int = &a;
    char *ptr_char = &c;
    struct str *ptr_str = &xstruct;
    void (*ptr_func)(int, int) = &func; // Pointer to a function
    void *ptr_vn = NULL;

    // printing sizes
    printf("Size of Integer Pointer  \t:\t%lu bytes\n", sizeof(ptr_int));
    printf("Size of Character Pointer\t:\t%lu bytes\n", sizeof(ptr_char));
    printf("Size of Structure Pointer\t:\t%lu bytes\n", sizeof(ptr_str));
    printf("Size of Function Pointer\t:\t%lu bytes\n", sizeof(ptr_func));
    printf("Size of NULL Void Pointer\t:\t%lu bytes\n", sizeof(ptr_vn));

    int x = 1, y = 2, z[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    float zf[10] = {4.8, 3.67, 24.5};
    int *ip;        // ip is a pointer to int
    ip = &x;        // ip now points to x
    y = *ip;        // y is now 1
    *ip = 0;        // x is now 0
    *ip = *ip + 10; // incremenets x by 10
    ip = &z[0];     // ip now points to z[0]. Here &z[0] gives a pointer to the
                    // first element of the z array.
    // ip = &zf[0];    // ip now points to zf[0], warning: assignment to ‘int *’
    // from incompatible pointer type ‘float *’
    ip = (int *)&zf[0]; // ip now points to zf[0]
    printf("Element Value as integer: %d\n", *ip);
    printf("Element Value as float: %d\n", *ip);

    ip = change_var(&x); // makes x =121
    printf("New Value of x: %d\n", x);
    printf("New Value pointed by ip: %d\n", *ip); // ip = 786
    int *pa = z;
    printf("Pointer Value and Array Name Value: %p,%p\n", pa, z);
    printf("Value at pointer and Value at array name: %d,%d\n", *pa, *z);
    printf("Address of the 4th element using pointer: %p\n", pa + 3);
    printf("Value of the 4th element using pointer: %d\n", *(pa + 3));
    printf("Address of the 4th element using array name: %p\n", z + 3);
    printf("Value of the 4th element using array name: %d\n", *(z + 3));
    f(&z[0]);
    f(z);
    f(&z[2]); // Subarray passed
    f(z + 2); // same as above

    char amessage[] = "Pointers and Array Characters in C"; /* an array */
    char *pmessage = "Pointers and Array Characters in C";  /* a pointer */
    char *month = month_name(12);
    printf("12th Month is: %s\n", month);
    printf("Length is: %d\n", strlen_func(month));

    {
        int arr[5] = {10, 11, 12, 13, 14};
        int brr[5] = {50, 60, 70, 80, 80};
        int *p = arr;  // Name of an array is a pointer to the first element of
                       // the array.
        int *q = &arr; // warning: initialization of ‘int *’ from incompatible
                       // pointer type ‘int (*)[5]’
        int *r = (int *)&arr;
        int *s = (int *)(&arr + 1);
        printf("arr[0]:%d, *p:%d, *q:%d, *r:%d, *s:%d\n", arr[0], *p, *q, *r,
               *s); // warning: initialization of ‘int *’ from incompatible
                    // pointer type ‘int (*)[5]’
        printf("&arr[0]:%p, p:%p, q:%p, r:%p, s:%p\n", &arr[0], p, q, r,
               s); // warning: initialization of ‘int *’ from incompatible
                   // pointer type ‘int (*)[5]’
        *arr = 100;
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
        printf("arr:%p and p:%p\n", arr, p); // Array name holds the address of
                                             // the first element of the array.
        // arr++; // error: lvalue required as increment operand
        // arr = brr; // error: assignment to expression with array type
    }

    {
        char *s = "Hello World!!!";
        printf("strlen(s):%lu\n", strlen(s));
        char *t = "Hello world!!!";
        // char *uv = &s; // warning: initialization of ‘char *’ from
        // incompatible pointer type ‘char **’
        char **uv = &s;
        char *uvwx = s;
        printf("(s==t):%d and (uvwx==s):%d\n", s == t, uvwx == s);
        printf("**uv= %s\n", *uv);
        s = "No World!!!";
        printf("s:%s\n", s);
        printf("*c:%c\n", *s);
        printf("s:%s, &s:%p, *s:%c\n", s, s, *s);
        char u[] = {'H', 'i', '\0'};
        printf("strlen(u):%lu\n", strlen(u));
        // char *p = &u;     // warning: initialization of ‘char *’ from
        // incompatible pointer type ‘char (*)[3]’ char **pp = &u; // warning:
        // initialization of ‘char *’ from incompatible pointer type ‘char
        // (*)[3]’
        char *p = u;
        char (*r)[3] =
            &u; // Here r is pointer to a character array of 3 elements.
        char *q = u;
        printf("u:%s and r:%s\n", u,
               *r); //  warning: format ‘%s’ expects argument of type ‘char *’,
                    //  but argument 3 has type ‘char (*)[3]’
        char v[] = "Bye Bye World!!!";
        printf("s:%s, &s:%p, *s:%c\n", v, v, *v);
        // v = "Woo World!!!"; // error: assignment to expression with array
        // type
        printf("Differenvce: sizeof(&v[0]):%lu, sizeof(v):%lu, sizeof(&v):%lu, "
               "sizeof(s):%lu\n",
               sizeof(&v[0]), sizeof(v), sizeof(&v), sizeof(s));
        printf("Differenvce: sizeof(&r[0]):%lu, sizeof(r):%lu, sizeof(&r):%lu, "
               "sizeof(u):%lu\n",
               sizeof(&r[0]), sizeof(r), sizeof(&r), sizeof(u));
        printf("&v:%p, &v+1:%p\n", &v, &v + 1);
        printf("r:%p, r+1:%p\n", r, r + 1);
        printf("*r[0]:%c and r:%s\n", *r[0], r);
        char *c = {'a', 'b'}; // warning: initialization of ‘char *’ from ‘int’
                              // makes pointer from integer without a cast
        char carr[] = {'a', 'b'};
        char *c_ptr = carr;
    }
    {
        int x = 10;
        char ch = 'A';
        char *c = (char *)&x; // warning: initialization of ‘char *’ from
                              // incompatible pointer type ‘int *’
        char *d;
        int *p, *q;
        q = &x;
        p = q;         // Assigning a pointer to another pointer of same type.
        d = (char *)p; // warning: initialization of ‘char *’ from incompatible
                       // pointer type ‘int *’
        int *e = (int *)&ch;
        int *f;
        f = (int *)c;
        char *g = (char *)&x;
        char *h = (char *)q;
        printf("&x:%p, p:%p, q:%p\n", &x, p, q);
        printf("x:%d, *p:%d, *q:%d\n", x, *p, *q);
    }
    {
        int arr[2][2] = {{1, 2}, {3, 4}};
        int (*r)[2];
        r = arr;
        int **s = arr; // warning: initialization of ‘int **’ from incompatible
                       // pointer type ‘int (*)[2]’
        int **t =
            (int **)arr; // This is not a correct statement. t is a pointer to
                         // pointer which is a pointer to an int.
        printf("arr:%p, arr+1:%p, r:%p, r+1:%p, s:%p, s+1:%p\n", arr, arr + 1,
               r, r + 1, s, s + 1);
        printf("arr[1][1]:%d, r[1][1]:%d\n", arr[1][1],
               r[1][1]); // Accessing t[1][1] results in segementation fault.
        // printf("**t=%d\n", **t); // This results in segmentation fault.
        printf("t=%p, t+1=%p, *t=%d and arr=%p\n", t, t + 1, *t, arr);
    }
    {
        int arr[5] = {1, 2, 3, 4, 5};
        int *x = &arr; // warning: initialization of ‘int *’ from incompatible
                       // pointer type ‘int (*)[5]’
        int (*y)[5] = &arr;
        int **z = &arr; // warning: initialization of ‘int **’ from incompatible
                        // pointer type ‘int (*)[2]’
        printf("y:%p, y+1=%p\n", y, y + 1);
        printf("*y:%p, *y+1=%p\n", *y, *y + 1);
        printf("arr[3] with x:%d and arr[3] with y:%d\n", *(x + 3), *(*y + 3));
        // printf("arr[3] with z:%d", (**z + 3)); // Segmentation fault (core
        // dumped)
    }
    {
        // Array of Pointers to a character
        // to store a list of strings.
        char *names[] = {"amiit", "amaar", "ankit",
                         "akhil"}; // Name is an array of character pointers and
                                   // not a pointer to a character array.
        char (*new_name)[6] = names[0];
        // char(*new_name)[6] = {"amiit", "amaar", "ankit", "akhil"}; //
        // New_Name is pointer to an array of character. initialization of ‘char
        // (*)[]’ from incompatible pointer type ‘char *’
        char **c_array = {"amit", "amar", "ankit", "akhil"};
        int i = 0;
        printf(
            "sizeof(names):%lu, sizeof(new_name):%lu and sizeof(c_array):%d\n",
            sizeof(names), sizeof(new_name), sizeof(c_array));
        printf("names:%p and names+1:%p\n", names, names + 1);
        printf("new_name:%p and new_name+1:%p\n", new_name, new_name + 1);
        printf("c_array:%p and c_array+1:%p\n", c_array, c_array + 1);
        for (i = 0; i < 4; i++)
        {
            printf("names[i]:%p and names[i]:%s\t ", names[i], names[i]);
            printf("new_name+i=%p and *(new_name+i):%s\t", (new_name + i),
                   *(new_name + i));
            printf("c_array:%s\n", c_array);
        }
        // char *str = strcat(new_name, names[0]);
        // printf("%s\n", str);
    }
    {
        // int *p = (int *)NULL;
        // printf("p:%p and *p:%d", p, *p); // Segmentation Fault
    }
    {
        printf("\n\n");
        int arr[5] = {9};
        for (int i = 0; i < 5; i++)
            printf("%d \t", arr[i]);

        printf("\n");
        printf("    arr = %p\n", arr);
        printf("arr + 1 = %p\n", arr + 1);
        printf("\n    &arr = %p\n", &arr);
        printf("  &arr + 1 = %p\n", &arr + 1);
        printf("\n  &arr[0] = %p\n", &arr[0]);
        printf("&arr[0] + 1 = %p\n", &arr[0] + 1);
        printf("\n");

        int *r =
            &arr; //  warning: initialization of ‘int *’ from incompatible
                  //  pointer type ‘int (*)[5]’ [-Wincompatible-pointer-types]
        int *s = (int *)&arr;
        printf("(r, r + 1) = %p, %p\n", r, r + 1);
        printf("(s, S + 1) = %p, %p\n", s, s + 1);

        int (*t)[5] = &arr;
        printf("(t, t + 1) = %p, %p\n", t, t + 1);
        printf("*t,**t : %p,%d\n", *t, **t);

        int **u =
            &arr; // warning: initialization of ‘int **’ from incompatible
                  // pointer type ‘int (*)[5]’ [-Wincompatible-pointer-types]
        printf("(u, u + 1) = %p, %p\n", u, u + 1);
    }
    {

        int matrix[3][2] = {{4, 5}, {7, 8}, {3, 8}};

        printf("\n\n");

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
        printf("    matrix = %p\n", matrix);
        printf("matrix + 1 = %p\n", matrix + 1);

        printf("\n    &matrix = %p\n", &matrix);
        printf("  &matrix + 1 = %p\n", &matrix + 1);

        printf("\n  &matrix[0] = %p\n", &matrix[0]);
        printf("&matrix[0] + 1 = %p\n", &matrix[0] + 1);

        printf("\n  matrix[0] = %p\n", matrix[0]);
        printf("matrix[0] + 1 = %p\n", matrix[0] + 1);

        printf("\n  &matrix[0][0] = %p\n", &matrix[0][0]);
        printf("&matrix[0][0] + 1 = %p\n", &matrix[0][0] + 1);

        printf("\n*matrix = %p\n", *matrix);
        printf("**matrix = %d\n", **matrix);

        printf("\n&*matrix = %p\n", &*matrix);
        printf("&**matrix = %p\n", &**matrix);

        printf("\n*&matrix = %p\n", *&matrix);
        printf("*&*matrix = %p\n", *&*matrix);
        printf("\n");
    }
    return 0;
}
/*
Value at ptr = 0x7ffebf7db60c
Value at var = 10
Value at *ptr = 10
Size of Integer Pointer  	:	8 bytes
Size of Character Pointer	:	8 bytes
Size of Structure Pointer	:	8 bytes
Size of Function Pointer	:	8 bytes
Size of NULL Void Pointer	:	8 bytes
Element Value as integer: 1083808154
Element Value as float: 1083808154
New Value of x: 121
New Value pointed by ip: 786
Pointer Value and Array Name Value: 0x7ffebf7db780,0x7ffebf7db780
Value at pointer and Value at array name: 1,1
Address of the 4th element using pointer: 0x7ffebf7db78c
Value of the 4th element using pointer: 4
Address of the 4th element using array name: 0x7ffebf7db78c
Value of the 4th element using array name: 4
Array elment: 1
Array elment: 1
Array elment: 3
Array elment: 3
12th Month is: December
Length is: 8
arr[0]:10, *p:10, *q:10, *r:10, *s:0
100 11 12 13 14
arr:0x7ffebf7db740 and p:0x7ffebf7db740
(s==t):0 and (uvwx==s):1
s:No World!!!
*c:N
s:No World!!!, &s:0x55a0e678436d, *s:N
u:Hi and r:Hi
s:Bye Bye World!!!, &s:0x7ffebf7db7e0, *s:B
Differenvce: sizeof(&v[0]):8, sizeof(v):17, sizeof(&v):8, sizeof(s):8
Differenvce: sizeof(&r[0]):8, sizeof(r):8, sizeof(&r):8, sizeof(u):3
&v:0x7ffebf7db7e0, &v+1:0x7ffebf7db7f1
r:0x7ffebf7db7dd, r+1:0x7ffebf7db7e0
*r[0]:H and r:Hi
&x:0x7ffebf7db658, p:0x7ffebf7db658, q:0x7ffebf7db658
x:10, *p:10, *q:10
arr:0x7ffebf7db760, arr+1:0x7ffebf7db768, r:0x7ffebf7db760, r+1:0x7ffebf7db768,
s:0x7ffebf7db760, s+1:0x7ffebf7db768 arr[1][1]:4, r[1][1]:4 arr[3] with x:4 and
arr[3] with y:4 Segmentation fault (core dumped)
*/
