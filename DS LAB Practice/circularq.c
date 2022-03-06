#include <stdio.h>
#define N 5
int cq[N];
int front = -1, rear = -1;
void enqueue(int x)
{
    if (rear == -1)
    {
        front = 0, rear = 0;
        cq[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Circular queue full!");
    }
    else
    {
        rear = (rear + 1) % N;
        cq[rear] = x;
    }
}
void deleteq()
{
    if (front == -1)
    {
        printf("Circular queue empty!");
    }
    else if (rear == front)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Empty!!");
    }
    else
    {
        while (i != rear)
        {
            printf("%d", cq[i]);
            i = (i + 1) % N;
        }
        printf("%d", cq[rear]);
    }
}
void main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    printf("\n");
    deleteq();
    display();
    printf("\n");
    enqueue(6);
    display();
    printf("\n");
}