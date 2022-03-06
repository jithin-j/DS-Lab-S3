#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *new_node, *temp, *head = NULL;
void insertatend()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next == NULL;
    if (head == NULL)
    {
        head = temp = new_node;
    }
    else
    {
        struct node *i = head;
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = new_node;
    }
}
void insertatbeg()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next == NULL;
    if (head == NULL)
    {
        head = temp = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insertatpos()
{
    int pos, flag = 0, i = 1, count = 1;
    struct node *temp_node, *temp_node2 = head;
    while (temp_node2->next != NULL)
    {
        temp_node2 = temp_node2->next;
        count++;
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next == NULL;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Invalid position");
    }
    else
    {
        temp_node = head;
        while (i < pos - 1)
        {
            temp_node = temp_node->next;
            i++;
        }
        new_node->next = temp_node->next;
        temp_node->next = new_node;
    }
}
void displayll()
{
    struct node *i = head;
    while (i != NULL)
    {
        printf("%d ", i->data);
        i = i->next;
    }
    printf("\n");
}
void deletefront()
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
}
void deleterear()
{
    struct node *prev, *temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        prev->next = NULL;
        free(temp);
    }
}
void deletefrompos()
{
    struct node *nextnode, *temp = head;
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
void main()
{
    int choice, option;
    while (option)
    {
        printf("1.Insert at end \n2.Insert at begining \n3.Insert at position \n4.Display \n5.Delete from front \n6.Delete from rear \n7.Delete from a position \n8.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatend();
            break;
        case 2:
            insertatbeg();
            break;
        case 3:
            insertatpos();
            break;
        case 4:
            displayll();
            break;
        case 5:
            deletefront();
            break;
        case 6:
            deleterear();
            break;
        case 7:
            deletefrompos();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter a correct option \n ");
            break;
        }
        printf("Do you want to continue? (1 -> Yes, 0 -> No): ");
        scanf("%d", &option);
    }
}