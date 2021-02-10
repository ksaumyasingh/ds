#include<stdio.h>
void selectionSort(int a[],int n)
{
	int p,j,temp,m,i;
	for(i=0;i<=n-1;i++)
	{
		m=a[i];
		p=i;
		for(j=i;j<=n-1;j++)
		{
			if(m>a[j])
			{
				m=a[j];
				p=j;
			}
		}
		if(p!=i)
		{
			temp=a[i];
			a[i]=a[p];
			a[p]=temp;
		}
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
	
	selectionSort(a,n);
	printf("sorted list is\n");
    for(i=0;i<=n-1;i++)
        printf("%d\n",a[i]);
}