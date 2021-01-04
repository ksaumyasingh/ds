#include<stdio.h>
void bubbleSort(int a[],int n)
{
	int i,j,temp;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<=i-1;j++) 
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void main()
{
	int a[90],n,i,f=0;
	printf("enter the no. of element be entered\n");
	scanf("%d",&n);
	printf("enter the elements\n");	
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
    /*for(i=n-1;i>=0;i--)
	{
		for(j=0;j<=i-1;j++)  
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}*/
	bubbleSort(a,n);
	printf("sorted list is\n");
    for(i=0;i<=n-1;i++)
        printf("%d\n",a[i]);
}	
				