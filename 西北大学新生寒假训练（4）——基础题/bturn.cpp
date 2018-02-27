#include<stdio.h>
__int64 cuobai[15],da[27];
__int64 c(int n,int m)//从n个中取m个的种数
{
    __int64 cc=1,in=1;
    for(int i=n;i>=n-m+1;i--)
    cc*=i;
    for(int i=2;i<=m;i++)
    in*=i;
    return cc/in;
}
void init()
{
    cuobai[1]=0; cuobai[2]=1;
    for(int i=3;i<=13;i++)//求i个人错排的种数
    cuobai[i]=(cuobai[i-1]+cuobai[i-2])*(i-1);
    da[1]=da[2]=da[3]=1;
    for(int i=4;i<=25;i++){
        da[i]=1;//全对只有一种
    for(int j=1;j<=i/2;j++)
    da[i]+=c(i,j)*cuobai[j];
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)>0&&n)
    {
        printf("%I64d\n",da[n]);
    }
}


