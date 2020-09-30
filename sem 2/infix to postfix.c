#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
void push(char [],int *,char);
char pop(char [],int *);
int isEmpty(int);
int isFull(int);
int isOperator(char);
int checkPrecedence(char);
void main()
{
	int top=-1,d,i,j=0,k=0;
	char expr[20],output[20],stack[MAXSIZE],val,x;
	printf("enter the infix expression elements\n");
	scanf("%s",expr);
	printf("string=%s\n",expr);
	d=strlen(expr);
	printf("%d\n",d);
	for(i=0;i<=d-1;i++)
	{
		if(expr[i]=='(')
		{
			val=expr[i];
			printf("val=%c\n",val);
			push(stack,&top,val);
		}
		else if(expr[i]==')')
		{
			
			do
			{
				x=stack[top];
				printf("x=%c",x);
				if(x=='(')
				{
					pop(stack,&top);
					break;
				}
				else
				{
					output[j]=pop(stack,&top);
					printf("output=%s,position=%d\n",output,j);
					j++;
				}
					k++;
			}
				while(1);
				
		}
			else if(isOperator(expr[i]))
			{
				if(isOperator(stack[top]))
				{
					printf("%d=expr,%d=inStack\n",checkPrecedence(expr[i]),checkPrecedence(stack[top]));
					if(checkPrecedence(expr[i])<=checkPrecedence(stack[top]))
					{
						output[j]=pop(stack,&top);
						printf("output=%s,position=%d\n",output,j);
						j++;
						val=expr[i];
						printf("val=%c\n",val);
						push(stack,&top,val);
						
					}
					else
					{
						val=expr[i];
						printf("val=%c\n",val);
						push(stack,&top,val);
					}
				}
				else
				{
					val=expr[i];
					printf("val=%c\n",val);
					push(stack,&top,val);
				}
			}
			else
			{
				output[j]=expr[i];
				printf("output=%s,position=%d\n",output,j);
				j++;
			}
			printf("i=%d\n",i);
			
	}
	for(k=top;k>=0;k--)
	{
		if(stack[k]==')'||stack[k]=='(')
		{
			printf("expression is incorrect\n");
			return;
		}
		output[j]=stack[k];
		j++;
	}
	output[j]='\0';
	printf("postfix=%s\n",output);
	
}
void push(char stack[],int *top,char val)
{
	if(isFull(*top))
	{
		printf("stack overflow");
	}
	(*top)++;
	stack[*top]=val;
	printf("push %c position=%d\n",val,(*top));
}
char pop(char stack[],int *top)
{
	if(isEmpty(*top))
	{
		return 0;
	}
	(*top)--;
	printf("poped element is %c\n",stack[(*top)+1]);
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
int checkPrecedence(char c)
{
	if(c=='^')
		return 3;
	if(c=='*'||c=='/')
		return 2;
	if(c=='+'||c=='-')
		return 1;
}