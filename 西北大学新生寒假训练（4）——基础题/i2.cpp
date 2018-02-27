#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n,m,i;
    int a[10010],t=0;
    while (~scanf("%d %d",&n,&m))
    {
        t=0;
        memset(a,0,sizeof(a));
        if(n==0&&m==0)
            break;
        n=n*100;
        for(i=0;i<=99;i++)
        {
            if((n+i)%m==0)
                {
                    a[t]=i;
                    t++;
                }
        }
        for(i=0;i<t-1;i++)
            printf("%02d ",a[i]);
        printf("%02d\n",a[t-1]);
    }
    return 0;
}

