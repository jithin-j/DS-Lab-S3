#include <stdio.h>
#include <stdlib.h>
struct node
{
    int marks;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void display();
void sort();

void main()
{
    int n, mark;
    printf("Enter the number of students \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks of students: ");
        scanf("%d", &mark);
        insert(mark);
    }
    printf("Marks before sorting: \n");
    display();
    sort();
    printf("\nMarks after sorting: \n");
    display();
    printf("\n");
}

void insert(int mark)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->marks = mark;
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
            printf("%d ", ptr->marks);
            ptr = ptr->next;
        }
    }
}

void sort()
{
    struct node *ptr, *nextnode;
    ptr = front;
    while (ptr != NULL)
    {
        nextnode = ptr->next;
        while (nextnode != NULL)
        {
            if (ptr->marks < nextnode->marks)
            {
                int temp = ptr->marks;
                ptr->marks = nextnode->marks;
                nextnode->marks = temp;
            }
            nextnode = nextnode->next;
        }
        ptr = ptr->next;
    }
}