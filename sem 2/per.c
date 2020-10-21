#include<stdio.h>
void main()
{
int i=0,j=0,k=0,l=0;
for (i=0;i<4;i++)
for(j=0;j<4;j++)
{

if (j==i) continue;

for(k=0;k<4;k++)

{

if ((k==j) || (k==i)) continue;

for(l=0;l<4;l++)

{

if ((l==i) || (l==j) || (l==k)) continue;

// i,j,k,l is a permutation
printf("%d%d%d%d\n",i,j,k,l);
}

}

}

}
