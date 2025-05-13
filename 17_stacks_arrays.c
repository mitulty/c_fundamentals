/**
 * @author: Mitul Tyagi
 * @description: Stacks using Arrays
 */
#include <stdint.h>
#include <stdio.h>

#define MAX_LENGTH 100
int stack[MAX_LENGTH], choice, n, top, x, i;
void push(void);
void pop(void);
void Top(void);
void display(void);
int IsEmpty(void);
int main()
{
    // clrscr();
    top = -1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t \n\t4.Top \n\t5.IsEmpty() "
           "\n\t6.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            Top();
            break;
        }
        case 5:
        {
            printf("Empty Status: %d", IsEmpty());
            break;
        }
        case 6:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4/5/6)");
        }
        }
    } while (choice != 6);
    return 0;
}
void push()
{
    if (top >= n - 1)
    {
        printf("\n\tSTACK Overflow");
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\n\t Stack Under ow");
    }
    else
    {
        printf("\n\t The popped elements is %d", stack[top]);
        top--;
    }
}
void Top()
{
    if (top <= -1)
        printf("\n\t Stack Under ow");
    else
        printf("\n\t The top elements is %d", stack[top]);
}
int IsEmpty(void)
{
    if (top <= -1)
        return 1;
    else
        return 0;
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
