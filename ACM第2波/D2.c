#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
long long int x1=0,x2=0,y1=0,y2=0,sum=0;
scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
long long int a=0,b=0;
if(x2-x1>=0)
a=x2-x1;
else a=x1-x2;
if(y2-y1>=0) 
b=y2-y1;
else b=y1-y2;
if(x1==x2&&y1==y2)
printf("0");
else if(a>=b)

     printf("%lld",a);

else 

     printf("%lld",b);

system("pause");
return 0;
}
