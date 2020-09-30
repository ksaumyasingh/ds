#include <stdio.h>
#include<stdlib.h>
void push(int stack[],int *top,int size,int value);
int isFull(int top,int size);
void pop(int stack[],int *top);
int isEmpty(int top);
void display(int stack[],int *top);


int main()
{
int top=-1,stack[20],size=20,choice,val;
do
    {
        printf("\n\npress 1.Push 2.Pop 3.display 4. Exit");
        scanf("%d",choice);
        switch(choice)
        {
            case 1:
             printf("enter the value to be inserted");
             scanf("%d",val);
             push(stack,&top,size,val);
             break;
            case 2:
             pop(stack,&top);
             break;
            case 3:
             display(stack,top);
            default:
              exit;
        }
    }while();
   
    return 0;
}
void push(int stack[],int size,int *top,int val)
{
    if(isfull(*top,size))
    {
        printf("stack is full");
    }
    else
    {
     *top = *top + 1;
     stack[*top]=val;
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
        *top=*top-1;
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
void display(int stack[],int *top)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}
