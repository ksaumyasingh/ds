#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
void push(char [],int *,char);
char pop(char [],int *);
void main()
{
	int i=0,top=-1;
	char string[40],k,val,j;
	char stack[20];
	printf("enter the sequance of characters\n");
	scanf("%s",string);
	printf("elements poped out\n");
	while(string[i]!='\0')
	{
		if(string[i]=='*')
		{
			k=pop(stack,&top);
			printf("%c ",k);
		}
		else if(string[i]=='#')
			{
				k=pop(stack,&top);
				j=pop(stack,&top);
				printf("%c %c ",k,j);
			}
			else
				{
					val=string[i];
					push(stack,&top,val);
				}
		i++;
	}
	printf("elements left in stack");
	for(i=top;i>-1;i++)
		printf("%c ",stack[i]);
	
}
void push(char stack[],int *top,char val)
{
	(*top)++;
	stack[*top]=val;
	printf("push %c position=%d\n",val,(*top));
}
char pop(char stack[],int *top)
{
	(*top)--;
	printf("poped element is %c\n",stack[(*top)+1]);
	return stack[(*top)+1];
}