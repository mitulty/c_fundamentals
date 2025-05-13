/**
 * @author: Mitul Tyagi
 * @description: Stacks using Linked List
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *TOP = NULL;
Node *create_node(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->link = NULL;
    return temp;
}
void Push(int x)
{
    Node *temp = create_node(x);
    if (TOP == NULL)
    {
        TOP = temp;
        return;
    }
    temp->link = TOP;
    TOP = temp;
    return;
}
void Pop()
{
    Node *temp = TOP;
    if (temp == NULL)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    TOP = TOP->link;
    printf("Removed: %d\n", temp->data);
    free(temp);
    return;
}
void Top()
{
    if (TOP == NULL)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    printf("Top of the Stack: %d\n", TOP->data);
    return;
}
int IsEmpty()
{
    if (TOP == NULL)
        return 1;
    else
        return 0;
}
void display()
{
    Node *temp = TOP;
    if (TOP == NULL)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
    return;
}
int main(int argc, char const *argv[])
{
    Push(5);
    Push(45);
    Push(98);
    Push(1);
    Push(12);
    display();
    Pop();
    Top();
    Pop();
    Pop();
    display();
    Pop();
    Pop();
    display();
    Top();
    return 0;
}
