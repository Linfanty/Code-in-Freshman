#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i <= b; i++)
const int maxn = 40005;

int dp[2005][2005];

int main()  {
    string a, b;
    while( cin >> a >> b)
    {
        int len1 = a.size();
        int len2 = b.size();

        memset(dp, 0, sizeof(dp));

        rep(i, 1, len1)
            rep(j, 1, len2)
                if( a[i-1] == b[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        cout << dp[len1][len2] << endl;
    }

}


