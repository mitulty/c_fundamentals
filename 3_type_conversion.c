/*
  @Author: Mitul Tyagi
  @Date:   2023-10-26 22:46:32
  @Description: Type Conversion
  @Last Modified time: 2024-07-12 19:30:52
*/
/*
- Type conversion in C is the process of converting one data type to another. The type conversion is only performed to those data types where conversion is 
  possible. Type conversion is performed by a compiler. In type conversion, the destination data type can’t be smaller than the source data type. Type 
  conversion is done at compile time and it is also called widening conversion because the destination data type can’t be smaller than the source data type.
  There are two types of Conversion: Implicit and Explicit.
- When an operator has operands of different types, they are converted to a common type. In general, the only automatic conversions are those that convert a 
  "narrower" operand into a "woder" one without losing the information, such as converting an integer to floating point.
- Expressions that might lose information may draw a warning but they are not illegal.
- A char is just a small integer, so chars may be freely used in arithmetic expressions. On some machines a char whose leftmost bit is 1 will be converted to a
  negative integer("sign extension"). On others, a char is promoted to an int by adding zeros at the left end, and thus is always positive.
- The defintion of C guarantees that any character in the machine's standard printing character set will never be negative, so these will be always positive 
  quantities in expressions.
- It is better to specify signed or unsigned if non-characted data is to be stored in char variables.
- Relational and logical expressions are defined to have value 1 if true, and 0 if false.
- If an operator that takes two operands has operands of different types, the lower type is promoted to the higher type before the operation proceeds. The 
  result is of the higher type.
        If either operand is long dobule, conver the other to long double.
        Otherwise, if either operand is double, convert the other to double.
        Otherwise, if either operand is float, convert the other to float.
        Otherwise, convert char and short to int.
        Then, if either operand is long, convert the other to long.
- Floats in an expression are not automatically converted to double.
- Comparisons between signed and unsigned values are machine-dependent, because they depend on the sizes of the various integer types.
- Conversion takes place across assignments; the value of the right side is converted to the type of the left, which is the type of the result.
- A character is converted to an integer, either by sign extension or not. Long integers are converted to shorter onces or to chars by dropping the excess 
  high-order bits.
- When double is converted to float, whether the value is rounded to truncated is implementation dependent.
- Since an argument of a function call is an expression, type conversions also take place when arguments are passed to functions. In the absence of a function
  prototype, char and short become int, and float becomes double.
- If the arguments are declared by a function prototype, the declaration causes automatic coercion of any arguments when the function is called.
- Explicit type conversions can be forced in any expression, with a unary operator called a cast.
- Advantages of Type Conversions:
            -> Type safety: Type conversions can be used to ensure that data is being stored and processed in the correct data type, avoiding potential type 
                            mismatches and type errors.
            -> Improved code readability: By explicitly converting data between different types, you can make the intent of your code clearer and easier to 
                                          understand.
            -> Improved performance: In some cases, type conversions can be used to optimize the performance of your code by converting data to a more efficient
                                     data type for processing.
            -> Improved compatibility: Type conversions can be used to convert data between different types that are not compatible, allowing you to write code 
                                       that is compatible with a wider range of APIs and libraries.
            -> Improved data manipulation: Type conversions can be used to manipulate data in various ways, such as converting an integer to a string, 
                                           converting a string to an integer, or converting a floating-point number to an integer.
            -> Improved data storage: Type conversions can be used to store data in a more compact form, such as converting a large integer value to a smaller 
                                      integer type, or converting a large floating-point value to a smaller floating-point type.
- Disadvantages of Type Conversions:
            -> Loss of precision: Converting data from a larger data type to a smaller data type can result in loss of precision, as some of the data may be 
                                  truncated.
            -> Overflow or underflow: Converting data from a smaller data type to a larger data type can result in overflow or underflow if the value being 
                                      converted is too large or too small for the new data type.
            -> Unexpected behavior: Type conversions can lead to unexpected behavior, such as when converting between signed and unsigned integer types, or 
                                    when converting between floating-point and integer types.
            -> Increased complexity: Type conversions can increase the complexity of your code, making it harder to debug and maintain.
            -> Slower performance: Type conversions can sometimes result in slower performance, particularly when converting data between complex data types, 
                                   such as between structures and arrays.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    {
        int x = 10;   // integer x
        char y = 'a'; // character c

        // y implicitly converted to int. ASCII
        // value of 'a' is 97
        x = x + y;

        // x is implicitly converted to float
        float z = x + 1.0;

        printf("x = %d, z = %f", x, z);
    }
    {
        double x = 1.2;

        // Explicit conversion from double to int
        int sum = (int)x + 1;

        printf("sum = %d", sum);
    }
    {
        float a = 1.5;
        int b = (int)a;

        printf("a = %f\n", a);
        printf("b = %d\n", b);
    }
    {
        double d = 124.35656;
        float f = 12.34;
        int i = 10;
        printf("Sizeof Float f: %lu , Sizeof Double d: %lu and sizeof(d + f): %lu\n", sizeof(f), sizeof(d), sizeof(d + f));
        printf("Sizeof Float f: %lu , Sizeof Int i: %lu and sizeof(f + i): %lu\n", sizeof(f), sizeof(i), sizeof(i + f));
        printf("(d+f) = %f and (f+i) = %f\n", d + f, f + i);
        printf("(d+f) = %lf and (f+i) = %f\n", d + f, f + i);
        printf("(d+f) = %LF and (f+i) = %f\n", d + f, f + i); /* warning: format ‘%LF’ expects argument of type ‘long double’, but argument 2 has type ‘double’ */
    }
    return 0;
}
/*
x = 107, z = 108.000000sum = 2a = 1.500000
b = 1
Sizeof Float f: 4 , Sizeof Double d: 8 and sizeof(d + f): 8
Sizeof Float f: 4 , Sizeof Int i: 4 and sizeof(f + i): 4
(d+f) = 136.696560 and (f+i) = 22.340000
(d+f) = 136.696560 and (f+i) = 22.340000
(d+f) = -NAN and (f+i) = 136.696560
*/