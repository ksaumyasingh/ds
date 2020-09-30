#include<stdio.h>
#include<conio.h>
void main()
{
	int i,num,n,a[90];
	printf("enter the no. of elements to be entered\n");
	scanf("%d",&n);
	printf("enter a array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	printf("enter a number to  be checked\n");
	scanf("%d",&num);
	for(i=0;i<=n-1;i++)
		if(num==a[i])
		{
			printf("element found at position %d \n",i+1);
		    return;
		}
}		