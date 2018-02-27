#include<stdio.h>
#include<string.h>
int main()
{long int n,i;
long long int x,sum=0;
scanf("%ld %lld",&n,&x);
if(x==1)
printf("1");
else
{
if(n>=x)
sum=2;
for(i=2;i<=n;i++)
{
if(x%i==0&&x/i<=n&&x!=i)
sum=sum+1;
}
//if()
printf("%lld",sum);

}   
    
system("pause");
return 0;    
}
