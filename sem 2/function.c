#include<stdio.h>
void bubblesort(int [],int);
void inseartionsort(int [],int);
void selectionsort(int [],int);
	
void main()
{
	int a[30],n,i,a1[30],a2[30];
	printf("enter the no. of elements to be entered\n");
	scanf("%d",&n);
	printf("enter a array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	printf("enter a array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a1[i]);
	printf("enter a array of %d elements\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a2[i]);
	bubblesort(a,n);
	inseartionsort(a1,n);
	selectionsort(a2,n);
}
void bubblesort(int a[],int n)
{
    int c, d, t,k=0,i;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (a[d] > a[d+1])
      {
        /* Swapping */
 
		t = a[d];
        a[d]   = a[d+1];
        a[d+1] = t;
		k++;
		printf(" value of k is %d\n",k);
      }
    }
  }
printf("sorted list using bubble sort after changing %d times\n",k);
    for(i=0;i<=n-1;i++)
        printf("%d\n",a[i]);
}
void inseartionsort(int a1[],int n)
{
int k=0,j,i,temp;
for (i = 1 ; i <= n - 1; i++)

    {

	    j = i;

            while ( j > 0 && a1[j-1] > a1[j])

            {	        
				k=k+1;
				printf("vaue of k is %d\n",k);
                temp     = a1[j];

                a1[j]   = a1[j-1];

                a1[j-1] = temp;

                j--;
				

            }

    }

    printf("Sorted list in inseartionsort after swapping %d times\n",k);

    for (i = 0; i <= n - 1; i++)

    {

        printf("%d\n", a1[i]);

    }
}
void selectionsort(int a2[],int n)
{
	int c,d,position,t,k=0;
	
		  for (c = 0; c < (n - 1); c++)
  {
    position = c;

    for (d = c + 1; d < n; d++)
    {
      if (a2[position] > a2[d])
        position = d;
    }
    if (position != c)
    {
	   k=k+1;
	   printf(" value of k is %d\n",k);
      t = a2[c];
      a2[c] = a2[position];
      a2[position] = t;
	 
    }
  }

  printf("Sorted list in selectionsort and no of swapping is %d\n",k);

  for (c = 0; c < n; c++)
    printf("%d\n", a2[c]);
}