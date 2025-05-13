/**
 * @author: Mitul Tyagi
 * @description: Functions in C
 */
/*
- Functions break large computing tasks into smaller ones. A function in C is a
set of statements that when called perform some specific task. It is the basic
building block of a C program that provides modularity and code reusability.
The programming statements of a function are enclosed within { } braces, having
certain meanings and performing certain operations. Functions are also called
subroutines or procedures in other languages.
- Each function definition has the form
                        return-type function-name ( argument declarations )
                        {
                            declarations and statements
                        }
Various parts may be absent.
- If the return-type is omitted, int is assumed. The communication between the
functions is by arguments and values returned by the functions, and through
external variables. The functions can occur in any order in the source file,
and the source program can be split into multiple files. The return statement is
the mechanism for returning a value from the called function to its caller.
Any expression can follow return. The expression will be converted to the return
type of the function. The callig function is free to ignore the returned
value. Furthermore, there need be no expression after return; in that cases, no
value is returned to the caller. Control also returns to the caller with no
value when execution falls of the end of the function by reaching the right
brace. If a function fails to return a value, its value is certain to be
garbage. The type void can be used if no arguments are present in a function and
if no type is returned.
- Only one value can be returned from a C function. To return multiple values,
pointers or structures are used.
- The syntax of function can be divided into 3 aspects:
    -> Function Declaration: In a function declaration, the function name, its
       return type, and the number and type of its parameters are defined. A
       function declaration tells the compiler that there is a function with the
       given name defined somewhere else in the program. The parameter name is
       not mandatory while declaring functions.
    -> Function Definition: It consists of actual statements which are executed
       when the function is called (i.e. when the program control comes to the
       function).
    -> Function Call: It is a statement that instructs the compiler to execute
       the function. The function name and the parameters in the function call.
- There are two type of functions in C:
    -> Library Functions: A library function is also referred to as a “built-in
       function”. A compiler package already exists that contains these
       functions, each of which has a specific meaning and is included in the
       package.
    -> User Defined Functions: Functions that the programmer creates are known
       as User-Defined functions.
- The data passed when the function is being invoked is known as the Actual
parameters. Formal Parameters are the variables and the data types as mentioned
in the function declaration. There are two ways to pass arguments to the C
function: Pass by Value and Pass by Reference
- Pass by Value: Parameter passing in this method copies values from actual
parameters into formal function parameters. As a result, any changes made inside
the functions do not reflect in the caller’s parameters.
- Pass by Reference: The caller’s actual parameters and the function’s actual
parameters refer to the same locations, so any changes made inside the function
are reflected in the caller’s actual parameters.
- Functions may not be defined within other functions but variables can be
defined in a block-structured fashion with in a function. Declaration of
variables (including initializations) may follow the left brace that introduces
any compound statement, not just the  one that begins a function. Variables
declared in this way hide any identically named variables in outer blocks, and
remain in existence until the matching right brace.
- An automatic variable declared and initialized in a block is intialized each
time the block is entered. A static variable is initialized only the first time
the block is entered.
- Automatic variables, including formal parameters, also hide external variables
and functions of the same name.
- C functions may be used recursively; that is, a function may call iteself
either directly or indirectly. When a function calls itself recursively, each
invocation gets a fresh set of all the automatic variabls, independent of the
previous set.
- The scope of a function lasts from the point at which it is declared to the
end of the file being compiled. A static function is visible only in the file in
which it is declared.
- Becasue external variables are globally accessible, they provide an
alternative to function arguments and return values for communicating data
between functions. Any function may access an external variable by referring to
it by name, if the name has been declared somehow. Automatic variables are
internal to a function; they come into existence when the function is entered,
and disappear when it is left. External variables are permanent, so they retain
there values from one function invocation to the next. The function parameters
are local variables.
*/
#include <stdint.h>
#include <stdio.h>

// Pass by Value
int sum(int a, int b) // formal parameters
{
    return a + b;
}
// Pass by Reference
void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}
int main(int argc, char const *argv[])
{
    // Calling sum function and
    // storing its value in add variable
    int add = sum(10, 30); // actual parameters

    printf("Sum is: %d", add);
    int var1 = 3, var2 = 2;
    printf("Before swap Value of var1 and var2 is: %d, %d\n", var1, var2);
    swap(&var1, &var2);
    printf("After swap Value of var1 and var2 is: %d, %d\n", var1, var2);
    int *p1 = &var1, *p2 = &var2;
    swap(p1, p2);
    printf("After swap Value of var1 and var2 is: %d, %d\n", var1, var2);
    return 0;
}
