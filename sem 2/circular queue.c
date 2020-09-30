#include<stdio.h>
#include<stdlib.h>
int isFull(int f,int r,int size)
{
		if((r+1)%size==f)
			return 1;
		else
			return 0;
}
int isEmpty(int r,int f)
{
	if(r==f)
		return 1;
	return 0;
}
void enqueue(int queue[],int *f,int *r,int size,int val)
{
	if(isFull(*f,*r,size))
		printf("overflow\n");
	else
	{
		*r=(*r+1)%size;
		queue[*r]=val;
		printf("enqueue=%d,position=%d\n",queue[*r],*r);
	}	
}
int dequeue(int queue[],int *f,int *r,int size)
{
	if(isEmpty(*f,*r))
		printf("underflow\n");
	else
	{
		*f=(*f+1)%size;
		return queue[*f];
	}
}
void display(int queue[],int f,int r,int size)
{
	int i;
	i=f+1;
	printf("i=%d\n",i);
	while(i!=(r+1)%size)
	{
		printf("%d at position=%d\n",queue[i],i);
		i=(i+1)%size;
	}
}
void main()
{
	int size=8,queue[size],f=0,r=0,val,i=0,choice;
	do
	{
		printf("\nenter choice\n 1.enqueue\n 2.dequeue\n 3.display\n 4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the value to be inserted");
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