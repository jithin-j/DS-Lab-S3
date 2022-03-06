#include <stdio.h>
#define N 5
int dequeue[N];
int front = -1, rear = -1;
void insertfront(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        dequeue[front] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Dequeue full!");
    }
    else if (front == 0)
    {
        front = N - 1;
        dequeue[front] = x;
    }
    else
    {
        front--;
        dequeue[front] = x;
    }
}
void insertend(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        dequeue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Dequeue full!");
    }
    else if (rear == N - 1)
    {
        rear = 0;
        dequeue[rear] = x;
    }
    else
    {
        rear++;
        dequeue[rear] = x;
    }
}
void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d ", dequeue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", dequeue[i]);
}
void dequeuefront()
{
    if (front == -1 && rear == -1)
    {
        printf("Dequeue empty!");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == N - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void dequeuerear()
{
    if (front == -1 && rear == -1)
    {
        printf("Dequeue empty!");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = N - 1;
    }
    else
    {
        rear--;
    }
}
void main()
{
    insertfront(10);
    insertend(20);
    insertend(30);
    insertend(40);
    insertend(50);
    display();
    dequeuefront();
    display();
    insertend(60);
    display();
    dequeuerear();
    display();
}