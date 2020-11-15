/* This program swaps the nodes of linked list rather
than swapping the field from the nodes.*/

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
typedef struct Node_s
{
    int data;
    struct Node_s *next;
} Node;

/* Function to swap nodes x and y in linked list by
changing links */
Node * swapNodes(Node *head, int x, int y)
{
    Node * newHead = head;
    // Nothing to do if x and y are same
    if (x == y) return newHead;

    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = head;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = head;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return newHead;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        newHead = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        newHead = currX;

    // Swap next pointers
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
    
    return newHead;
}

Node * createList(Node * head)
{
    Node *newnode,*traverse;
	int choice;
	do
	{
		node *newnode;
		newnode=(Node *)malloc(sizeof(Node));
		printf("enter the data\n");
		scanf("%c",&newnode->data);
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
		printf("insert a newnode 1.yes 2.no\n");
		scanf("%d",&choice);
	}
	while(choice==1);
	return head;
}
/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    Node *head = NULL;

    /* The constructed linked list is:
    1->2->3->4->5->6->7 */
    head =createList(head);
    printf("\n Linked list before calling swapNodes() ");
    printList(head);

    head = swapNodes(head, 7, 5);

    printf("\n Linked list after calling swapNodes() ");
    printList(head);

    return 0;
}
rf
