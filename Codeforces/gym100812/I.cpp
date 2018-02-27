#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 1000005;

ll num[maxn];

//http://blog.csdn.net/qq_31759205/article/details/52224203


typedef long long LL;
LL a[1005], sum[1005], dp[1005];
int main() {
    int n;
    LL d, c;
    // freopen("in.txt","r",stdin);
    while(~scanf("%d%I64d%I64d", &n, &d, &c)) {
        for(int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            sum[i] = sum[i - 1] + a[i]; //前i个送货时间的前缀和 2 7 13
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        //区间dp,送到第i个货物时,考虑第i个与前i-1个货物的组合,取花费最小的组合
        //由于前前i-1个货物的情况已经是最优,那么dp[i]=min(dp[j]+cost);(cost是j+1,i]一起送时候的花费)
        //对于[j+1,i]中每个物品x,其花费cost=(a[i]-a[x])*c,那么累加起来等于((i-j)*a[i]-(sum[i]-sum[j]))*c
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + ((i - j) * a[i] - (sum[i] - sum[j])) * c + d);
//printf("%d: %I64d %d %d %d \n",i, dp[i],  (i - j) * a[i] ,   (sum[i] - sum[j]) ,(sum[i] - sum[j])*c) ;
            }
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
