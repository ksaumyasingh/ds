#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};

struct node * createList(struct node *);
int main()
{
  struct node *head=NULL,*traverse;
  head=createList(head);
  printf("linkedlist");
  for(traverse=head;traverse!=NULL;traverse=traverse->next)
    printf("%d\n",traverse->data);
}
struct node * createList(struct node *head)
{
	struct node *newnode,*traverse;
	 int choice;
  do
  {
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
      if(head==NULL)
      {
        head=newnode;
        traverse=head;
      }
      else
      {
        traverse->next=newnode;
        traverse=traverse->next;
      }
    printf("1.newnode,2.none");
    scanf("%d",&choice);
  }
  while(choice==1);
	return head;
}