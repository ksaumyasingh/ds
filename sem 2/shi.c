#include<stdio.h>
int main() {
int i, n, a[20], j, k, temp=0;
        printf("Enter the size of array\n");
        scanf("%d", &n);
 
        printf("Enter the elements of array \n");
        for (i = 0; i < n; ++i)
       scanf("%d", &a[i]);
       
  printf("enter the number till you want ascending order after descending order \n");
  scanf("%d",&i);
 
  for(j=0;j<=i;j++)
  {
      for(k=j+1;k<=i;k++)
      {
          if(a[j]>a[k])
          {
              temp=a[j];
              a[j]=a[k];
              a[k]=temp;
          }
      }
  }
  for(j=i+1;j<n;j++)
  {
      for(k=j+1;k<n;k++)
      {
          if(a[j]<a[k])
          {
              temp=a[j];
              a[j]=a[k];
              a[k]=temp;
          }
      }
  }
  printf("the array");
  for(j=0;j<n;j++)
    printf("%d",a[j]);
 
return 0;
}