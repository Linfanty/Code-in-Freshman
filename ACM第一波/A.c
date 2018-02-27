#include<stdio.h>
#include<string.h>
int main()
{
int k,c[105],n,sum=0;
int i,j,d[105];
memset(c,0,sizeof(c));
memset(d,-1,sizeof(d));
scanf("%d",&n);
for(i=1;i<=n;i++)
{scanf("%d",&c[i]);
sum=sum+c[i];
}
k=sum/(n/2);
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
{
if(d[i]==0)
break;
if(d[j]==0)
continue;
if(c[i]+c[j]==k)
{printf("%d %d\n",i,j);
d[j]=0;
break;
}
}

system("pause");    
return 0;    
}
