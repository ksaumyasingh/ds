#include<stdio.h>
#include<math.h>
void main()
{
	int height,n,choice1,choice2,size,i,j,k;
	char tree1[40];
	printf("enter height of tree1\n");
	scanf("%d",&height);
	size=pow(2,height);
	size--;
	printf("size=%d\n",size);
	n=size/2;
	printf("n=%d\n",n);
	printf("enter root element\n");
	scanf("%c",&tree1[0]);
	for(i=0;i<n;i++)
	{
		printf("left child of %d parent exist?1.yes 2.no\n",i);
		scanf("%d",&choice1);
		j=2*i+1;
		if(choice1==1)
		{
			printf("enter left child\n");
			scanf("%c",&tree1[j]);
		}
		else
			tree1[j]=-1;
		printf("right child of %d parent exist?1.yes 2.no\n",i);
		scanf("%d",&choice2);
		k=2*i+2;
		if(choice2==1)
		{
			printf("enter right child\n");
			scanf("%c",&tree1[k]);
		}
		else
			tree1[k]=-1;		
	}
	printf("tree1\n");
	for(i=0;i<=size;i++)
		printf("%c ",tree1[i]);
	

}