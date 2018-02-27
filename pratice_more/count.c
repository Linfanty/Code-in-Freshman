#include<stdio.h>
#define INF 1000000000
main()
{     long a[10000],t,n,limit;
      long i,j,k,mini;
      char ch;
   // printf("Input limit:\n");
   scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",a[i]/*,(a[i]==\n?" ":"")*/);
    /*选择排序*/
    for(i=0;i<n;i++)
    {mini=i;
       for(j=i+1;j<n;j++)
         if(a[j]<a[mini])
             mini=j;
        t=a[i];a[i]=a[mini];a[mini]=t;
    } 
   /*输出结果*/
   for(i=0;i<n;i++)
       printf("%d",a[i]);
   printf("\n");
   getchar();
}
