/**
 * @author: Mitul Tyagi
 * @description: Qualifiers, Modifiers and Storage Classes in C
 */
/*
- In C programming, type qualifiers are keywords that can be used to modify the
properties of variables. The following are the type qualifiers in C:
    -> const: The const type qualifier is used to create constant variables.
       The value of a constant variable cannot be changed.
    -> volatile: The volatile type qualifier is used to create variables
       whose values can be changed by external devices or hardware.
    -> restrict: The restrict type qualifier is used to restrict the way
       that a pointer can be used.
    -> _Atomic: The _Atomic type qualifier is used to indicate that a variable
       is atomic. This means that the value of the variable cannot be changed by
       multiple threads at the same time.
- Const: The qualifier const can be applied to the declaration of any variable
to specify that its value will not be changed (which depends upon where const
variables are stored, we may change the value of the const variable by using a
pointer). The result is implementation-defined if an attempt is made to
change a const. In C programming, the const qualifier can be used in different
contexts to provide various behaviors. Here are some different use cases of the
const qualifier in C:
        -> Constant Variables: The value of this variable cannot be modified
           once it is initialized.
        -> Pointer to Constant: We can change the pointer to point to any other
           integer variable, but cannot change the value of the object (entity)
           pointed using pointer ptr.
        -> Constant Pointer to Variable: We can change the value of the object
           pointed by the pointer, but cannot change the pointer to point to
           another variable.
        -> Constant Pointer to Constant: We cannot change the value pointed by
           the pointer as well as we cannot point the pointer to other
           variables.
- Volatile: The volatile type qualifier is used to create variables whose values
can't be changed in the program explicitly but can be changed by any external
device or hardware. It is typically used for variables that can be
accessed by interrupt service routines, hardware, or updated by several threads
and processes. The volatile qualifier informs the compiler that any
reads or writes to the variable should not be optimized away since the
variable's value might change without the program's permission. When a variable
is declared  as volatile, the compiler generates code that ensures that every
access to the variable reads or writes its actual value, rather than
using any cached or optimized value. This guarantees that the program behaves as
expected, even if the variable’s value changes unexpectedly.
- Restrict: Restrict keyword specifies that a particular pointer argument does
not alias any other and the compiler doesn’t need to add any additional checks.
restrict keyword is mainly used in pointer declarations as a type qualifier for
pointers. It doesn’t add any new functionality. It is only a way for the
programmer to inform about an optimization that the compiler can make.
- The restrict keyword is a type qualifier that was introduced in the C99
standard. It is used to tell the compiler that a pointer is the only reference
or access point to the memory it points to, allowing the compiler to make
optimizations based on that information.
- In C, data type modifiers are used to modify the length or size of data that
various data types hold such as int, char, and double as per the requirements.
By using these data type modifiers we can precisely utilize the computer
memory. In C, there are 4 data type modifiers that are used to modify data
types. They are used as prefixed to the basic data types. These are: int, long,
signed and unsigned.
- C Storage Classes are used to describe the features of a variable/function.
These features basically include the scope, visibility, and lifetime which help
us to trace the existence of a particular variable/function during the runtime
of a program. These are: auto, static, extern and register.
- Const variables defined in a function are created in the stack memory
  and are destroyed when the function exits. Const variables defined outside
  a function are created in the data segment and are destroyed when the program
  exits.
*/
#include <stdint.h>
#include <stdio.h>
// declaring the variable which is to be made extern
// an initial value can also be initialized to x
int x;

void autoStorageClass()
{

    printf("\nDemonstrating auto class\n\n");

    // declaring an auto variable (simply
    // writing "int a=32;" works as well)
    auto int a = 32;

    // printing the auto variable 'a'
    printf("Value of the variable 'a'"
           " declared as auto: %d\n",
           a);

    printf("--------------------------------");
}

