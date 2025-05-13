/**
 * @author: Mitul Tyagi
 * @description:  Linear Queues using Arrays
 */

#include <stdint.h>
#include <stdio.h>
#define N 5
int Arr[N];
int front = -1, rear = -1;
void enqueue(int var)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        Arr[front] = var;
        printf("Added: %d\n", Arr[rear]);
        return;
    }
    if (rear == N - 1)
    {
        printf("Queue is full\n");
        return;
    }
    rear++;
    Arr[rear] = var;
    printf("Added: %d\n", Arr[rear]);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty!!!\n");
        return;
    }
    printf("Removed: %d\n", Arr[front]);
    front++;
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
}
void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty!!!\n");
        return;
    }
    printf("First Element: %d\n", Arr[front]);
    return;
}
void isEmpty()
{
    if (front == -1)
        printf("Queue is Empty!!!\n");
    else
        printf("Queue is not Empty\n");
    return;
}
void isFull()
{
    if (rear == N - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is not Full\n");
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty!!!\n");
        return;
    }
    printf("Queue:\n");
    for (i = front; i <= rear; i++)
        printf("%d\n", Arr[i]);
    return;
}
int main(int argc, char const *argv[])
{
    isEmpty();
    enqueue(5);
    enqueue(1345);
    enqueue(23);
    enqueue(52);
    isEmpty();
    enqueue(45);
    isFull();
    peek();
    display();
    dequeue();
    isFull();
    dequeue();
    dequeue();
    peek();
    display();
    isFull();
    dequeue();
    dequeue();
    isEmpty();
    return 0;
}
