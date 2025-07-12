/**
 * @author: Mitul Tyagi
 * @description: Function Pointer
 */
/*
- Function pointers are a pointer that points to a memory region which has
code. They point to instructions.
- There are two ways to define a function pointer:
  1. Using typedef: typedef void (*funcptr)(int);
     This defines a datatype funcptr which is function pointer. This type then can
     be used to create different variables and assign those variables the value.
  2. Using direct declaration: void (*func_ptr)();
     This defines a variable func_ptr which is a function pointer.
- Typedef example:
                        typedef void (*funcptr)(int);
                        funcptr pf; // This defines a variable pf of type funcptr
                        pf = &function_4; // Assigning the address of function_4 to pf
                        pf(10);
- Direct declaration example:
                        void (*func_ptr)();
                        func_ptr = function_1;
                        func_ptr();
*/
#include <stdint.h>
#include <stdio.h>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

void execute_math_operation(int, int, int);
static void add(int, int);
static void sub(int, int);
static void mul(int, int);
static void divide(int, int);

typedef void (*operation)(int, int);
operation arithmetic[4] = {add, sub, &mul, &divide};
// This defines a datatype funcptr which is function pointer. This type then can
// be used to create different variables and assign those variables the value.
typedef void (*funcptr)(int);

void function_1() { printf("Functiion_1() Called\n"); }

void function_2() { printf("Functiion_2() Called\n"); }

void function_3(int a) { printf("Functiion_3() Called with a: %d\n", a); }

void function_4(int a) { printf("Functiion_4() Called with a: %d\n", a); }

int main(int argc, char const *argv[])
{
    void (*func_ptr)();
    func_ptr = function_1;
    func_ptr();

    func_ptr = function_2;
    func_ptr();

    void (*func_ptr_arg)(int);
    func_ptr_arg = &function_3;
    func_ptr_arg(3);

    func_ptr_arg = &function_4;
    func_ptr_arg(4);

    funcptr pf;
    pf = &function_4;
    pf(10);
    execute_math_operation(ADD, 12, 4);
    execute_math_operation(SUB, 12, 4);
    execute_math_operation(MUL, 12, 4);
    execute_math_operation(DIV, 12, 4);
    execute_math_operation(DIV, 12, 0);
    return 0;
}
static void add(int a, int b)
{
    printf("Addition of %d and %d: %d\n", a, b, a + b);
}
static void sub(int a, int b)
{
    printf("Subtraction of %d and %d: %d\n", a, b, a - b);
}
static void mul(int a, int b)
{
    printf("Multiplication of %d and %d: %d\n", a, b, a * b);
}
static void divide(int a, int b)
{
    if (b)
        printf("Division of %d and %d: %d\n", a, b, a / b);
    else
        printf("Division by zero. Error!!!\n");
}
void execute_math_operation(int op, int a, int b) { arithmetic[op](a, b); }
