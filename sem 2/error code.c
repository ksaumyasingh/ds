#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
void push(char *[],int *,char *);
char * pop(char *[],int *);
int isEmpty(int);
int isFull(int);
int isOperator(char);
void main()
{
	int top=-1,d,i,j=0,temp;
	char expr[20],expr1[20],*op1,*stack[MAXSIZE];
	char *op2,*opr;
	char val;
	printf("enter the prefix expression elements\n");
	scanf("%s",expr1);
	printf("string=%s\n",expr1);
	d=strlen(expr1);
	printf("%d\n",d);
	for(i=d-1;i>=0;i--)
	{
		expr[j]=expr1[i];
		j++;
	}
	expr[j]='\0';
	printf("reversed string=%s\n",expr);
	for(i=0;i<=d-1;i++)
	{
		if(isOperator(expr[i]))
		{
			//printf("poped element=%d\n",pop(stack,&top));
			op2=pop(stack,&top);
			printf("copy op2[0]=%s\n",op2);
			op1=pop(stack,&top);
			printf("copy op1[0]=%s\n",op1);
			strcat(op2,op1);
			strcat(op2,&expr[i]);
			strcat(op2,"\0");		
			push(stack,&top,op2);
		}	
		else
		{
			//strcat(*op2,expr[i]);
			push(stack,&top,&expr[i]);
		}
	}
	printf("postfix=%s\n",*op2);
	
}
void push(char *stack[],int *top,char *op2)
{
	if(isFull(*top))
	{
		printf("stack overflow");
	}
	(*top)++;
	stack[*top]=op2;
	printf("pushed op2[%d]=%c\n",*top,*stack[*top]);	
}
char * pop(char *stack[],int *top)
{
	if(isEmpty(*top))
	{
		return 0;
	}
	(*top)--;
	printf("poped element is %s\n",stack[(*top)+1]);
	return stack[(*top)+1];
}
int isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return 1;
	return 0;
}
int isEmpty(int top)
{
	if(top==-1)
		return 1;
	return 0;
}
int isFull(int top)
{
	if(top>=MAXSIZE-1)
		return 1;
	return 0;
		
}