void registerStorageClass()
{

    printf("\nDemonstrating register class\n\n");

    // declaring a register variable
    register char b = 'G';

    // printing the register variable 'b'
    printf("Value of the variable 'b'"
           " declared as register: %d\n",
           b);

    printf("--------------------------------");
}

void externStorageClass()
{

    printf("\nDemonstrating extern class\n\n");

    // telling the compiler that the variable
    // x is an extern variable and has been
    // defined elsewhere (above the main
    // function)
    extern int x;

    // printing the extern variables 'x'
    printf("Value of the variable 'x'"
           " declared as extern: %d\n",
           x);

    // value of extern variable x modified
    x = 2;

    // printing the modified values of
    // extern variables 'x'
    printf("Modified value of the variable 'x'"
           " declared as extern: %d\n",
           x);

    printf("--------------------------------");
}

void staticStorageClass()
{
    int i = 0;

    printf("\nDemonstrating static class\n\n");

    // using a static variable 'y'
    printf("Declaring 'y' as static inside the loop.\n"
           "But this declaration will occur only"
           " once as 'y' is static.\n"
           "If not, then every time the value of 'y' "
           "will be the declared value 5"
           " as in the case of variable 'p'\n");

    printf("\nLoop started:\n");

    for (i = 1; i < 5; i++)
    {

        // Declaring the static variable 'y'
        static int y = 5;

        // Declare a non-static variable 'p'
        int p = 10;

        // Incrementing the value of y and p by 1
        y++;
        p++;

        // printing value of y at each iteration
        printf("\nThe value of 'y', "
               "declared as static, in %d "
               "iteration is %d\n",
               i, y);

        // printing value of p at each iteration
        printf("The value of non-static variable 'p', "
               "in %d iteration is %d\n",
               i, p);
    }

    printf("\nLoop ended:\n");

    printf("--------------------------------\n");
}

