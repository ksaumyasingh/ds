#include<stdio.h>
#include<stdlib.h>
typedef struct node_s
{
	int data;
	struct node_s * next;
}node;
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
				newnode=(node *)malloc(sizeof(node));
				printf("enter the data\n");
				scanf("%d",&newnode->data);
				newnode->next=NULL;
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
		for(traverse=head;(traverse!=NULL)&&(f==0);traverse=traverse->next)
		{
			if(traverse->data==element)
			{
				printf("element found at node =%d\n",i);
				f=1;
			}
			i++;
		}
		if(f==0)
			printf("element found at node\n",i);	
	}
	
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
void main()
{
	node *head=NULL;
	int choice;
	do
	{
		printf("1.createList 2.print 3.searchAElement 4.exit list\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=createList(head);
				break;
			case 2:
				printList(head);
				break;
			case 3:
				searchAElement(head);
				break;
			case 4:
				exit(0);
		}
		
	}
	while(1);
}