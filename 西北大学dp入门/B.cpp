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
	int dp[60] = {0};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 6;
	
	//去年的母牛，只要没有死，今年仍在因此有f(n-1)头，
	//今年出生的母牛有多少？大前年(第n-3年)有多少头母牛，
	//那么到了今年这些牛都能生小牛了，因此出生数为f(n-3)
	
	//f(n)=f(n-1)+f(n-3)
	
	rep( i, 5, 55)
	{
		dp[i] = dp[i-1] + dp[i-3]; // 
	}
	
	int n;
	while( cin>>n  )
	{
		if(n==0)
		break;
		cout<<dp[n]<<endl;
	}
}
