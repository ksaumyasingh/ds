#include<stdio.h>
void main()
{
	int a[90],n,i,j,temp,f=0;
	printf("enter the no. of element be entered\n");
	scanf("%d",&n);
	printf("enter the elements\n");	
		for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
    for(i=0;i<=(n-1)/2;i++)
	{
		for(j=0;j<=(n-1)/2-i;j+=2)
		{
			if(a[j]>a[j+2])
			{
				temp=a[j];
				a[j]=a[j+2];
				a[j+2]=temp;
			}
		}
	}
	for(i=0;i<=(n-1)/2;i++)
	{
		for(j=1;j<=(n)/2-i;j+=2)
		{
			if(a[j]<a[j+2])
			{
				temp=a[j];
				a[j]=a[j+2];
				a[j+2]=temp;
			}
		}
	}
	printf("sorted list is\n");
    for(i=0;i<=n-1;i++)
        printf("%d\n",a[i]);
}	
     	
				