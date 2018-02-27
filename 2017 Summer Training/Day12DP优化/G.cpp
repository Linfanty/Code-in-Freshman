
/** 加一维表示是否在边界放置，放置一个，两个

状态转移方程：dp[i][j][k]=max( dp[i-1][j][k],
                                   dp[i-1][j-w[i]][k]+v[i],
                                   dp[i-1][j-w[i]/2][k-1]+v[i]);
1、是费用除以2会出现小数，所以我们可以在一开始所有的费用全部乘2，背包容量也乘2。

2、如果只放一根金条，无论金条多长，都可以放下。
                                         */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define mem(a) memset(a,0,sizeof(a))
#define pfn printf("\n")
#define ll long long
#define pfd(a) printf("%d\n",a)
#define pf2d(a,b) printf("%d %d\n",a,b)
#define pf3d(a,b,c) printf("%d %d %d\n",a,b,c)
#define pfs(a) printf("%s\n",a)
#define sfd(a) scanf("%d",&a)
#define sf2d(a,b) scanf("%d%d",&a,&b)
#define sf3d(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfs(a) scanf("%s",a)
#define sf  scanf
#define pf  printf
#define fr(i,n) for(int i=0;i<n;i++)
const double PI = acos(-1.0);
const double e = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
using namespace std;

#define N 4000+10
long long v[1010],w[1010];
long long dp[N][3];
int main()
{
    //freopen("1.txt","r",stdin);
    int t;
    sfd(t);
    for(int cas=1;cas<=t;cas++){
        printf("Case #%d: ",cas);
        int n,m;
        long long ma=0;
        scanf("%d%d",&n,&m);
        m*=2;
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&w[i],&v[i]);
            w[i] *= 2;
            ma = Max(ma,v[i]);
            for(int j=m;j>=w[i]/2;j--)
            {
                for(int k=0;k<=2;k++)
                {
                    if(k>=1)
                        dp[j][k]=Max(dp[j-w[i]/2][k-1]+v[i],dp[j][k]);
                    if(j>=w[i])
                    {
                        dp[j][k]=Max(dp[j-w[i]][k]+v[i],dp[j][k]);
                    }
                    ma=Max(dp[j][k],ma);
                }
            }
        }
        printf("%lld\n",ma);
    }
    return 0;
}
