#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define max3(a,b,c) max(a,max(b, c))
int dp[100005][15];

int main()  {
    int x, t, n;
    while( scanf("%d", &n) && n )
    {
        memset(dp, 0, sizeof(dp));
        int max_time = 0;

        rep(i, 0, n-1){
            scanf("%d %d", &x, &t );
            dp[t][x+1]++ ;
            max_time = max(max_time, t);

        }

        per(i, max_time, 0) /// 从最后的时间依次向前递推
            rep(j, 1, 11) /// 从相邻的两侧(距离1m)或者原地不动，取一个最大值
                dp[i][j] += max3(dp[i+1][j-1],
                        dp[i+1][j], dp[i+1][j+1] ), cout << i << ' ' << j << ' ' << dp[i][j] << endl;

        /// 依次累加到t为0为止
        printf("%d\n", dp[0][6] );
/// 最后输出的时候也应该输出6那个位置(相当于5)
    }

}
