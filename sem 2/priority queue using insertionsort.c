                          //priority queue using insertionsort
						  
#include<stdio.h>
void main()
{
	int *a,i,size,element,temp;
	printf("enter the size of priority queue");
	scanf("%d",&size);
	for(i=0;i<=size-1;i++);
	{
		printf("enter the queue elements");
		scanf("%d",&element);
		if(i==0)
			*(a+0)=element;
		else
		{
			for(j=i;j>0;j--)
				if(*(a+j)>element)
				{
					*(a+(--j))=element;
				}
			for(j=i;j<=size-1;j++)
				if(*(a+j)<element)
				{
					*(a+(++j))=element;
				}			
		}
		for(j=p;j<=size-2-i;j++)
			{
				a[i]=queue[i+1];
			}
		printf("deleted element %d\n",m);
	}
}