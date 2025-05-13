/**
 * @author: Mitul Tyagi
 * @description: Circular Queues using Arrays
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
    rear = (rear + 1) % N;
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
    front = (front + 1) % N;
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
    if (rear == (front - 1) % N) // front == (rear + 1)%N
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
    i = front;
    while (i != rear)
    {
        printf("%d\n", Arr[i]);
        i = (i + 1) % N;
    }
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
