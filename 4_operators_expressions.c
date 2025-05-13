/**
 * @author: Mitul Tyagi
 * @description: Operators and Expressions
 */
/*
- Operators can be defined as the symbols that perform specific mathematical, relational, bitwise, conditional, or logical computations on operands.
  In other words, an operator operates the operands. C Operators are symbols that represent operations to be performed on one or more operands. C provides a
  wide range of operators, which can be classified into different categories based on their functionality. Operators are used for performing operations on
  variables and values.
- Arithmetic Operators: The binary arithmetic operators are +, -, *, /, and the modulus operator %. Integer division truncates any fractional part. The %
  operator can not be applied to float or double. The unary arithmetic operators  are + and -. They work with single operand.
- The direction of truncation for / and the sign of the result for % are machine-dependent for negative operands, as is the action taken on overflow or
  underflow.
- Arithmetic operators associate left to right.
- Relational Operators: These are used for the comparison of the values of two operands. These are >, >=, <, <= , == and !=. These are used for the comparison
  of the values of two operands.
- Logical Operators: These are used to combine two or more conditions/constraints or to complement the evaluation of the original condition in consideration.
  The result of the operation of a logical operator is a Boolean value either "true" or "false". These are &&, || and !. The unary negation operator ! converts
  a non-zero operand into 0, and a zero operand into 1.
- The numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the relation is false.
- Assignment Operators:These are used to assign value to a variable. These are =, -=, +=, *=, /=, %=, <<=, >>=, &=, ^= and |=. THe type of the assignment
  expression is the type of its left operand, and the value is the value after the assignment.
- Increement and Decreement Operators: The increment operator ++ adds 1 to its operand, while the decrement operator -- subtracts 1. They may be used eithere
  as prefix operators or postfix. In both the cases, the effect is to increment n. But the ++n expression increments n before its value is used, while n++
  increments n after its value has been used. They are only applied to variables and not expressions.
- Bitwise Operators: These perform bit manipulation and these may only be applied to integral operands, that is char, short, int and long, whether signed or
  unsigned. These are &, |, ^, <<, >> and ~. The bitwise AND operator & is often used to mask off some set of bits. The bitwise OR operator | is used to turn
  bits on. The bitwise exclusive OR operator ^ sets a one in each bit position where its operands have different bits, and zero where they are the same.
- The shift operators << and >> perform left and right shifts of thei left operand by the number of bit positions given by the right operand, which must be
  positive. Right shifting an unsigned quantity always fills vacated bits with zero. Right shifting a signed quantity will fill with sign bits (arithmetic
  shift) on some machines and with 0-bits( logical shift ) on others. The unary operator ~ yields the one's complement of an integer.
- Ternary Operator: It is of the form Expression1? Expression2: Expression3. Here, Expression1 is the condition to be evaluated. If the condition(Expression1)
  is "true" then we will execute and return the result of Expression2 otherwise if the condition(Expression1) is "false" then we will execute and return the
  result of Expression3.
- Comma Operator: It is a binary operator that evaluates its first operand and discards the result, it then evaluates the second operand and returns this value
  (and type). It has the lowest precedence of any C operator.
- sizeof Operator: It is a compile-time unary operator which is used to compute the size of its operands. The result of sizeof is of the unsigned integral type
  which is usually denoted by size_t.
- The dot (.) and the arrow (->) Operators: The member operators are used for referencing individual members of structures, and unions. The dot operator is
  applied to the actual object. The arrow operator is used with a pointer to an object.
- &,* Operator: Pointer operator & returns the address of a variable. The pointer operator * is a pointer to a variable.
- Precedence is the priority for grouping different types of operators with their operands. Associativity is the left-to-right or right-to-left order for
  grouping operands to operators that have the same precedence. Operator precedence describes how operations are performed in an arithmetic expression. It
  determines how terms are grouped in an expression and how the expression is evaluated.
|------------|---------------|-------------------------------------------------------|--------------------|
|Precedence  |    Operator   |             description                               |  Associativity     |
|------------|---------------|-------------------------------------------------------|--------------------|
|1           |    ()         |     Parentheses (function call)                       |  left-to-right     |
|            |    []         |     Brackets (array subscript)                        |  left-to-right     |
|            |    .          |     Member selection via object name                  |  left-to-right     |
|            |    ->         |     Member selection via a pointer                    |  left-to-right     |
|            |    a++/a--    |     Postfix increment/decrement (a is a variable)     |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|2           |    ++a/--a    |     Prefix increment/decrement (a is a variable)      |  right-to-left     |
|            |    +/-        |     Unary plus/minus                                  |  right-to-left     |
|            |    !/~        |     Logical negation/bitwise complement               |  right-to-left     |
|            |    (type)     |     Cast (convert value to temporary value of type)   |  right-to-left     |
|            |    *          |     Dereference                                       |  right-to-left     |
|            |    &          |     Address (of operand)                              |  right-to-left     |
|            |    sizeof     |     Determine size in bytes on this implementation    |  right-to-left     |
|------------|---------------|-------------------------------------------------------|--------------------|
|3           |    *,/,%      |     Multiplication/division/modulus                   |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|4           |    +/-        |     Addition/subtraction                              |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|5           |    << , >>    |     Bitwise shift left, Bitwise shift right           |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|6           |    < , <=     |     Relational less than/less than or equal to        |  left-to-right     |
|            |    > , >=     |     Relational greater than/greater than or equal to  |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|7           |    == , !=    |     Relational is equal to/is not equal to            |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|8           |    &          |     Bitwise AND                                       |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|9           |    ^          |     Bitwise exclusive OR                              |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|10          |    |          |     Bitwise inclusive OR                              |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|11          |    &&         |     Logical AND                                       |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|12          |    ||         |     Logical OR                                        |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
|13          |    ?:         |     Ternary conditional                               |  right-to-left     |
|------------|---------------|-------------------------------------------------------|--------------------|
|14          |    =          |     Assignment                                        |  right-to-left     |
|            |    += , -=    |     Addition/subtraction assignment                   |  right-to-left     |
|            |    *= , /=    |     Multiplication/division assignment                |  right-to-left     |
|            |    %= , &=    |     Modulus/bitwise AND assignment                    |  right-to-left     |
|            |    ^= , |=    |     Bitwise exclusive/inclusive OR assignment         |  right-to-left     |
|            |    <<=,>>=    |     Bitwise shift left/right assignment               |  right-to-left     |
|------------|---------------|-------------------------------------------------------|--------------------|
|15          |    ,          |     expression separator/comma operator               |  left-to-right     |
|------------|---------------|-------------------------------------------------------|--------------------|
- Function calls, nested assignment statements, and increment and decrement opearators cause "side effects".
- An expression in C is a combination of operands and operators that evaluates to a single value. The operands can be variables, constants, or function calls.
  The operators can be arithmetic, logical, relational, or assignment operators.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
void operator_check()
{
  int a = 10, b = 20, c, x = 100, y = 125, z = 125;
  char ch = 'a';
  c = a + 4 / 6 * 6 / 2;
  printf("---------------------------------Case 1-----------------------------------------------------\n");

  printf("Value= %d\n", c);
  c = b + 3 / 2 * 2 / 3;
  printf("Value= %d\n", c);

  printf("%c\n", x);
  printf("%c\n", y);
  printf("%d\n", x);
  printf("%d\n", ch);
  printf("%c\n", ch);
  printf("%d\n", 10 + x++);
  printf("%d\n", 10 + ++x);
  x = y == z;
  printf("%d\n", x);
  printf("%d\n", (x > y) ? x : y);
  printf("---------------------------------Case 2-----------------------------------------------------\n");
  unsigned m = 1;
  signed char n = -1;
  printf("%c %d\n", n, n);
  printf("%c %d\n", m, m);
  if (m > n)
    printf("m>n\n");
  else
    printf("m<=n\n");
  printf("---------------------------------Case 3-----------------------------------------------------\n");
  int r = 10;
  if (r = 0)
    printf("TRUE\n");
  else
    printf("FALSE\n");
  if (r = 20)
    printf("TRUE\n");
  else
    printf("FALSE\n");
  printf("---------------------------------Case 4-----------------------------------------------------\n");
  for (int m = 0; m < 3; ++m)
    printf("%d\n", (m = (m % 2) ? m : m + 2));
  printf("---------------------------------Case 5-----------------------------------------------------\n");
  for (int m = 0; m < 3; ++m)
    printf("%d\n", (m % 2) ? m : m + 2);
  printf("---------------------------------Case 6-----------------------------------------------------\n");
  int p = -14, q = 3;
  printf("%d\n", p / q * 10);
  q = -q;
  printf("%d\n", p / q * 10);
  printf("---------------------------------Case 7-----------------------------------------------------\n");
  // Concept of a block in C
  {
    int p = -6, q = 7;
    printf("%d\n", p / q);
    q = -q;
    printf("%d\n", p / q);
  }
}
int main(int argc, char const *argv[])
{
  int a = 10, b = 5;
  // Arithmetic operators
  printf("Following are the Arithmetic operators in C\n");
  printf("The value of a + b is %d\n", a + b);
  printf("The value of a - b is %d\n", a - b);

  printf("The value of a * b is %d\n", a * b);
  printf("The value of a / b is %d\n", a / b);
  printf("The value of a % b is %d\n", a % b);
  // First print (a) and then increment it
  // by 1
  printf("The value of a++ is %d\n", a++);

  // First print (a+1) and then decrease it
  // by 1
  printf("The value of a-- is %d\n", a--);

  // Increment (a) by (a+1) and then print
  printf("The value of ++a is %d\n", ++a);

  // Decrement (a+1) by (a) and then print
  printf("The value of --a is %d\n", --a);

  // Assignment Operators --> used to assign values to
  int avar = 3, bvar = 9;
  char dvar = 'd';
  avar += 5;
  bvar /= 2;
  bvar -= 1;
  dvar += 3;
  // Comparison operators
  // Output of all these comparison operators will be (1)
  // if it is true and (0) if it is false
  printf("\nFollowing are the comparison operators in C\n");
  printf("The value of a == b is %d\n", (a == b));
  printf("The value of a != b is %d\n", (a != b));
  printf("The value of a >= b is %d\n", (a >= b));
  printf("The value of a <= b is %d\n", (a <= b));
  printf("The value of a > b is %d\n", (a > b));
  printf("The value of a < b is %d\n", (a < b));

  // Logical operators
  printf("\nFollowing are the logical operators in C\n");
  printf("The value of this logical and operator ((a==b) && (a<b)) is:%d\n", ((a == b) && (a < b)));
  printf("The value of this logical or operator ((a==b) || (a<b)) is:%d\n", ((a == b) || (a < b)));
  printf("The value of this logical not operator (!(a==b)) is:%d\n", (!(a == b)));

  {
    int a = 2, b = 3, c = 4, z;
    // Arithmetic Expressions
    z = a + b - (a * c);

    printf("Result= %d\n", z);
    char c[] = "Hello";
  }
  {
    // ternary operator
    int m = 5, n = 4;

    (m > n) ? printf("m is greater than n that is %d > %d\n", m, n) : printf("n is greater than m that is %d > %d\n", n, m);
    int yr = 1900;

    (yr % 4 == 0) ? (yr % 100 != 0 ? printf("The year %d is a leap year\n", yr)
                                   : (yr % 400 == 0 ? printf("The year %d is a leap year\n", yr)
                                                    : printf("The year %d is not a leap year\n", yr)))
                  : printf("The year %d is not a leap year\n", yr);
  }
  operator_check();
  return 0;
}
/*
Following are the Arithmetic operators in C
The value of a + b is 15
The value of a - b is 5
The value of a * b is 50
The value of a / b is 2
The value of a % b is 0
The value of a++ is 10
The value of a-- is 11
The value of ++a is 11
The value of --a is 10

Following are the comparison operators in C
The value of a == b is 0
The value of a != b is 1
The value of a >= b is 1
The value of a <= b is 0
The value of a > b is 1
The value of a < b is 0

Following are the logical operators in C
The value of this logical and operator ((a==b) && (a<b)) is:0
The value of this logical or operator ((a==b) || (a<b)) is:0
The value of this logical not operator (!(a==b)) is:1
Result= -3
m is greater than n that is 5 > 4
The year 1900 is not a leap year
---------------------------------Case 1-----------------------------------------------------
Value= 10
Value= 20
d
}
100
97
a
110
112
1
125
---------------------------------Case 2-----------------------------------------------------
� -1
 1
m<=n
---------------------------------Case 3-----------------------------------------------------
FALSE
TRUE
---------------------------------Case 4-----------------------------------------------------
2
---------------------------------Case 5-----------------------------------------------------
2
1
4
---------------------------------Case 6-----------------------------------------------------
-40
40
---------------------------------Case 7-----------------------------------------------------
0
0
*/
