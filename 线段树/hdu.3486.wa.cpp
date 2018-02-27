#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200000+10;
const int maxn2 = 30;   //这里要保证2^maxn2>maxn
int d[maxn][30];
int a[maxn];

//如果是求最大值，则把min改成max就可以了
void init_rmq(int n)//初始化
{
    for(int i=0;i<n;i++)
        d[i][0] = a[i];
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
            d[i][j] = max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    }
}

//查询函数
int query_rmq(int L,int R)
{
    int k=0;
    while(1<<(k+1)<=R-L+1)k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}

bool check(int len,int m,int t)
{
    int sum = 0;
    for(int i=1;i<=t;i=i++)
    {
        sum += query_rmq((i-1)*len+1,i*len);
        if(sum > m)
            return true;
    }
    return false;
}

int main()
{
    int n;
    int m;
    while(~scanf("%d %d\n",&n,&m))
    {
        if(n<0 || m<0)
            break;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum<=m)
        {
            printf("-1\n");
            continue;
        }

        init_rmq(n);
        int l=1;
        int r=n;
        int ans;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(n/mid,m,mid))
            {
                ans = mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}