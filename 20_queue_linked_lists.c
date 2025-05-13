/**
 * @author: Mitul Tyagi
 * @description: Queues using Linked List
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x, y;
    struct node *next;
} Node;
Node *front = NULL;
Node *rear = NULL;
void display();
void enqueue(int, int);
void dequeue();
void peek();
void isEmpty();
void isFull();
int main()
{
    int n, m, ch;
    do
    {
        printf("\n\nQueue Menu\n1. Add \n2. Remove\n3. Display\n4. Peek\n5. "
               "IsEmpty\n0. Exit");
        printf("\nEnter Choice 0-5? : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter number ");
            scanf("%d", &n);
            scanf("%d", &m);
            enqueue(n, m);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            isEmpty();
            break;
        }
    } while (ch != 0);
}
void enqueue(int a, int b)
{
    Node *nptr = (Node *)malloc(sizeof(struct node));
    nptr->x = a;
    nptr->y = b;
    nptr->next = NULL;
    if (rear == NULL)
    {
        front = nptr;
        rear = nptr;
    }
    else
    {
        rear->next = nptr;
        rear = rear->next;
    }
}
void peek()
{
    if (front == NULL)
    {
        printf("\n\nqueue is empty \n");
        return;
    }
    printf("Front Element: (%d,%d)\n", front->x, front->y);
}
void isEmpty()
{
    if (front == NULL)
        printf("\n\nqueue is empty \n");
    else
        printf("\n\nqueue is not empty \n");
}
void display()
{
    Node *temp;
    temp = front;
    printf("\n");
    while (temp != NULL)
    {
        printf("\n(%d,%d)", temp->x, temp->y);
        temp = temp->next;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("\n\nqueue is empty \n");
    }
    else
    {
        Node *temp;
        temp = front;
        if (front == rear)
        {
            printf("Last Element\n");
            front = NULL;
            rear = NULL;
        }
        else
            front = front->next;
        printf("\n\n(%d,%d) deleted", temp->x, temp->y);
        free(temp);
    }
}
