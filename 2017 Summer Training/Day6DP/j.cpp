#include <cstdio>
#include <cstring>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define max3(a,b,c) max(a,max(b, c))
#define max4(a,b,c,d) max(max(a,b), max(c, d))
int dp[105][105];
int t, n, m, a[105][105];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int dfs(int x, int y, int h) {
    if( x < 1 || x > n || y < 1 || y > m || h <= a[x][y] )
        return 0;
    if( dp[x][y] >= 0)
        return dp[x][y];

    dp[x][y] = max4( dfs(x-1, y, a[x][y]),
                   dfs(x+1, y, a[x][y]),
                   dfs(x, y-1, a[x][y]),
                   dfs(x, y+1, a[x][y]) ) + 1;

    return dp[x][y];
}


int main()  {
        scanf("%d %d", &n, &m);
        memset(dp, -1, sizeof(dp));

        rep(i, 1, n)
            rep(j, 1, m)
                scanf("%d", &a[i][j]);

        int max1 = 0, s;
        rep(i, 1, n)
            rep(j, 1, m)
                if( (s = dfs(i,j,inf)) > max1)
                    max1 = s;
        printf("%d\n", max1);
}
