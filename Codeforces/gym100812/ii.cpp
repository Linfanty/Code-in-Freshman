#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 100005;

ll a[maxn], sum[maxn], dp[maxn];

int main()
{
    int n;
    ll d, c;
    cin >> n >> d >> c;
    rep(i, 1, n)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];//前i个送货时间的前缀和
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    rep(i, 1, n)
    {
        rep(j, 0, i-1)
        dp[i] = min(dp[i-1] + d, dp[i-2] + d + c *(a[i]- a[i-1]), dp[i-1] );
    }
    cout << dp[n] <<endl;
}
