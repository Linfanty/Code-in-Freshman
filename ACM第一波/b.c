#include<stdio.h>
int main()
{
int t,s,x;
int i,j=0;
scanf("%d %d %d",&t,&s,&x);
if(x==t)
printf("YES");
else 
{x=(t+s);
if(x==(t+s))
printf("YES");
}
while(x>t)
    {if(x==t)
    {printf("YES");
    break;
    }
    else if(j==0)
    t++;
    else if(j==1)
    {t=t-1+s;
     j=0;
     continue;}
    j++;
}
if(x==t)
printf("YES");
if(x<t)
printf("NO");
system("pause");    
return 0;    
}
