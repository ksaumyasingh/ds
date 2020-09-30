#include<stdio.h>
void main()
{
    int a[90],n,i,j,f=0;
	printf("enter the no. of element to v entered");
	scanf("%d",&n);
	printf("enter the elements");
		for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
    printf("enter the no.to be checked");
	scanf("%d",&j);
	for(i=0;i<=n-1;i++)
	{
		if(a[i]==j)
		{
			printf("element found");
			return;
		}
		
	}
	printf("element not found");
	

		
}   