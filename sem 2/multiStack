#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct multistack{
	int *array;
	int top_A;
	int top_B;
	int size;
}ms;
void push_A(ms *stack)
{
	int val;
	//if(isFull(*(stack)))
	//	printf("stack overflow");
	//else
	
		printf("enter the value to be pushed\n");
		scanf("%d",&val);
		printf("%d",val);
		(stack->top_A)++;
		printf("top_a=%d\n",stack->top_A);
		stack->array[stack->top_A]=val;
	
}
void push_B(ms *stack)
{
	char val;
	//if(isFull(*(stack)))
	//	printf("stack overflow");
	//else
	{
		printf("enter the value to be pushed\n");
		scanf("%c",&val);
		(stack->top_B)++;
		stack->array[stack->top_B]=(int)val;
	}
}
int pop_A(ms *stack)
{
	(stack->top_A)--;
	return stack->array[stack->top_A+1];
}
char pop_B(ms *stack)
{
	(stack->top_B)--;
	return (char)stack->array[stack->top_B+1];
}
void display_A(ms *stack)
{
	int i;
	for(i=0;i<stack->top_A;i++)
		printf("%d",stack->array[i]);
}
void display_B(ms *stack)
{
	int i;
	for(i=stack->size-1;i>stack->top_B;i--)
		printf("%c",(char)stack->array[i]);
}
int isFull(ms *stack)
{
	if(stack->top_B=stack->top_A+1)
		return 1;
	return 0;
}
int isEmpty(ms *stack)
{
	if(stack->top_A==-1&&stack->top_B==stack->size)
		return 1;
	return 0;

}
void cleanUp(ms *stack)
{
	if(stack->array != NULL)
	{
		free(stack->array);
		stack->array=NULL;
	}
	if(stack!= NULL)
	{
		free(stack);
		stack=NULL;
	}
	
}
void main()
{
	int size_A,size_B,n,i=0;
	ms *stack=(ms *)malloc(sizeof(ms)*1);
	printf("enter the size of character array and integer array");
	scanf("%d%d",&size_A,&size_B);
	stack->size=size_A+size_B;
	stack->top_A=-1;
	stack->array=(int *)malloc(sizeof(int)*(stack->size));
	stack->top_B=stack->size;
	
	do
	{
		printf("\n1.push_A,2.push_B,3.pop_A,4.pop_B,5.dispay_A,6.dispay_B,7.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
					push_A(stack);
					break;
			case 2:
					push_B(stack);
					break;
			case 3:
					printf("poped element=%c/n",pop_A(stack));
					break;
			case 4:
					printf("poped element=%c/n",pop_B(stack));
					break;
			case 5:
					display_A(stack);
					break;
			case 6:
					display_B(stack);
					break;
			case 7:
					cleanUp(stack);
					exit(0);
					break;
		}
		i++;
	}
	while(1);
}

	
	