#include <stdio.h>
#define N 5
int stack[N];
int top = -1;
void push(int x)
{
    if (top == N - 1)
    {
        printf("Stack full!!");
    }
    else
    {
        stack[++top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Empty!!");
    }
    else
    {
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Empty!!");
    }
    else
    {
        printf("\n%d\n\n", stack[top]);
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d \n", stack[i]);
    }
}
void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    peek();
    pop();
    display();
}
