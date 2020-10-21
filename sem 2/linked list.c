//linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node_s
{
	int data;
	struct node_s * next;
}node;
node *insertAtBeginning(node *);
void printList(node *);
node * insertAtEnd(node *);
node * createList(node *);
void searchAElement(node *);
node *insertAtLocation(node *);
node *createANewnode();
node *insertion(node *);
node *insertAfterSomeSpecificLocation(node *);
node *deleteAtBeginnig(node *);
void deleteAtEnd(node *);
node *deleteAtposition(node *);
node *deletion(node *);
void main()
{
	node *head=NULL;
	int choice;
	do
	{
		printf("1.create list 2.print list 3.insertion 4.search an element 5.deletion 6.exit\n");
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
				head=insertion(head);
				break;
			case 4:
				searchAElement(head);
				break;
			case 5:
				head=deletion(head);
				break;
			case 6:
				exit(0);
		}	
	}
	while(1);
}
node * insertAtBeginning(node *head)
{
	node *newnode;
	newnode=createANewnode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	return head;
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
node * insertAtEnd(node *head)
{
	node *newnode,*traverse;
	newnode=createANewnode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(traverse=head;traverse->next!=NULL;traverse=traverse->next)
		{	
		}
		traverse->next=newnode;

	}
	return head;
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
node *insertAtLocation(node * head)
{
	int position,f=0,i=0;
	printf("enter the node position at which u want to insert newnode");
	scanf("%d",&position);
	node *newnode,*traverse;
	newnode=createANewnode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(traverse=head;traverse->next!=NULL&&f==0;traverse=traverse->next)
		{ 
				if(i==position-2)
				{
					f=1;
				}
				i++;
		}
		newnode->next=traverse->next;
		traverse->next=newnode;

	}
	return head;
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
node * insertAfterSomeSpecificLocation(node *head)
{
		int position,f=0,i=0;
	printf("enter the position after which u want to insert newnode");
	scanf("%d",&position);
	node *newnode,*traverse;
	newnode=createANewnode();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(traverse=head;traverse->next!=NULL&&f==0;traverse=traverse->next)
		{ 
				if(i==position-1)
				{
					f=1;
				}
				i++;
		}
		newnode->next=traverse->next;
		traverse->next=newnode;

	}
	return head;
}
node * insertion(node * head)
{
	int choice;
	printf("1.insert from beginning\n2.insert from end\n3.insert at some location\n4.insert After Some SpecificLocation\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				head=insertAtBeginning(head);
				break;
		case 2:
				head=insertAtEnd(head);
				break;
		case 3:
				head=insertAtLocation(head);
				break;
		case 4:
				head=insertAfterSomeSpecificLocation(head);
				break;
	}
	return head;
}
node * deleteAtBeginnig(node * head)
{
	node *traverse;
	traverse=head;
	head=head->next;
	free(traverse);
	return head;
}
void deleteAtEnd(node * head)
{
	node *traverse,*beforeTraverse;
	for(traverse=head;traverse->next!=NULL;traverse=traverse->next)
	{
		beforeTraverse=traverse;
	}
	beforeTraverse->next=NULL;
	free(traverse);
}
node * deleteAtposition(node * head)
{
	int position,f=0,i=0;
	node *traverse,*beforeTraverse;
	printf("enter the node position which u want to delete");
	scanf("%d",&position);
	if(head->next!=NULL)
	{
		for(traverse=head;traverse->next!=NULL&&f==0;traverse=traverse->next)
		{ 
			beforeTraverse=traverse;
			if(i==position)
			{
				f=1;
			}
			i++;
		}
		if(f==0)
			printf("not valid position");
		else
		{
		beforeTraverse->next=traverse->next;
		free(traverse);
		}
	}
	else
	{
		head=NULL;
	}
	return head;
}
node *deletion(node * head)
{
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		int choice;
		printf("1.delete from beginning\n2.delete at end\n3.delete at position\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					head=deleteAtBeginnig(head);
					break;
			case 2:
					deleteAtEnd(head);
					break;
			case 3:
					head=deleteAtposition(head);
					break;
		}
	}
	return head;
}
node *swappingOfNades(node *head);
{
	node *node1,*node2,*preNode1=NULL,*preNode2=NULL,*temp=NULL;
	int i=0,j=0;
    int n1,n1;
	printf("enter the node to be swapped\n");
	scanf("%d%d",&n1,&n2);
	if(n1==n2)
		return head;
	if(head=NULL)
		printf("list is empty");
	else
	{
		for(node1=head;node1->next!=NULL&&n1=i;node1=node1->next)
		{
			preNode1=node1;
			i++;
		}
		for(node2=head;node2->next!=NULL&&n2=j;node2=node2->next)
		{
			preNode2=node2;
			j++;
		}
		 if(node1 != NULL && node2 != NULL) {  
          
        //If previous node to node1 is not null then, it will point to node2  
        if(prevNode1 != NULL)  
            prevNode1->next = node2;          
        else  
            head  = node2;  
          
        //If previous node to node2 is not null then, it will point to node1  
        if(prevNode2 != NULL)  
            prevNode2->next = node1;  
        else  
            head  = node1;  
          
        //Swaps the next nodes of node1 and node2  
        temp = node1->next;   
        node1->next = node2->next;   
        node2->next = temp;       
    }      
    else{  
        printf("Swapping is not possible\n");  
    }  
	}
}