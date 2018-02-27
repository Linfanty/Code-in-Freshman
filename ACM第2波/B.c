#include<stdio.h>
#include<string.h>
int main()
{//memset(c,0,sizeof(c));    
long long int n,k=0,i,j;
long long int c[105],mark=0,sum=1;
long long int num=0,first=0,last=0,first1=0,last1=0;    
memset(c,0,sizeof(c)); 

scanf("%lld",&n);

for(i=0;i<n;i++)
scanf("%lld",&c[i]);

for(i=0;i<n;i++)
{if(c[i]==1)
{first=i;
break;
}
}

for(i=n-1;i>0;i--)
{if(c[i]==1)
{last=i;
break;
}
}

if(c[0]==1&&last==0)
printf("1");
else if(c[0]==0&&last==0)
printf("0");

first1=first;
last1=last;

for(i=(first1+1);i<=last1;i++)
{
if(c[i]==1)
k=i-first1;

if(c[i]==1&&c[first1]==1)
{sum=k*sum;
//num=0;
first1=i;
}
if(first1==last1)
break;
}


if(last!=0)
printf("%lld",sum);
system("pause");    
return 0;    
}
