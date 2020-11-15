#include<stdio.h>
#include<conio.h>
void main()
{
	int i,num,n,first,last,middle;
	printf("enter the no. of elements to be entered\n");
	scanf("%d",&n);
	printf("enter a shorted array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	printf("enter a number to  be checked/n");
	scanf("%d",&num);
	first=0;
	last=n;
	while(last>=first)
	{
		middle=(first+last)/2;
		if(num==a[middle])
		{
			printf("element found at position %d /n",middle+1);
		    return;
		}
		else if(num>=a[middle])
				first=middle+1;
			else
				last=middle-1;
	}
}
		