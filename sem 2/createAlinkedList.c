#include<stdio.h>
#include<stdlib.h>
typedef struct node_s
{
	int data;
	struct node_s * next;
}node;
node *createANewnode();
node * createList(node *);
void printList(node *);
void searchAElement(node *);
void main()
{
	node *head=NULL;
	head=createList(head);
	printList(head);
	searchAElement(head);
}
void printList(node *traverse)
{
	printf("linked list\n");
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;	
	}
}
node * createList(node * head)
{
    node *newnode,*traverse;
	int choice;
	do
	{
		printf("insert a newnode 1.yes 2.no\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				newnode=createANewnode();
				if(head==NULL)
				{
					traverse=newnode;
					head=newnode;
					
				}
				else
				{
					traverse->next=newnode;
					traverse=traverse->next;
				}

				break;
		}
		
	}
	while(choice==1);
	return head;
}
void searchAElement(node *head)
{
	int element,i=0,f=0;
	node * traverse;
	if(head==NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		printf("enter the element to be searched\n");
		scanf("%d",&element);
		for(traverse=head;traverse!=NULL&&f==0;traverse=traverse->next)
		{
			if(traverse->data==element)
			{
				printf("element found at node =%d\n",i+1);
				f=1;
			}
			i++;
		}
		if(f==0)
			printf("element not found in list");	
	}
	
}
node * createANewnode()
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}