// Note that the purpose of restrict is to
// show only syntax. It doesn't change anything
// in output (or logic). It is just a way for
// programmer to tell compiler about an
// optimization
void use(int *a, int *b, int *restrict c)
{
    *a += *c;

    // Since c is restrict, compiler will
    // not reload value at address c in
    // its assembly code. Therefore generated
    // assembly code is optimized
    *b += *c;
}
int main(int argc, char const *argv[])
{
    {
        const int var = 1000;
        printf("Constant Variable Value: %d\n", var);
        /*
            // Compilation error: assignment of read-only variable
            // 'var'
            var = 200;
        */
        int *ptr = &var; // warning: initialization discards ‘const’ qualifier
                         // from pointer target type [-Wdiscarded-qualifiers]
        *ptr = 10;
        printf("Pointer Value: %d, Constant Variable Value: %d\n", *ptr, var);
    }
    {
        // Pointer to a constant
        int i = 10;
        int j = 20;
        /* ptr is pointer to constant */
        const int *ptr = &i;

        printf("ptr: %d\n", *ptr);
        /* error: object pointed cannot be modified
        using the pointer ptr */
        //*ptr = 100;

        ptr = &j; /* valid */
        printf("ptr: %d\n", *ptr);
    }
    {
        // Pointer to a constant
        int const i = 10;
        int j = 20;

        /* pointer to integer constant. Here i
        is of type "const int", and &i is of
        type "const int *".  And p is of type
        "const int", types are matching no issue */
        int const *ptr = &i;

        printf("ptr: %d\n", *ptr);

        /* error */
        //*ptr = 100;

        /* valid. We call it up qualification. In
        C/C++, the type of "int *" is allowed to up
        qualify to the type "const int *". The type of
        &j is "int *" and is implicitly up qualified by
        the compiler to "const int *" */

        ptr = &j;
        printf("ptr: %d\n", *ptr);
    }
    {
        // Pointer to Constant
        /*
        Down qualification is not allowed in C++ and may cause warnings in C.
        Down qualification refers to the situation where a qualified type is
        assigned to a non-qualified type.
        */
        int i = 10;
        int const j = 20;

        /* ptr is pointing an integer object */
        int *ptr = &i;

        printf("*ptr: %d and j: %d\n", *ptr, j);

        /* The below assignment is invalid in C++, results in
           error/warning In C, the compiler may throw a warning, but
           casting is implicitly allowed */

        ptr = &j; // warning: assignment discards ‘const’ qualifier from pointer target type
        *ptr = 234;

        /* In C++, it is called 'down qualification'. The type
           of expression &j is "const int *" and the type of ptr
           is "int *". The assignment "ptr = &j" causes to
           implicitly remove const-ness from the expression &j.
           C++ being more type restrictive, will not allow
           implicit down qualification. However, C++ allows
           implicit up qualification. The reason being, const
           qualified identifiers are bound to be placed in
           read-only memory (but not always). If C++ allows
           above kind of assignment (ptr = &j), we can use 'ptr'
           to modify value of j which is in read-only memory.
           The consequences are implementation dependent, the
           program may fail at runtime. So strict type checking
           helps clean code.
         */

        printf("*ptr: %d and j: %d\n", *ptr, j);
    }
    {
        // constant pointer to a variable
        int i = 10;
        int j = 20;

        /* constant pointer to integer */
        int *const ptr = &i;

        printf("ptr: %d\n", *ptr);

        *ptr = 100; /* valid */
        printf("ptr: %d\n", *ptr);

        // Cannot change the pointer to point to another variable.
        // ptr = &j; /* error */
    }
    {
        // Constant Pointer to a Constant
        int i = 10;
        int j = 20;

        /* constant pointer to constant integer */
        const int *const ptr = &i;

        printf("ptr: %d\n", *ptr);

        // ptr = &j;   /* error */
        //*ptr = 100; /* error */
    }
    {
        const volatile int local = 10;
        int *ptr = (int *)&local;

        printf("Initial value of local : %d \n", local);

        *ptr = 100;

        printf("Modified value of local: %d \n", local);
    }
    {
        // Restrict
        printf("Using Restrict\n");
        int a = 50, b = 60, c = 70;
        use(&a, &b, &c);
        printf("%d %d %d", a, b, c);
    }
    {
        // To demonstrate auto Storage Class
        autoStorageClass();

        // To demonstrate register Storage Class
        registerStorageClass();

        // To demonstrate extern Storage Class
        externStorageClass();

        // To demonstrate static Storage Class
        staticStorageClass();
    }
    return 0;
}
/*
Constant Variable Value: 1000
Pointer Value: 10, Constant Variable Value: 10
ptr: 10
ptr: 20
ptr: 10
ptr: 20
*ptr: 10 and j: 20
*ptr: 234 and j: 234
ptr: 10
ptr: 100
ptr: 10
Initial value of local : 10
Modified value of local: 100
Using Restrict
120 130 70
Demonstrating auto class

Value of the variable 'a' declared as auto: 32
--------------------------------
Demonstrating register class

Value of the variable 'b' declared as register: 71
--------------------------------
Demonstrating extern class

Value of the variable 'x' declared as extern: 0
Modified value of the variable 'x' declared as extern: 2
--------------------------------
Demonstrating static class

Declaring 'y' as static inside the loop.
But this declaration will occur only once as 'y' is static.
If not, then every time the value of 'y' will be the declared value 5 as in the
case of variable 'p'

Loop started:

The value of 'y', declared as static, in 1 iteration is 6
The value of non-static variable 'p', in 1 iteration is 11

The value of 'y', declared as static, in 2 iteration is 7
The value of non-static variable 'p', in 2 iteration is 11

The value of 'y', declared as static, in 3 iteration is 8
The value of non-static variable 'p', in 3 iteration is 11

The value of 'y', declared as static, in 4 iteration is 9
The value of non-static variable 'p', in 4 iteration is 11

Loop ended:
--------------------------------
*/
