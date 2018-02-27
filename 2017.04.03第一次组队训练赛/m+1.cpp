#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = 1e6+5;

int n, a[55], dp[55][2];

int main()
{
    //FIN;
    cin >> n;
    rep(i, 1, n)    cin >> a[i];
    int maxn = 1;
    rep(i, 1, n)
	{
        dp[i][0] = dp[i][1] = 1;
        
        rep(j, 1, i-1)
		{
            if(a[j] > a[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
            if(a[j] < a[i]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
        }
        
        maxn = max(maxn, max(dp[i][0], dp[i][1]));
    }
    
    cout << maxn << endl;
    return 0;
}
