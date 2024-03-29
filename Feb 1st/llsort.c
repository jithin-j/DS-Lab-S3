#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int marks;
    char name[50];
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
    char name[50];
    printf("Enter the number of students \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name and marks of students: \n");
        scanf("%s", name);
        scanf("%d", &mark);
        insert(mark, name);
    }
    printf("Marks before sorting: \n");
    display();
    sort();
    printf("\nMarks after sorting: \n");
    display();
    printf("\n");
}

void insert(int mark, char name[])
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
        strcpy(ptr->name, name);
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
            printf("%s %d, ", ptr->name, ptr->marks);
            ptr = ptr->next;
        }
    }
}

void sort()
{
    struct node *ptr, *nextnode;
    char tempname[50];
    ptr = front;
    while (ptr != NULL)
    {
        nextnode = ptr->next;
        while (nextnode != NULL)
        {
            if (ptr->marks < nextnode->marks)
            {
                int temp = ptr->marks;
                strcpy(tempname, ptr->name);
                ptr->marks = nextnode->marks;
                strcpy(ptr->name, nextnode->name);
                nextnode->marks = temp;
                strcpy(nextnode->name, tempname);
            }
            nextnode = nextnode->next;
        }
        ptr = ptr->next;
    }
}