#include<stdio.h>
#include<conio.h>
void heapinsert(int heap[],int item)
{
	int flag=1,present,last,i,temp;
	if(heap[0]==0)
	{
		heap[0]=1;
		heap[1]=item;
	}
	else
	{
		heap[0]=heap[0]+1;
		last=heap[0];
		heap[last]=item;
		i=last;
		while(flag==1)
		{
			present=i/2;
			if(present>=1)
				if(heap[present]<heap[i])
				{
					temp=heap[present];
					heap[present]=heap[i];
					heap[i]=temp;
					i=present;
				}
				else
					flag=0;
			else
				flag=0;
		}
	}
}
int deletion(int heap[],int size)
{
	int temp,i=1,present,flag=1,j=1,del;
	del=heap[1];
	while(j<=size)
	{
		i=j;
		j=(2*i)+1;
	}
	heap[1]=heap[i];
	printf("\nheap[1]=%d",heap[1]);
	heap[0]=heap[0]-1;
	last=heap[0];
	heap[last]=item;
	i=last;
	while(flag==1)
	{
		present=i+1;
		if(present<=size)
		{
			if(heap[present]>heap[i])
			{
				temp=heap[present];
				heap[present]=heap[i];
				heap[i]=temp;
				i=present;
				printf("temp=%d",temp);
			}
		}
		else
			flag=0;
	}
	return del;
}
void main()
{
	int heap[30],item,choice,size,del;
	heap[0]=0;
	printf("enter the size of heap");
	scanf("%d",&size);
	do
	{
		printf("enter the item");
		scanf("%d",&item);
		heapinsert(heap,item);
		printf("press 1 to enter more else 0 ");
		scanf("%d",&choice);
	}
	while(choice);
	printf("heap");
	for(int i=1;i<=size;i++)
		printf("\n %d ",heap[i]);
	del=deletion(heap,size);
	printf("\nheap after deletion of %d element\n",del);
	for(int i=1;i<=size-1;i++)
		printf("\n %d ",heap[i]);
	
	
}