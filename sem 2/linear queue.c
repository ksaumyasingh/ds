#include<stdio.h>
#include<stdlib.h>
int isFull(int r,int size)
{
	if(r==size-1)
		return 1;
	return 0;
}
int isEmpty(int r)
{
	if(r==-1)
		return 1;
	return 0;
}
void enqueue(int queue[],int *f,int *r,int size,int val)
{
	if(isFull(*r,size))
		printf("overflow\n");
	else
	{
		*r=*r+1;
		queue[*r]=val;
		printf("enqueue=%d,position=%d\n",queue[*r],*r);
	}	
}
int dequeue(int queue[],int *f,int *r,int size)
{
	if(isEmpty(*r))
		printf("underflow\n");
	else
	{
		*f=*f+1;
		return queue[*f-1];
	}
}
void display(int queue[],int f,int r,int size)
{
	int i;
	i=f;
	//printf("i=%d\n",i);
	while(i<=r)
	{
		printf("%d at position=%d\n",queue[i],i);
		i++;
	}
}
void main()
{
	int size=5,queue[size],f=0,r=-1,val,i=0,choice;
	do
	{
		printf("enter choice\n 1.enqueue\n 2.dequeue\n 3.display\n 4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the value to be inserted\n");
					scanf("%d",&val);
					enqueue(queue,&f,&r,size,val);
					break;
			case 2:
					printf("dequeue element is=%d",dequeue(queue,&f,&r,size));
					break;
			case 3:
					display(queue,f,r,size);
					break;
			case 4:
					exit(0);
					break;
			default: printf("wrong choice");
		}
		i++;
	}
	while(1);
}