#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *top = NULL;
void push(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void display()
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
void peek()
{
    if (top == NULL)
    {
        printf("Stack Empty!");
    }
    else
    {
        printf("Top element = %d", top->data);
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack empty!");
    }
    else if (top->next == NULL)
    {
        top = NULL;
        free(top);
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}
void main()
{
    push(5);
    push(10);
    push(15);
    display();
    pop();
    display();
}