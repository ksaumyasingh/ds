#include<stdio.h>
void main()
{
	int a[40],b[40],i,m,diff,n;
	printf("enter the no. of element be entered\n");
	scanf("%d",&n);
	printf("enter the elements\n");	
		for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	m=a[0];
    for(i=1;i<=n-1;i++)
		if(m>a[i])
			m=a[i];
	if(m<10)
		diff=10-m;
	else
	{
		printf("smallest all element of array is already greater than 10\n %d",m);
	    return;
	}
	printf("new array elements after increasing by %d\n",diff);
	for(i=0;i<=n-1;i++)
	{
		b[i]=a[i]+diff;
		printf("%d ",b[i]);
	}
}
	
	