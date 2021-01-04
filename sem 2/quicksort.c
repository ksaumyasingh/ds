#include<stdio.h>
#include<conio.h>
void quickshort(int [],int,int);
int partition(int [],int,int);
void main()
{
	int A[20],low,high,n,i;
	printf("\nenter the size of array");
	scanf("%d",&n);
	printf("\nenter array");
	for(i=0;i<=n-1;i++)
		scanf("%d",&A[i]);
	low=0;
	high=n-1;
	quickshort(A,low,high);
	printf("\nshorted array\n");
	for(i=0;i<=n-1;i++)
		printf("%d ",A[i]);
	
}
void quickshort(int A[],int low,int high)
{
	int pivot;
	if(low < high)
	{
		pivot=partition(A,low,high);
		quickshort(A,low,pivot-1);
		quickshort(A,pivot+1,high);
	}
}
int partition(int A[],int low,int high)
{
	int left,right,pivot=A[low],temp;
	left=low;
	right=high;
	while(left<right)
	{
		while(A[left]<=pivot)
			left++;
		while(A[right]>pivot)
			right--;
		if(left<right)
		{
			temp=A[left];
			A[left]=A[right];
			A[right]=temp;
		}
	}
	A[low]=A[right];
	A[right]=pivot;
	return right;
}