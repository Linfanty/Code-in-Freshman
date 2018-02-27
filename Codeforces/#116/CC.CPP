#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, 0, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1000005;
    string s;
    int sum[maxn], cnt = 0, ans;

int main()
{

    cin >> s;   int len = s.size();
    per(i, len-1, 0)
        sum[i] = sum[i+1] + (s[i] >= 'a' ? 0 : 1);
///从后向前找i之后有多少大写的
    ans = sum[0];
    rep(i, 0, len-1)
    {
///从前向后找i之前有多少小写的 记为 cnt
        cnt += (s[i] >= 'a' ? 1: 0);

        //cout << cnt << ' ' << sum[i+1] << endl;

        ans = min(ans, sum[i+1] + cnt);
    }
    cout << ans ;
}
/*
PPPPrPPPrPPPPPPPPrrrrrrrrrPrrrrrrr
0 15
0 14
0 13
0 12
1 12
1 11
1 10
1 9
2 9
2 8
2 7
2 6
2 5
2 4
2 3
2 2
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
11 0
12 0
13 0
14 0
15 0
16 0
17 0
18 0
3
*/
