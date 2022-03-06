// Priority queue using ordered array
#include <stdio.h>
#define N 100
int idx = -1;
int pqval[N], pqpriority[N];

int isEmpty()
{
    return idx == -1;
}
int isFull()
{
    return idx == N - 1;
}

void enqueue(int data, int priority)
{
    if (!isFull())
    {
        if (idx == -1)
        {
            idx++;
            pqval[idx] = data;
            pqpriority[idx] = priority;
            return;
        }
        else
        {
            idx++;
            for (int i = idx - 1; i >= 0; i--)
            {
                if (pqpriority[i] > priority)
                {
                    pqval[i + 1] = pqval[i];
                    pqpriority[i + 1] = pqpriority[i];
                }
                else
                {
                    pqval[i + 1] = data;
                    pqpriority[i + 1] = priority;
                    break;
                }
            }
        }
    }
}
void dequeue()
{
    idx--;
}
void display()
{
    for (int i = 0; i <= idx; i++)
    {
        printf("(%d, %d)\n", pqval[i], pqpriority[i]);
    }
}
void main()
{
    enqueue(10, 1);
    enqueue(20, 2);
    enqueue(30, 4);
    enqueue(40, 3);
    display();
    dequeue();
    display();
}