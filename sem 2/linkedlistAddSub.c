#include<stdio.h>
#include<stdlib.h>
typedef struct node_s
{
	int data;
	struct node_s * next;
}node;
node * createANewnode()
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}
node * createList(node * head)
{
    node *newnode,*traverse;
	int choice;
	do
	{
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
		printf("insert a newnode 1.yes 2.no\n");
		scanf("%d",&choice);
	}
	while(choice==1);
	return head;
}
void printList(node *traverse)
{
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;	
	}
}

void swap(node *head,int n1, int n2)
{  
        struct node *prevNode1 = NULL, *prevNode2 = NULL, *node1 = head, *node2 = head, *temp = NULL;  
          
        //Checks if list is empty  
        if(head == NULL) {  
            return;  
        }  
              
        //If n1 and n2 are equal, then list will remain the same  
        if(n1 == n2)  
            return;  
          
        //Search for node1  
        while(node1 != NULL && node1->data != n1){  
            prevNode1 = node1;  
            node1 = node1->next;  
        }  
          
        //Search for node2  
        while(node2 != NULL && node2->data != n2){  
            prevNode2 = node2;  
            node2 = node2->next;  
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
void main()
{
  /*node *headA=NULL,*headB=NULL,*traverseA,*traverseB,*headA_B=NULL,*headB_A=NULL,*traverseA_B,*traverseB_A,*newnode;;
  printf("create list A\n");
  headA=createList(headA);
  printf("create list B\n");
  headB=createList(headB);
  printList(headB);
  printf("$");
  traverseA=headA;
  printf("\ntraverseA=%D",traverseA);
  traverseB=headB;
  printf("\ntraverseA=%D",traverseA);
  printf("\n+");
  while((traverseA!=NULL)&&(traverseB!=NULL))
  {
	  printf("/");
	  if(traverseA->data==traverseB->data)
	  {
		  printf("- \n");
	  }
	  else
		{
	        newnode=(node *)malloc(sizeof(node));
			newnode->data=traverseA->data;
			newnode->next=NULL;
			if(headA_B==NULL)
			{
				traverseA_B=newnode;
				headA_B=newnode;
			}
			else
			{
				traverseA_B->next=newnode;
				traverseA_B=traverseA_B->next;
			}
			newnode=(node *)malloc(sizeof(node));
			newnode->data=traverseB->data;
			newnode->next=NULL;
			if(headB_A==NULL)
			{
				traverseB_A=newnode;
				headB_A=newnode;
			}
			else
			{
				traverseB_A->next=newnode;
				traverseB_A=traverseB_A->next;
			}
			printf("* \n");
		}
	 traverseA=traverseA->next;
	 traverseB=traverseB->next;
  }
  printf("\nA-B=");
  printList(headA_B);
  printf("\nB-A=");
  printList(headB_A);*/
  node *head=NULL;
  int i;
  head=createList(head);
  swap(head,2,3);
}
