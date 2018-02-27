/*********************************************
Memory: 1140 KB     Time: 3976 MS
Language: C++       Result: Accepted
*********************************************/
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int l[1005];
int v[1005];
ll dp[4005][5];

int main()
{
    int t;
    cin >> t;
    int cas = 0;
    while (t--)
    {
        cas++;
        int n, L;
        cin >> n >> L;
        L *= 2;
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> l[i] >> v[i];
            l[i] *= 2;
            ans = max(ans, (ll)v[i]);
        }
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i)
        {
            for (int j = L; j >= l[i] / 2; --j)
            {
                dp[j][2] = max(dp[j][2], dp[j - l[i] / 2][1] + v[i]);
                if (j >= l[i]) dp[j][2] = max(dp[j][2], dp[j - l[i]][2] + v[i]);
                dp[j][1] = max(dp[j][1], dp[j - l[i] / 2][0] + v[i]);
                if (j >= l[i]) dp[j][1] = max(dp[j][1], dp[j - l[i]][1] + v[i]);
                if (j >= l[i]) dp[j][0] = max(dp[j][0], dp[j - l[i]][0] + v[i]);
            }
        }
        ans = max(ans, dp[L][2]);
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

/**
Input:
50
2 3
1 2
2 3

3 7
4 1
2 1
8 1

3 7
4 2
2 1
8 4

3 5
4 1
2 2
8 9

1 1
10 3



Output:
5
2
6
11
3

*/

