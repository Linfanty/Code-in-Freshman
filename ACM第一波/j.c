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
printf("%lld %lld\n",c[1]-c[0],c[n-1]-c[0]);
for(i=1;i<n-1;i++)
printf("%lld %lld\n",c[i]-c[i-1]<c[i+1]-c[i]?c[i]-c[i-1]:c[i+1]-c[i],
c[n-1]-c[i]>c[i]-c[0]?c[n-1]-c[i]:c[i]-c[0]);
printf("%lld %lld\n",c[n-1]-c[n-2],c[n-1]-c[0]);



//printf("%lld",sum);
system("pause");    
return 0;    
}
