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

//aiemckgobjfndlhp 20 
// A C G J L P     6

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	int dp[maxn];
	
	int max1 = 0;
	
	rep(i ,1, len )
	{
		dp[i] = 1;
		rep(j, 1, i-1)
		{
			if( s[j-1] < s[i-1] )
				dp[i] = max ( dp[j] + 1, dp[i]);
		}
		max1 = max( max1 , dp[i]);
		
	}
	
	cout<< 26 - max1 <<endl; 
	return 0;	
}

int main()
{
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
	
}


