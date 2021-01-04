			//heapsort

#include <stdio.h>
#include <stdlib.h>
void insert(int a[],int item);
void swapping(int *a,int *b);
void heap_sort(int heap[]);
int deletionOfheapRoot(int heap[]);
int main()
{
	int heap[50],i,c,item;
	heap[0]=0;
	do
	{
		printf("\add node?Press 1.Yes else 0");
		scanf("%d",&c);
		if(c==1)
		{
			printf("\nEnter data= ");
			scanf("%d",&item);
			insert(heap,item);
		}
		else
		   break;
	}while(1);
	printf("\ntotal no of elements in heap= %d",heap[0]);
	printf("\nHeap");
	for(i=1;i<=heap[0];i++)
	   	printf("%d  ",heap[i]);
	heap_sort(heap);
	return 0;
}
void heap_sort(int heap[])
{
	int i,ele,n;
	printf("\nSorted heap");
	n=heap[0];
	for(i=0;i<n;i++)
	{
		ele=deletionOfheapRoot(heap);
		printf("%d ",ele);
	}

}
int deletionOfheapRoot(int heap[])
{
	int i,f,k,last,temp,pos,lc;
	if(heap[0]==1)
	   return heap[1];
	last=heap[0];
	temp=heap[1];
	heap[1]=heap[last];
	heap[0]=heap[0]-1;
	k=last-1;
	i=1;
	f=1;
	while(f==1)
	{
		lc=2*i;
		if(lc<=k)
		{
			if(lc+1<=k)
			{
				if(heap[lc]>heap[lc+1])
				  	pos=lc;
				else
					pos=lc+1;
				if(heap[pos]>heap[i])
				   	swapping(&heap[pos],&heap[i]);
				else
				  	f=0;
			}
			else
			{
				if(heap[lc]>heap[i])
				  	swapping(&heap[lc],&heap[i]);
				else
				 	f=0;
			}
		}
		else
		 	f=0;
	}
	return temp;
}
void insert(int heap[],int item)
{
	int f,i,parent;
	if(heap[0]==0)
	{
		heap[0]=1;
		heap[1]=item;
	}
	else
	{
		heap[0]=heap[0]+1;
		i=heap[0];
		heap[i]=item;
		f=1;
		while(f==1)
		{
			parent=i/2;
			if(parent>=1)
			{
				if(heap[parent]<heap[i])
				{
					swapping(&heap[parent],&heap[i]);
					i=parent;
				}
				else
					f=0;

			}
			else
			   	f=0;
	 	}
	}
}
void swapping(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
