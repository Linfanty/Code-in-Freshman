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

string s;
int dp[105];

int main()
{
    //FIN;
    cin >> s;
    int len = s.size(), maxn = 0;
    rep(i, 1, len){
        dp[i] = 1;
        rep(j, 1, i-1){
            if(s[j-1] < s[i-1]) dp[i] = max(dp[j]+1, dp[i]);
        }
        maxn = max(maxn, dp[i]);
    }
    cout << 26-maxn << endl;
    return 0;
}
