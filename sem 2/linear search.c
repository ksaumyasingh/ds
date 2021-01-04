#include<stdio.h>
#include<conio.h>
int linearSearch(int [],int n);
void main()
{
	int i,n,array[90],choice,flag=0;
	printf("enter the no. of elements to be entered\n");
	scanf("%d",&n);
	printf("enter a array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&array[i]);
	flag=linearSearch(array,n);
	if(flag)
		printf("element found at position %d \n",flag);
	else
		printf("element not present\n");
}
int linearSearch(int array[],int n)
{
	int num,i;
	printf("enter a number to  be checked\n");
	scanf("%d",&num);
	for(i=0;i<=n-1;i++)
	{
		if(num==array[i])
		{
		    return (i+1);
		}
	}
	return 0;
}


