#include<stdio.h>

int main(){
    int num =0,i,j,k,l,count=0;
    for (i=1;i<=6;i++)
    {
        for(j=1;j<i;j++)
        {
            //if (j==i) continue;
            for(k=1;k<j;k++)
            {
                //if ((k==j) || (k==i)) continue;
                for(l=1;l<k;l++)
                {
                    //if ((l==i) || (l==j) || (l==k)) continue;

                        // i,j,k,l is a permutation
                        num = (i)*1000+(j)*100+(k)*10+(l);
                        printf("%d\n", num);
                        count++;

                }
            }
        }
    }
    printf("total %d combinations printed\n",count);
}
