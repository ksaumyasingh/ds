#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
void push(char *[],int *,char *);
char * pop(char *[],int *);
int isEmpty(int);
int isFull(int);
int isOperator(char);
int main()
{
	int top=-1,d,i,j=0,temp;
	char expr[20],expr1[20],*stack[MAXSIZE];
	char *op2,*opr,*op1;
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
            char * newStr;
			//printf("poped element=%d\n",pop(stack,&top));
			op2=pop(stack,&top);
			printf(" op2=%s\n",op2);
			op1=pop(stack,&top);
            printf(" op1=%s\n",op1);
            newStr =(char*)malloc(sizeof(char)*(strlen(op1)+2+strlen(op2)));
            sprintf(newStr, "%s%s%c\0",op2,op1,expr[i]);
			push(stack,&top,newStr);
            
            if(op2)
                free(op2);
            if(op1)
                free(op1);
		}	
		else
		{
            char * Str = (char*)malloc(sizeof(char)*2);
			sprintf(Str, "%c\0",expr[i]);
            //*Str = expr[i];
			push(stack,&top,Str);
		}
	}
    op2=pop(stack,&top);
    printf(" postfix=%s\n",op2);
    if(op2)
        free(op2);
    return 0;
}
void push(char *stack[],int *top,char *op2)
{
	if(isFull(*top))
	{
		printf("stack overflow");
	}
	(*top)++;
	stack[*top]=op2;
	printf("\npushed op2[%d]=%c\n",*top,*stack[*top]);
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
