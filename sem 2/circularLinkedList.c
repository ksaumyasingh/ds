//linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}node;
void printList(node *head)
{
	node * traverse;
	traverse=head;
	
	printf("linked list\n");
	do
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;	
	}
	while(traverse!=head);
}
void main()
{
	node *newnode,*head,*traverse;
	head=NULL;
	int choice;
	do
	{
		printf("insert a newnode 1.yes 2.no\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				newnode=(node *)malloc(sizeof(node));
				printf("enter the data\n");
				scanf("%d",&newnode->data);
				newnode->next=head;
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
	printList(head);

}


