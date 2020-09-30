#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
void push(int [],int *,int);
int pop(int [],int *);
int isNum(char);
void toString(int,int []);
int isEmpty(int);
int isFull(int);
int isOperator(char);
int isValidInteger(char []);
void main()
{
	int stack[MAXSIZE],top=-1,val,opr1,opr2,result,d;
	char expr[20];
	while(1)
	{
		printf("enter the posfix expression elements\n");
	    scanf("%s",&expr);
	    //printf("string=%s\n",expr);
		d=strlen(expr);
		if(d==1)
		{
			if(isNum(expr[0]))
			{
					val=atoi(expr);
				   push(stack,&top,val);
			}
			else if(isOperator(expr[0]))
			{
				if(isEmpty(top))
				{
					printf("not enough operends on stack\n");
				}
				else
				{
					opr2=pop(stack,&top);
					if(isEmpty(top))
					{
						val=opr2;
						push(stack,&top,val);
						printf("not enough operends on stack\n");
					}	
					else
					{
						opr1=pop(stack,&top);
						switch(expr[0])
						{
							case '+': 
									result=opr1+(opr2);
									break;
							
							case '-':
									result=opr1-(opr2);
									break;
							
							case '*': 
									result=opr1*(opr2);
									break;
							
							case '/': 
									result=opr1/(opr2);
									break;
							
							case '^':
									result=opr1^(opr2);
									break;
						}
						val=result;
						push(stack,&top,val);
					}
				}
			}
			else
			{
				switch(expr[0])
				{
					case '?':
							toString(top,stack);
							break;
					case '%':
							printf("top most element of stack is %d\n",pop(stack,&top));
							break;
					case '!': exit(0);
					default : printf("can't do anything helpful with that input");
								break;
				}
			}
		}
		else
		{	
			if(isValidInteger(expr))
			{
					val=atoi(expr);
					push(stack,&top,val);
			}
			else
			{
				 printf("can't do anything helpful with that input\n");																	
			
			}
	    }
	}
}
void push(int stack[],int *top,int val)
{
	if(isFull(*top))
	{
		printf("stack overflow");
	}
	(*top)++;
	stack[*top]=val;
	//printf("push %d position=%d\n",val,(*top));
}
int pop(int stack[],int *top)
{
	if(isEmpty(*top))
	{
		return 0;
	}
	(*top)--;
	return stack[(*top)+1];
}
void toString(int top,int stack[] )
{
	int p,i;
	p=top;
	printf("elements of stack is\n");
	for(i=p;i>-1;i--)
		 printf("%d\n",stack[i]);
}
int isNum(char c)
{
	if(c>=48&&c<=57)
		return 1;
	return 0;
	
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
int isValidInteger(char expr[])
{
	int i=0;
	if(expr[0]=='-')
		i=1;
	while(expr[i]!=0)
	{
		if(isNum(expr[i]))
		{
		}
		else
		{
			return 0;
		}
		i++;
	}
	return 1;
}
				
													
									
							
									
