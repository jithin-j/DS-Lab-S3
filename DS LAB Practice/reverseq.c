// Program to reverse a queue using stack
#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL, *top = NULL;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void dequeuepush()
{
    struct node *temp = front;
    while (front != NULL)
    {
        temp = front;
        push(temp->data);
        front = front->next;
    }
}
void displaystack()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack Empty! \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
    }
}
void displayqueue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue empty! \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void popenqueue()
{
    while (top != NULL)
    {
        struct node *temp;
        temp = top;
        top = top->next;
        enqueue(temp->data);
    }
}
void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    displayqueue();
    dequeuepush();
    displaystack();
    front = NULL;
    rear = NULL;
    popenqueue();
    displayqueue();
}