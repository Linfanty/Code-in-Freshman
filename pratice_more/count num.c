#include "stdio.h" 
main() 
{int a[20],i,j,n,k=1;
for(i=0;i<=19;i++) 
{scanf("%d",&a[i]);}
for(i=0;i<19;i++)
{ 
for(j=i+1;j<=19;j++)
{ 
if(a[j]==a[i]) 
{n=0;break;} 
if(a[j]!=a[i]) 
n=1; 
}
if(n==1) k++;
}
printf("%d\n",k);
getchar();
}
