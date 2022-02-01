#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete ();
void display();
void main()
{
    int choice;
    printf("1.Insert into queue \n2.Delete from queue \n3.Delete from queue \n4.Exit \n");
    scanf("%d", &choice);
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            insert();
            display();
            break;

        case 2:
            delete ();
            display();
            break;

        case 3:
            display();
            break;

        case 4:
            break;
        default:
            printf("Please enter correct choice \n");
        }
        printf("\n1.Insert into queue \n2.Delete from queue \n3.Display the queue \n4.Exit \n");
        scanf("%d", &choice);
    }
}

void insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter value: ");
    scanf("%d", &item);
    if (ptr == NULL)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}

void delete ()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("Underflow \n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("Empty Queue \n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}