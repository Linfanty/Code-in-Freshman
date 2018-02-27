
# include<cstdio>
# include<cstring>
using namespace std;
#define NUM 50
int MAXN,n,mod;
struct Matrix//矩阵的类
{
    int a[NUM][NUM];
    void init()           //将其初始化为单位矩阵
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<MAXN;i++)
            a[i][i]=1;
    }
} A;
Matrix mul(Matrix a,Matrix b)  //(a*b)%mod  矩阵乘法
{
    Matrix ans;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
        {
            ans.a[i][j]=0;
            for(int k=0;k<MAXN;k++)
                ans.a[i][j]+=a.a[i][k]*b.a[k][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

Matrix add(Matrix a,Matrix b)  //(a+b)%mod  //矩阵加法
{
    int i,j,k;
    Matrix ans;
    for(i=0;i<MAXN;i++)
        for(j=0;j<MAXN;j++)
        {
            ans.a[i][j]=a.a[i][j]+b.a[i][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

Matrix pow(Matrix a,int n)    //(a^n)%mod  //矩阵快速幂
{
    Matrix ans;
    ans.init();
    while(n)
    {
        if(n%2)//n&1
            ans=mul(ans,a);
        n/=2;
        a=mul(a,a);
    }
    return ans;
}

Matrix sum(Matrix a,int n)  //(a+a^2+a^3....+a^n)%mod// 矩阵的幂和
{
    int m;
    Matrix ans,pre;
    if(n==1)
        return a;
     pre=sum(a,m);                      //[1,n/2]
    ans=add(pre,mul(pre,pow(a,m)));   //ans=[1,n/2]+a^(n/2)*[1,n/2]
    if(n&1)
        ans=add(ans,pow(a,n));          //ans=ans+a^n
    return ans;
}

void output(Matrix a)//输出矩阵
{
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            printf("%d%c",a.a[i][j],j==MAXN-1?'\n':' ');
}
int main()
{
    freopen("in.txt","r",stdin);
    Matrix ans;
    scanf("%d%d%d",&MAXN,&n,&mod);
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
        {
            scanf("%d",&A.a[i][j]);
            A.a[i][j]%=mod;
        }
    ans=sum(A,n);
    output(ans);
    return 0;
}
