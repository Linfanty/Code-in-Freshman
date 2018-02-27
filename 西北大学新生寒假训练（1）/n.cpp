#include<stdio.h>
#include<string.h>
int main()
{
    __int64 a[21][21];
    int i,j,m,n;
    memset(a,0,sizeof(a));//首先全部初始化为0
    for(i=0;i<=20;i++)
        a[i][0]=1;//当n为0的时候无论吗取何值都是1
    for(i=1;i<=20;i++)
        for(j=i;j<=20;j++)
            a[j][i]=a[j-1][i]+a[j][i-1];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        printf("%I64d\n",a[m][n]);
    }
    return 0;
}
