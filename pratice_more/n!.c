#include<stdio.h>
#include<math.h>
main()
{int n,i,a,b,c;

   // scanf("%d",&n);
   
    for(i=100;i<=999;i++)
{a=(i/100)*(i/100)*(i/100);
b=(i%10)*(i%10)*(i%10);
c=(i/10%10)*(i/10%10)*(i/10%10);
n=i;
    if(n=a+b+c)
     printf("%d\n",n);
   

}
   
  system("pause");
   return 0;
       
       
       
       
       
  /* printf("%d",153%10);
   
  system("pause");*/
           }
