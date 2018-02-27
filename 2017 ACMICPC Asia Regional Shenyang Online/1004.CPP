#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define N 400
#define maxn 100100

int dp[100005];
int a[100005] = {-1};
int dp2[100005];
int b[100005] = {-1};

int main()
{IO;
    int t, n, k;
    scanf("%d", &t);
    while( t--)
    {
        scanf("%d %d", &n, &k);

        int ans = -1, ans2 = -1;
        for(int i = 1; i <= n; i++) cin >> a[i], b[i] = -a[i];

        for(int i = 1; i <= n; i++) dp[i] = 1, dp2[i] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
                if(b[j] < b[i]) dp2[i] = max(dp2[i], dp2[j] + 1);

            }
            ans = max(ans, dp[i]);
            ans2 = max(ans2, dp2[i]);
        }
       // cout  << ' ' << n - ans  << ' ' << n - ans2 << endl;
        if( min(n - ans, n - ans2 ) <= k)
            cout << "A is a magic array." << endl;
        else cout << "A is not a magic array." << endl;
    }

}
