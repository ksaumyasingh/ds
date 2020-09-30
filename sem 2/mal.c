#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int n,*p,sum,i;
	char r[10],*j[30];
	printf("enter the no of students");
	scanf("%d",&n);
	p=(int *)malloc(n*(sizeof(int)));
	for(i=0;i<=n-1;i++)
	{
		printf("enter the roll no. of %dth sudent",i+1);
		scanf("%d",p+i);
		printf("enter the name");
		scanf("%s",r);
		j[i]=(char *)malloc((strlen(r)+1)*sizeof(char));
		strcpy(j[i],r);
		
	}
	for(i=0;i<=n-1;i++)
	{
		printf(" student %d =%s,%d",i+1,j[i],*(p+i));
	}
	free(p);
	for(i=0;i<=n-1;i++)	
	free (j[i]);
}