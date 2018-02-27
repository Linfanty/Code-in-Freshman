#include<stdio.h>
#include<string.h>
int main()
{int i,j;
    long long int a,b,sum=0;
scanf("%lld %lld",&a,&b);
sum=a*(b/5)+(b%5)*(a/5);
if(((a%5)+b%5)>4)
sum=sum+(a%5)+(b%5)-4;
/*for(i=1;i<=a;i++)
for(j=1;j<=b;j++)
{if((i+j)%5==0)
sum++;

}    
  */  
printf("%lld",sum);
system("pause");    
return 0;    
}
