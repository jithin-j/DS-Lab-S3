#include <stdio.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
void enqueue(int x)
{
    if (rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if (rear == N - 1)
    {
        printf("Queue Full!");
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Empty!!");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
void printq()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}
void main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    printq();
    dequeue();
    printq();
}