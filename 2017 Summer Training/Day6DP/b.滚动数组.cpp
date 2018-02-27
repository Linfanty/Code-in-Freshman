#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define max3(a,b,c) max(a,max(b, c))
#define max4(a,b,c,d) max(max(a,b), max(c, d))
const int MAXN = 1e6+7;
int n;
char a[5005], b[5005];
int dp[2][5050];

int main()  {
    while ( scanf("%d\n", &n) != EOF)
    {
         rep(i, 0, n-1)
            scanf("%c", &a[i]), b[n-i-1] = a[i];

         memset(dp, 0, sizeof(dp));
/// 需要加的字符的个数=原来字符串的长度-原来字符串和逆字符串的最长公共子序列的长度。
/// Ab3bd db3bA 最长公共子序列的长度

         rep(i, 1, n)
            rep(j, 1, n)
                {if( a[i-1] == b[j-1] )
                    dp[i%2][j] = dp[ (i-1)%2 ][j-1] + 1;
                else dp[i%2][j] = max(dp[(i-1)%2][j],
                                      dp[i%2][j-1]   );
                cout << i << a[i-1]<< ' ' << j<< b[j-1] << ' ' << dp[i%2][j] << endl;
                }
        printf("%d\n", n - dp[n%2][n] ); /// d p[n%2][n]
    }
}
