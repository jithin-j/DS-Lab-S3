#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char ch;
	struct listNode *next;
	struct ListNode *prev;
}listNode;
listNode *head=NULL; 
listNode *tail=NULL;
listNode* create(char item)	
{
	listNode *node;
	node=(listNode*)malloc(sizeof(listNode));
	node->ch=item;
	node->prev=NULL;
	node->next=NULL;
	return node;
}  

void insertend(char item)	
{
	listNode *node=create(item);
	if(head==NULL)	
	{
		head=tail=node;
		head->prev=NULL;
		tail->next=NULL;
	}
	else
	{
		tail->next=node;
		node->prev=tail;
		tail=node;
		tail->next=NULL;
	}
	
}

int checkPalin()
{
	listNode *temp1=head, *temp2=tail;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->ch != temp2->ch)
			return 0;
		else{
			temp1=temp1->next;
			temp2=temp2->prev;	
		}
		
	}
	return 1;
}

void display()
{
	listNode *temp=head;
	if(head==NULL)
	{
		printf("List Empty !!!\n");
		exit(0);
	}	
	printf("Nodes of the doubly linked list are: \n");
	while(temp!=NULL)
	{
		printf("%c\t",temp->ch);
		temp=temp->next;
	}
	printf("\n");
}

void main()
{
	char str[20],s;
	int i,n;
	printf("Enter a string: ");
	gets(str);
	for(i=0;str[i]!='\0';i++)
		insertend(str[i]);
	display();
	n=checkPalin();	
	if(n==1)
		printf("%s is a Palindrome.\n",str);
	else if(n==0)
		printf("%s is not a Palindrome.\n",str);
	else
		printf("Invalid !!! Try Again...\n");		
		
		
}
