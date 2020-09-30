#include<stdio.h>
#include<stdlib.h>
int isEmpty(int r)
{
	if(r==-1)
		return 1;
	return 0;
}
void enqueue(int queue[],int *f,int *r,int size,int val)
{
		*r=*r+1;
		queue[*r]=val;
		printf("enqueue=%d,position=%d\n",queue[*r],*r);	
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
void main()
{
	int f=0,r=-1,calling_queue[100],ideal_queue[100],val,i,N,fi=0,ri=-1,value,time=0;
	printf("enter the size of calling order/ideal order\n");
	scanf("%d",&N);
	if(N>=1&&N<=100)
	{
		printf("enter ideal order");
		for(i=0;i<=N-1;i++)
		{
			scanf("%d",&value);
			enqueue(ideal_queue,&fi,&ri,N,value);
		}
		printf("enter calling order");
		for(i=0;i<=N-1;i++)
		{
			scanf("%d",&val);
			enqueue(calling_queue,&f,&r,N,val);
		}
		for(i=f;fi<=ri;i++)
		{
			if(calling_queue[f]!=ideal_queue[fi])
			{
				val=dequeue(calling_queue,&f,&r,N);
				enqueue(calling_queue,&f,&r,N,val);
				time++;
			}
			else
			{
				printf("dequeue element of calling queue is %d\n",dequeue(calling_queue,&f,&r,N));
				printf("dequeue element of ideal queue is %d\n",dequeue(ideal_queue,&fi,&ri,N));
				time++;
			}
		}	
		printf("time taken=%d",time);
	}
	else
	{
		printf("not valid input");
	}
}