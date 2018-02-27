#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[1005][1005];
int dfs(int pos1, int pos2)
{
	if(pos1 == -1 && pos2 == -1) return 0;
	if(pos1 == -1) return pos2 + 1;
	if(pos2 == -1) return pos1 + 1;
	if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
	if(s1[pos1] == s2[pos2]) return dp[pos1][pos2] = dfs(pos1 - 1, pos2 - 1);
	return dp[pos1][pos2] = min(dfs(pos1, pos2 - 1), min(dfs(pos1 -1, pos2), dfs(pos1 - 1, pos2 - 1))) + 1;
}
int main()
{
	while(cin >> s1 >>s2)
	{
		memset(dp, -1, sizeof dp);
		cout << dfs(s1.size() - 1, s2.size() - 1) << endl;
	}
}
