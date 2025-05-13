/**
 * @author: Mitul Tyagi
 * @description: Statements in C
 */
/*
- An expression becomes a statement when it is followed by a semicoloon. The
semicolon is a statement terminator. Braces { and } are used to group
declarations and statementes together into a compound statement, or block. There
is no semicolon after the right brace that ends a block.
- The if-else statement is used to express decisions. The else part is optional.
In a nested if-else block, the else block belongs to the closes previous
else-less if. The else-if construction is a multi-way decision. The
expressions are evaluated in order.
- The if else if ladder in C programming is used to test a series of conditions
sequentially. Furthermore, if a condition is tested only when all previous if
conditions in the if-else ladder are false. If any of the conditional
expressions evaluate to be true, the appropriate code block will be executed,
and the entire if-else ladder will be terminated.
- The switch statement is a multi-way decision that tests whether an expression
matches one of a number of constant integer values, and branches accordingly.
Each case is labeled by one or more integer-valued constants or constant
expression. If a case matches the expression value, execution starts at that
cases. All case expressions must be different. The case labeled default is
executed if none of the other cases are satisfied. A default is optional. Cases
and default clause can occur in any order. The break statement causes an
immediate exit from the switch. Because cases serve just as labels, after the
code for one case is done, execution falls through to the next unless explicit
actions are taken to escape. break and return are the most common ways to leave
a switch. The expression has to be a constant expression or a variable of an
integer/character type.
        -> Switch expression should result in a constant value.
        -> Expression must evaluate only int or char type values.
        -> No duplicate Case Values
        -> Nested Switch statements are allowed but avoided for most of the
           times.
- Any non-zero and non-null values are assumed to be true, and zero or null
values are assumed to be false.
- Loops in programming are used to repeat a block of code until the specified
condition is met. A loop statement allows programmers to execute a statement or
group of statements multiple times without repetition of code. C supports
three different loop statements: for, while and do-while.
- There are mainly two types of loops in C Programming:
        -> Entry Controlled loops: In Entry controlled loops the test condition
           is checked before entering the main body of the loop. For Loop and
           While Loop are Entry-controlled loops.
        -> Exit Controlled loops: In Exit controlled loops the test condition is
           evaluated at the end of the loop body. The loop body will execute at
           least once, irrespective of whether the condition is true or false.
           A do-while Loop is an Exit Controlled loop.
- for loop in C programming is a  repetition control structure that allows
programmers to write a loop that will be executed a specific number of times.
for loop enables programmers to perform n number of steps together in a single
line.
    for (initialize expression; test expression; update expression)
                {
                    //
                    // body of for loop
                    //
                }
- In for loop, a loop variable is used to control the loop. Firstly we
initialize the loop variable with some value, then check its test condition. If
the statement is true then control will move to the body and the body of for
loop will be executed. Steps will be repeated till the exit condition becomes
true. If the test condition will be false then it will stop.
            -> Initialization Expression: In this expression, we assign a loop
               variable or loop counter to some value. for example: int i=1;
            -> Test Expression: In this expression, test conditions are
               performed. If the condition evaluates to true then the loop body
               will be executed and then an update of the loop variable is done.
               If the test expression becomes false then the control will exit
               from the loop. for example, i<=9;
            -> Update Expression: After execution of the loop body loop variable
               is updated by some value it could be incremented, decremented,
               multiplied, or divided by any value.
- It is possible to place multiple expressions in the various parts of a for
statement using comma operator. They will be evaluated left to right.
- While loop does not depend upon the number of iterations. In for loop the
number of iterations was previously known to us but in the While loop, the
execution is terminated on the basis of the test condition. If the test
condition will become false then it will break from the while loop else body
will be executed. initialization_expression;

                while (test_expression)
                {
                    // body of the while loop

                    update_expression;
                }
- The do-while loop is similar to a while loop but the only difference lies in
the do-while loop test condition which is tested at the end of the body. In the
do-while loop, the loop body will execute at least once irrespective of the
test condition.

                initialization_expression;
                do
                {
                    // body of do-while loop


                    update_expression;

                } while (test_expression);
- The break statement is used to terminate the switch and loop statement. It
transfers the execution to the statement immediately following the loop or
switch.
- The continue statement skips the remainder body and immediately resets its
condition before reiterating it. It applies only to loops, & not to switch. In
the while and do, this means that the test part is executed immediately; in the
for, control passes to the increment step.
- The goto statement transfers the control to the labeled statement. The most
common is to abandon process in some deeply nested structure, such as
breaking out of two or more loops at once. A label has the same form as a
variable name, and is followed by a colon. It can be attached to any statement
in the same function as the goto. The scope of a label is the entire function.
- An infinite loop is executed when the test expression never becomes false and
the body of the loop is executed repeatedly. A program is stuck in an infinite
loop when the condition is always true. Mostly this is an error that can be
resolved by using Loop Control statements.
                    for ( ; ; )
                      {
                        printf("This loop will run forever.\n");
                      }
                    while (1)
                        printf("This loop will run forever.\n");
                    do
                      {
                        printf("This loop will run forever.\n");
                      } while (1);
*/
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0, n = 14, var = 3;
    int p1_age = 15;
    int p2_age = 25;
    int gfg = 9;
    int num = 9911234;
    int marks = 91;

    // if statement with true condition
    if (gfg < 10)
    {
        printf("%d is less than 10\n", gfg);
    }

    // if statement with false condition
    if (gfg > 20)
    {
        printf("%d is greater than 20\n", gfg);
    }

    // checking eligibility of person 1
    if (p1_age < 18)
        printf("Person 1 is not eligible to vote.\n");
    else
        printf("Person 1 is eligible to vote.\n");

    // checking eligiblity of person 2
    if (p2_age < 18)
        printf("Person 2 is not eligible to vote.\n");
    else
        printf("Person 2 is eligible to vote.\n");

    // if block with condition at the start
    if (5 < 10)
    {

        // will be executed if the condition is true
        printf("5 is less than 10.\n");
    }
    // else block after the if block
    else
    {
        // will be executed if the condition is false
        printf("5 is greater that 10.\n");
    }

    // The if-else-if ladder
    if (n > 0)
    {
        printf("Positive\n");
    }
    // all Negative numbers will make this
    // condition true
    else if (n < 0)
    {
        printf("Negative\n");
    }
    // if a number is neither Positive nor Negative
    else
    {
        printf("Zero\n");
    }

    // checking the condition at the start of if block
    if (num % 2 == 0)
    {
        // executed when the number is even
        printf("Number is even\n");
    }
    // else block
    else
    {
        // executed when the number is odd
        printf("Number is Odd\n");
    }

    // The if-else-if ladder
    if (marks <= 100 && marks >= 90)
        printf("A+ Grade\n");
    else if (marks < 90 && marks >= 80)
        printf("A Grade\n");
    else if (marks < 80 && marks >= 70)
        printf("B Grade\n");
    else if (marks < 70 && marks >= 60)
        printf("C Grade\n");
    else if (marks < 60 && marks >= 50)
        printf("D Grade\n");
    else
        printf("F Failed\n");
    return 0;

    // if else statement for true condition
    if (1)
    {
        printf("The if block  is executed.\n");
    }
    else
    {
        printf("The else block is executed\n");
    }

    // switch variable
    char x = 'A';

    // switch statements
    switch (x)
    {
    case 'A':
        printf("Choise is A\n");
        break;
    case 'B':
        printf("Choise is B\n");
        break;
    case 'C':
        printf("Choise is C\n");
        break;
    default:
        printf("Choise is absent\n");
        break;
    }

    // switch case without break
    switch (var)
    {
    case 1:
        printf("Case 1 is executed.\n");
    case 2:
        printf("Case 2 is executed.\n");
    case 3:
        printf("Case 3 is executed.\n");
    case 4:
        printf("Case 4 is executed.");
    }

    num = 2;

    switch (num)
    {
    case 1:
    case 2:
    case 3:
        printf("Number is between 1 and 3\n");
        break;
    case 4:
    case 5:
        printf("Number is either 4 or 5\n");
        break;
    default:
        printf("Number is outside the range 1-5\n");
        break;
    }

    for (i = 1; i <= 10; i++)
    {
        printf("Hello World\n");
    }

    while (i < 20)
    {
        // loop body
        printf("Hello World\n");

        // update expression
        i++;
    }

    do
    {
        // loop body
        printf("Hello World\n");

        // Update expression
        i++;

        // Test expression
    } while (i < 30);

    return 0;
}
/*
9 is less than 10
Person 1 is not eligible to vote.
Person 2 is eligible to vote.
5 is less than 10.
Positive
Number is even
A+ Grade
*/
