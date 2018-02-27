#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
int dp[1005];
int a[1005] = {-1};
int main()
{
    int n, ans = -1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
//        for(int j = 1; j <= n; j++) cout << dp[j] << " "; cout << endl;
    }
    cout << ans << endl;
    return 0;
}
