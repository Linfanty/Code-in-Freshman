#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int main()
{
	int n, T;
	cin>> T;
	while( T-- )
	{
		int a[105][105] = {0}, dp[105][105] = {0};
		cin >> n;
		rep( i, 1, n)
		{
			rep( j, 1, i)
				cin >> a[i][j];
		}
		
		rep( i, 1, n+1)
			a[n+1][i] = 0;
		
		per( i, n, 1)
		{
			rep( j, 1, i)
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];	
		}
		cout << dp[1][1] << endl;
	}
	
}
