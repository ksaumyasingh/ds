#include<stdio.h>
#include<stdlib.h>
typedef struct node_S
{
	int amount_deposited;
	char item[10];
	struct node_S *next;
}node;
node * seller(node *);
node * buyer(node *);
void main()
{
	node *head=NULL;
	int choice;
	do
	{
		printf("1.seller , 2.buyer , 3.exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
					head=seller(head);
					break;
			case 2: 
					head=buyer(head);
					break;
			case 3: 
					exit(0);
		}
	}
	while(1);
}
node * seller(node *head)
{
	node *newnode,*traverse;
	int choice;
	do
	{
		newnode=(node *)malloc(sizeof(node));
		printf("\n enter amount deposited");
		scanf("%d",&(newnode->amount_deposited));
		printf("\n enter item for sell \n");
		scanf("%s",&(newnode->item));
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			traverse=newnode;
		}
		else
		{
			int m=0,i=0,j=1;
			for(traverse=head;traverse!=NULL;traverse=traverse->next)
			{
				if((newnode->amount_deposited)<(traverse->amount_deposited))
				{
					m=traverse->amount_deposited;
					printf("\n %d=m",m);
					i++;
				}
				else
					break;
			}
			if(m==0)
			{
				newnode->next=head;
				head=newnode;
				traverse=head;
				printf("\n %d head",head);
			}
			else
			{
				for(traverse=head;traverse->next!=NULL&&j!=i;traverse=traverse->next)
				{
					j++;
				}
				newnode->next=traverse->next;
				traverse->next=newnode;
				traverse=traverse->next;
			}
		}
		printf("\n add more item 1.yes 2.no");
		scanf("%d",&choice);
	}
	while(choice==1);
	printf("\n %d head",head);
	return head;
}
node * buyer(node *head)
{
	node *traverse;
	int m,choice,position;
	do
	{
		printf("\n items you can purchase");
		if(head==NULL)
		{
			printf("\n all items are out of stock");
			return head;
		}
		else
		{
			m=head->amount_deposited;
			for(traverse=head;traverse!=NULL&&m==traverse->amount_deposited;traverse=traverse->next)
			{
				printf("\n %s  %d   %d",traverse->item,traverse->amount_deposited,(traverse->next)->amount_deposited);
			}	
			printf("\n enter position of item u want to buy");
			scanf("%d",&position); 
			if(position==0)
			{
				printf("\n purchased item=%s",head->item);
				traverse=head;
				head=head->next;
				free(traverse);
			}
			else
			{
				int i=0,f=0;
				node *prevTraverse;
				for(traverse=head;(traverse!=NULL&&m==traverse->amount_deposited)&&f==0;traverse=traverse->next)
				{
					prevTraverse=traverse;
					if(i==position-1)
						f=1;
					i++;
				}
				if(f==0)
					printf("\n wroung item no.");
				else
				{
					printf("purchased item=%s",traverse->item);
					prevTraverse->next=traverse->next;
					free(traverse);
				}
			}
		}
		printf("\n buy more item 1.yes 2.no");
		scanf("%d",&choice);
	}
	while(choice==1);
	return head;	
}