/**
 * @author: Mitul Tyagi
 * @description: Types, Literals, Objects and Values in C
 */
/*
- The type of an object determines the set of values it can have and what
operations can be performed on it. It indicates the encoding of the data
stored, the number of bytes or bits allocated to this variable and the
limitation of data being stored in this information.
- These can be classified as: Primitive Data Types, User-Defined Data Types and
Derived Data Types.
- Primitive Data Types: These data types are built-in or predefined data types
and can be used directly by the user to declare variables. Example: int, char,
float, double and void.
- Derived Data Types: These are derived from the primitive or built-in datatypes
are referred to as Derived Data Types.vExample: Array, Pointer, Reference and
Function.
- User-Defined Data Types: These are defined by the user itself. Example:
Structure, Union, Enumeration and Typedef.
- The primitive data types in C are:
        -> char: a single byte capable of holding one character in the local
           character set
        -> int: an integer, typically reflecting the natural size of integers on
           the host machine
        -> float: single-precision floating point
        -> double: double-precision floating point
        -> void: used to specify that no value is present. It does not provide a
            result value to its caller. It has no values and no operations. It
            is used to represent nothing. Void is used in multiple ways as
            function return type, function arguments as void, and pointers to
            void. No object has a type void.
- There are a number of qualifiers that can be applied to these basic types.
- Printable characters are always positive.
- The long, short, signed and unsigned are type modifiers that can be used
with some primitive data types to change the size or length of the datatype.
- The qualifiers signed or unsigned may be applied to char or any integer.
- The size of the data types in C is dependent on the size of the architecture,
so the universal size of the data types can not be defined. For that, the C
language provides the sizeof() operator to check the size of the data types.
-----------------------|--------------|-----------------------------------|
Data Type/             |  Size(bytes) |   Range                           |
Format Specifier       |              |                                   |
-----------------------|--------------|-----------------------------------|
signed char/           |  1           |    -128 to 127                    |
%c/%hhi                |              |                                   |
-----------------------|--------------|-----------------------------------|
unsigned char/         |  1           |   0 to 255                        |
%c/%hhu                |              |                                   |
-----------------------|--------------|-----------------------------------|
short int/             |  2           |   -32,768 to 32,767               |
%hd/%hi                |              |                                   |
-----------------------|--------------|-----------------------------------|
unsigned short int/    |  2           |   0 to 65,535                     |
%hu                    |              |                                   |
-----------------------|--------------|-----------------------------------|
unsigned int/          |  4           |   0 to 4,294,967,295              |
%u                     |              |                                   |
-----------------------|--------------|-----------------------------------|
int/signed int/        |  4           |   -2,147,483,648 to 2,147,483,647 |
%d/%i                  |              |                                   |
-----------------------|--------------|-----------------------------------|
long int/              |  4           |   -2,147,483,648 to 2,147,483,647 |
%ld/%li                |              |                                   |
-----------------------|--------------|-----------------------------------|
unsigned long int/     |  4           |   0 to 4,294,967,295              |
%lu                    |              |                                   |
-----------------------|--------------|-----------------------------------|
long long int/         |  8           |   -(2^63) to (2^63)-1             |
%lld/%lli              |              |                                   |
-----------------------|--------------|-----------------------------------|
unsigned long long int/|  8           |   0 to 18,446,744,073,709,551,615 |
%llu                   |              |                                   |
-----------------------|--------------|-----------------------------------|
float                  |  4           |   1.2E-38 to 3.4E+38	          |
%f/%F                  |              |                                   |
-----------------------|--------------|-----------------------------------|
double                 |  8           |   1.7E-308 to 1.7E+308	          |
%lf/%lF                |              |                                   |
-----------------------|--------------|-----------------------------------|
long double            |  16          |   3.4E-4932 to 1.1E+4932	      |
%Lf/%LF                |              |                                   |
-----------------------|--------------|-----------------------------------|
- Literals are tokens that denotes a fixed value, which may be an integar, a
floating-point number, a character, or a string. It's type is determined by its
value and its notation.
- A character literal is an integer literal, written as one character within
single quotes. It's value is the numeric value of the character in the machine's
character set. Certain characters can be represented in character and string
literals by escape sequences. An arbitrary byte-sized bit pattern can be
specified by '\ooo' where "ooo" is one to three octal digits(0....7) or by
'\xhh' where "hh" is one or more hexadecimal digits(0...9,a...f,A...F).
- The character literal '\0' represents the character with value zero, the null
character.
- An integer literal is of type int. A long literal is written with a terminal
"l". Unsigned literals are written with a terminal "u" or "U", and the suffix
"ul" or "UL" indicates unsigned long.
- The value of an integer literals can be specified in octal or hexadecimal
instead of decimal. A leading 0(zero) on an integer literals means octal, a
leading 0x or 0X means hexadecimal. They may also be followed by "L" and "U".
- Floating-point constants contain a decimal point or an exponent. Their type is
double, unless suffixed with "f" or "F" for float and "l" or "L" for long
double.
- A constant expression involves only constants and can be evaluated during the
compilation rather than run-time.
- A string literal or string constant is a sequence of zero or more characters
enclosed by double quotes. They can be concatenated at compile time. The
internal representation of a string has a null character '\0' at the end.
- The enumeration constant is a list of integer literals. The first name has a
value 0, the next 1, and so on, unless explicit values are specified. If not all
values are specified, unspecified values continue the progression from the last
specified value. Names in different enumerations must be distinct. Values need
not be distinct in the same enumeration.
- An enumeration is a better alternative compared to #define.
- An object is a data recognized by a name which has an address in memory.
- An “l-value” refers to memory location which identifies an object. l-value may
appear as either left hand or right hand side of an assignment operator(=).
l-value often represents an identifier. Expressions referring to modifiable
locations are called “modifiable l-values“. A modifiable l-value cannot have an
array type, an incomplete type, or a type with the const attribute. For
structures and unions to be modifiable lvalues, they must not have any members
with the const attribute. The name of the identifier denotes a storage location,
while the value of the variable is the value stored at that location. An
identifier is a modifiable lvalue if it refers to a memory location and if its
type is arithmetic, structure, union or pointer. For example, if ptr is a
pointer to a storage region, then *ptr is a modifiable l-value that designates
the storage region to which ptr points. In C, the concept was renamed as
“locator value”, and referred to expressions that locate (designate) objects.
The l-value is one of the following:
              --> The name of the variable of any type i.e. , an identifier of
                  integral, floating, pointer, structure, or union type.
              --> A subscript ([ ]) expression that does not evaluate to an
                  array.
              --> A unary-indirection (*) expression that does not refer to an
                  array
              --> An l-value expression in parentheses.
              --> A const object (a nonmodifiable l-value).
              --> The result of indirection through a pointer, provided that it
                  isn’t a function pointer.
              --> The result of member access through pointer(-> or .)
- An "r-value" simply means, an object that has no identifiable location in
memory (i.e. having an address). "r-value" refers to data value that is stored
at some address in memory. An r-value is an expression, that can’t have a value
assigned to it, which means the r-value can appear on right but not on left hand
side of an assignment operator(=).
- The unary & (address-of) operator requires an l-value as its operand. That is,
&n is a valid expression only if n is an l-value. Thus, an expression such as
&12 is an error. Again, 12 does not refer to an object, so it’s not
addressable. All l-values are r-values but not all r-values are l-values.
- Structures are l-values.
- An array is not an lvalue, except when it is the operand of the sizeof
operator, the _Alignof operator, or the unary & operator, or is a string literal
used to initialize an array. An expression that has type "array of type" is
converted to an expression with type "pointer to type" that points to the
initial element of the array object and is not an lvalue.
      int x[10];
      int i = 0;
      x = &i; //error occurs!
      char name1[10];
      char name2[10];
      name1 = name2; //Gives compilation error
*/
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size_of_char = sizeof(char);
    int size_of_int = sizeof(int);
    int size_of_short = sizeof(short);
    int size_of_long_int = sizeof(long);
    int size_of_long_long_int = sizeof(long long);
    int size_of_float = sizeof(float);
    int size_of_double = sizeof(double);
    int size_of_long_double = sizeof(long double);

    printf("The size of char data type : %d\n", size_of_char);
    printf("The size of int data type : %d\n", size_of_int);
    printf("The size of short int data type : %d\n", size_of_short);
    printf("The size of long int data type : %d\n", size_of_long_int);
    printf("The size of long long int data type : %d\n", size_of_long_long_int);
    printf("The size of float data type : %d\n", size_of_float);
    printf("The size of double data type : %d\n", size_of_double);
    printf("The size of long double data type : %d\n", size_of_long_double);
    float myFloatNum = 1333.5;

    printf("%f\n", myFloatNum);   // Default will show 6 digits after the decimal point
    printf("%.1f\n", myFloatNum); // Only show 1 digit after the decimal
    printf("%.2f\n", myFloatNum); // Only show 2 digits after the decimal
    printf("%.4f\n", myFloatNum); // Only show 4 digits after the decimal

    // Integer value with positive data.
    int aint = 9;

    // integer value with negative data.
    int bint = -9;

    // U or u is Used for Unsigned int in C.
    int cint = 89U;

    // L or l is used for long int in C.
    long int dint = 99998L;

    unsigned long int eint = -99998UL;

    printf("Integer value with positive data: %d\n", aint);
    printf("Integer value with negative data: %d\n", bint);
    printf("Integer value with an unsigned int data: %u\n", cint);
    printf("Integer value with a  long int data: %ld\n", dint);
    printf("Integer value with an unsigned long int data: %lu\n", eint);

    char a_char = 'a';
    char c_char;

    printf("Value of a_char: %c\n", a_char);

    a_char++;
    printf("Value of a_char after increment is: %c\n", a_char);

    // c is assigned ASCII values
    // which corresponds to the
    // character 'c'
    // a-->97 b-->98 c-->99
    // here c will be printed
    c_char = 99;

    printf("Value of c_char: %c\n", c_char);

    float afloat = 9.0f;
    float bfloat = 2.5f;

    // 2x10^-4
    float cfloat = 2E-4f;
    printf("Float: %f\n", afloat);
    printf("Float: %f\n", bfloat);
    printf("Float: %f\n", cfloat);

    double a = 123123.00;
    double b = 12.293123;
    double c = 21324454560043469987.23426223545;

    printf("Double: %lf\n", a);

    printf("Double: %lf\n", b);

    printf("Double: %lf\n", c);

    long double ald = 21324454560043469987.23426223545L;
    printf("Long Double: %Lf\n", ald);

    int val = 30;
    void *ptr = &val;
    printf("%d\n", *(int *)ptr);
    printf("Integer Literals: %d ,%ld and %lu\n", 534, 34L, -34UL);
    printf("Float Literals: %f ,%lf and %Lf\n", 5.435475785f, 4556.65845646,
           123544.787945l);
    printf("Character Literal: %c,%hhi and %hhu\n", 'a', 'a', 'a');
    printf("Character Literal: %c,%hhi and %hhu\n", 128, 128, 128);
    printf("String Literal: %s and %s\n", "Hello!!", "a");
    enum days
    {
        Mon = 0,
        Tue,
        Wed = 10,
        Thurs = 0,
        Fri,
        Sat = 5,
        Sun
    };

    printf("Enum Literals: Mon- %d, Tues-%d, Wed-%d, Thurs-%d, Fri-%d, Sat-%d "
           "and Sun-%d\n",
           Mon, Tue, Wed, Thurs, Fri, Sat, Sun);
    return 0;
}
/*
The size of char data type : 1
The size of int data type : 4
The size of short int data type : 2
The size of long int data type : 8
The size of long long int data type : 8
The size of float data type : 4
The size of double data type : 8
The size of long double data type : 16
1333.500000
1333.5
1333.50
1333.5000
Integer value with positive data: 9
Integer value with negative data: -9
Integer value with an unsigned int data: 89
Integer value with a  long int data: 99998
Integer value with an unsigned long int data: 18446744073709451618
Value of a_char: a
Value of a_char after increment is: b
Value of c_char: c
Float: 9.000000
Float: 2.500000
Float: 0.000200
Double: 123123.000000
Double: 12.293123
Double: 21324454560043470848.000000
Long Double: 21324454560043469988.000000
30
Integer Literals: 534 ,34 and 18446744073709551582
Float Literals: 5.435476 ,4556.658456 and 123544.787945
Character Literal: a,97 and 97
Character Literal: �,-128 and 128
String Literal: Hello!! and a
Enum Literals: Mon- 0, Tues-1, Wed-10, Thurs-0, Fri-1, Sat-5 and Sun-6
*/
