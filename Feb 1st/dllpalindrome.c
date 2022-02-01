#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *front;
struct node *rear;
void insert(char item)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ;
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
            front->prev = NULL;
            rear->next = NULL;
            rear->prev = NULL;
        }
        else
        {
            ptr->next = NULL;
            ptr->prev = rear;
            rear->next = ptr;
            rear = ptr;
        }
    }
}

bool isPalindrome()
{
    struct node *left = front;
    if (left == NULL)
    {
        return true;
    }
    else
    {
        struct node *right = rear;
        while (left != right)
        {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("Empty \n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%c", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of charecters: ");
    char item;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter char: ");
        scanf("%c", &item);
        // void insert(char item);
    }
    void display();
}