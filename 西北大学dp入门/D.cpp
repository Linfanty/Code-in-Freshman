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
	 int T;
	 int dp[50] = {0};
	 	dp[1] = 1;
	 	dp[2] = 1;
	 	dp[3] = 2;
	 	
	 rep( i, 3, 41)
	 {
	 	dp[i] =  dp[i-1] + dp[i-2];
	 	//每一步都可以是前面的一步或者两步走过来
	 }
	 cin >> T;
	 while(T--)
	 {
	 	
	 	
	 	int n;
	 	cin >> n;
	 	cout << dp[n] <<endl;
	 }
}


