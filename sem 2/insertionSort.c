#include<stdio.h>
void insertionSort(int a[],int n)
{
	int i,j,v;
	for(i=1;i<=n-1;i++)
	{
		v=a[i];
		j=i;
		while(j>=1&&a[j-1]>v)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=v;
	}
}
void main()
{
	int a[90],n,i;
	printf("enter the no. of element be entered\n");
	scanf("%d",&n);
	printf("enter the elements\n");	
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	insertionSort(a,n);
	printf("sorted list is\n");
    for(i=0;i<=n-1;i++)
        printf("%d\n",a[i]);
}