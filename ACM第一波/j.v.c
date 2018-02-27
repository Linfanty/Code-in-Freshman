#include<stdio.h>
#include<string.h>
int main()
{long int n,i,j; 
long long int c[100002];
memset(c,0,sizeof(c));
scanf("%ld",&n);
for(i=0;i<n;i++)
{scanf("%lld",&c[i]);
}
for(i=1;i<n;i++)
printf("%lld %lld",c[i]-c[i-1],c[n]-c[i]>c[i]-c[0]?c[n]-c[i]:c[i]-c[0]);




//printf("%lld",sum);
system("pause");    
return 0;    
}
