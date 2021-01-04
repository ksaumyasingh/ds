#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int isFull(int f,int r,int size)
{
	if(f==r+1||(f==0&&r==size-1))
		return 1;
	else
		return 0;
}
int isEmpty(int r,int f)
{
	if(r==-1||f==-1)
		return 1;
	return 0;
}
void enqueueFromRare(int queue[],int *f,int *r,int size,int val)
{
	if(isFull(*f,*r,size))
		printf("overflow\n");
	else if(isEmpty(*r,*f))
	{
		*r=*f=0;
		queue[*r]=val;
		printf("enqueue=%d,position=%d f=%d\n",queue[*r],*r,*f);
	}
	else  
	{
		if(*r==size-1)
			*r=0;
		else
			*r=*r+1;
		queue[*r]=val;
		printf("enqueue=%d,position=%d f=%d\n",queue[*r],*r,*f);
	}	
}
void enqueueFromFront(int queue[],int *f,int *r,int size,int val)
{
	if(isFull(*f,*r,size))
		printf("overflow\n");
	else if(isEmpty(*r,*f))
	{
		*r=*f=0;
		queue[*r]=val;
		printf("enqueue=%d,position=%d\n",queue[*r],*r);
	}
	else
	{
		if(*f==0)
		{
			*f=size-1;
		}
		else
		{
			*f=*f-1;
		}
		queue[*f]=val;
		printf("enqueue=%d,position=%d\n",queue[*f],*f);
	}
}
int dequeueFromFront(int queue[],int *f,int *r,int size)
{
	if(isEmpty(*r,*f))
		printf("underflow\n");
	else
	{
		if(*f==size-1)
		{
			*f=0;
			return queue[size-1];
		}
		else
		{		
			*f=*f+1;
			return queue[*f-1];
		}
	}
}
int dequeueFromRare(int queue[],int *f,int *r,int size)
{
	if(isEmpty(*r,*f))
		printf("underflow\n");
	else
	{
		if(*r==0)
		{
			*r=size-1;
			return queue[0];
		}
		else
		{
			*r=*r-1;
			return queue[*r+1];
		}
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
	int size=5,queue[size],f=-1,r=-1,val,i=0,choice;
	do
	{
		printf("enter choice\n 1.enqueue from rare\n 2.dequeue from front\n 3.display\n 4.enqueue from front\n 5.dequeue from rare\n 6.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the value to be inserted\n");
					scanf("%d",&val);
					enqueueFromRare(queue,&f,&r,size,val);
					break;
			case 2:
					printf("dequeue element is=%d",dequeueFromFront(queue,&f,&r,size));
					break;
			case 3:
					display(queue,f,r,size);
					break;
			case 4: printf("enter the value to be inserted\n");
					scanf("%d",&val);
					enqueueFromFront(queue,&f,&r,size,val);
					break;
			case 5:
					printf("dequeue element is=%d",dequeueFromRare(queue,&f,&r,size));
					break;
			case 6:
					exit(0);
					break;
			default: printf("wrong choice");
		}
		i++;
	}
	while(1);
}