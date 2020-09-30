#include<stdio.h>
void main()
{
	int size,queue[30],i,m,j,p;
	printf("enter the size of queue");
	scanf("%d",&size);
	printf("enter the queue");
	for(i=0;i<=size-1;i++)
		scanf("%d",&queue[i]);
	//searching for max priority elements i.e finding min num
	for(j=0;j<=size-1;j++)
	{
		m=queue[0];
		p=0;
		for(i=1;i<=size-1-j;i++)
		{
			if(queue[i]<m)
			{
				m=queue[i];
				p=i;
			}
		}
		printf("mth element is %d,p0sition =%d \n",m,p);
		//deleting min elements
			for(i=p;i<=size-2-j;i++)
			{
				queue[i]=queue[i+1];
			}
		printf("deleted element %d\n",m);
	}
}
