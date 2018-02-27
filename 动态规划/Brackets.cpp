#include <iostream>
#include <cstring>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int dp[105][105];
string s;
bool isok(int x, int y)
{
    if(s[x] == '(' && s[y] ==')' || s[x] == '['&& s[y] == ']') return true;
    return false;
}
int dfs(int l, int r)
{
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    for(int i = l; i <= r; i++)
        if(isok(l, i)) dp[l][r] = max(dp[l][r], 2 + dfs(l + 1, i - 1) + dfs(i + 1, r));
        else dp[l][r] = max(dp[l][r], dfs(l, i) + dfs(i + 1, r));
    return dp[l][r];
}

int main()
{
    while(cin >> s && s != "end")
    {
        memset(dp, -1, sizeof dp);
        cout << dfs(0, s.size() - 1) << endl;
    }
    return 0;
}
