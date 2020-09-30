#include<stdio.h>
void main()
{
	int array[40],i,n,j,k,temp,array1[21],m;
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the array of size %d\n",n);
	for(j=0;j<=n-1;j++)
	scanf("%d",&array[j]);/*
	printf("output\n");
	for(j=0;j<=n-1;j++)
		printf("%d\n",array[j]);*/
	

	printf("enter the integer value i between 0<=i<%d\n",n-1);
	scanf("%d",&i);
	m=0;
	for(j=i+1;j<=n-1;j++)
	{
		array1[m]=array[j];
		m++;
	}
	printf("output\n");
	for(j=0;j<=m-1;j++)
		printf("%d\n",array1[j]);
	
	
	for(j=0;j<=i-1;j++)
		for(k=0;k<=i-j-1;k++)
		{
			if(array[k]>array[k+1])
			{
				temp=array[k];
				array[k]=array[k+1];
				array[k+1]=temp;
			}
		}

	for(j=0;j<=m-1;++j)
		for(k=j+1;k<m;++k)
		{
			if(array1[j]<array1[k])
			{
				temp=array1[j];
				array1[j]=array1[k];
				array1[k]=temp;
			}
		}
	
	printf("output\n");
	for(j=0;j<=m-1;j++)
		printf("%d ",array1[j]);
	printf("output\n");
	for(j=0;j<=i;j++)
		printf("%d ",array[j]);
	for(j=0;j<=m-1;j++)
		printf("%d ",array1[j]);
}
	
	
	