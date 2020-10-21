#include<stdio.h>
#include<conio.h>
int isFull(int r, int n)
{
	if(r == n-1) return 1;
	else return 0;
}
int isEmpty(int front)
{
	if(front==-1) return 1;
	else return 0;
}
int enqueue(int q[],int front,int *rearAdd,int size,int val)
{
	int i;
	if(*rearAdd==-1)
		{
			*rearAdd=0;
			front=0;
			q[*rearAdd]=val;
		}
	else{
			i=*rearAdd;
			while(q[i]>val && i!=-1)
			{
				q[i+1]=q[i];
				i--;
			}
			q[i+1]=val;
			*rearAdd+=1;
		}
}
int dequeue(int q[],int *frontAdd,int *rearAdd)
{
	int val;
	val=q[*frontAdd];
		*frontAdd=*frontAdd+1;
		if(*frontAdd==*rearAdd+1)
		{
			*frontAdd=-1;
			*rearAdd=-1;
		}
		printf("Deleted value is=%d\n",val );
}
int display(int q[], int front, int rear)
{
	if(isEmpty(front)){
	…