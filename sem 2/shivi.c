#include <stdio.h>
#include<stdlib.h>
void push(int [],int ,int* ,int );
int isFull(int top,int size);
void pop(int stack[],int *top);
int isEmpty(int top);
void display(int stack[],int top);
int main()
{
int top=-1,stack[20],size=20,choice,val;
do
    {
        printf("\n\npress 1.Push 2.Pop 3.display 4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             printf("enter the value to be inserted\n");
             scanf("%d",&val);
             push(stack,size,&top,val);
             break;
            case 2:
             pop(stack,&top);
             break;
            case 3:
             display(stack,top);
			 break;
            case 4:
              exit(0);
        }
    }
while(1);
   
    return 0;
}
void push(int stack[],int size,int *top,int val)
{
    if(isFull(*top,size))
    {
        printf("stack is full");
    }
    else
    {
     *top = (*top)+ 1;
     stack[*top]=val;
	 printf("push=%d,position=%d\n",stack[*top],(*top));
    }
}
int isFull(int top,int size)
{
    if(top==(size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pop(int stack[],int *top)
{
    int element_deleted;
    if(isEmpty(*top))
    {
        printf("stack empty");
    }
    else
    {
        element_deleted=stack[*top];
		printf("element deleted=%d\n",element_deleted);
        (*top)=(*top)-1;
    }
}
int isEmpty(int top)
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(int stack[],int top)
{
	int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
