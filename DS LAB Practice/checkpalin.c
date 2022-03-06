#include <stdio.h>
#include <malloc.h>
struct node
{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *front = NULL, *rear = NULL;
void insertend(char c)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = c;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        front->prev = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = newnode;
        newnode->prev = rear;
        newnode->next = NULL;
        rear = newnode;
    }
}
int checkpalin()
{
    struct node *temp1 = front, *temp2 = rear;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
    }
    return 1;
}
void main()
{
    char a[50];
    printf("Enter the string: ");
    gets(a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        insertend(a[i]);
    }
    int ans = checkpalin();
    if (ans == 1)
    {
        printf("Palindrome!\n");
    }
    else
    {
        printf("Not Palindrome!\n");
    }
}