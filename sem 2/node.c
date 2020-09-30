#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlist(struct node *head)
{
     struct node *nn,*traverse;
    int choice;
    do
    {
        nn = (struct node *)malloc(sizeof(struct node));
        printf("enter the data of node");
        scanf("%d",&nn->data);
        nn->next = NULL;
        if(head == NULL)
        {
            head = nn;
            traverse = nn;
        }
        else
        {
            traverse->next=nn;
            traverse=nn;
        }
        printf("\n To insert more node \n1.Yes \n2.No");
        scanf("%d",&choice);
    }while(choice==1);
    return head;

}

int main()
{
    struct node *nn,*traverse,*head=NULL;
    head=createlist(head);
    traverse=head;

     for(traverse=head;traverse!=NULL;traverse=traverse->next)
    {
        printf("\n the data is %d",traverse->data);
    }
    return 0;
}