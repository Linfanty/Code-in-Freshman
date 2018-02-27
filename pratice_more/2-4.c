#include<stdio.h>
#include<math.h>
int q=0;
int main()
{for(q=1;q<=1000;q++)
                     {int n,count=0;
                     scanf("%d",&n);
                     while(n>1)
                     {
                     if(n%2==1) n=n*3+1;
                     else n/=2;
                     count++;
                     }
printf("%d\n\n",count);
}
for(;;)
;
}
          
