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
#define maxn 1000000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int dp[ 1000005 ]; // 6 个 0  7位数 
int main()
{
	 	dp[1] = 1;
	 	dp[2] = 2;
	 	dp[3] = 2;
	 	
	 	dp[4] = 4;
	 	dp[5] = 4;
	 	
		dp[6] = 6;
		dp[7] = 6;
		
		dp[8] = 10;
	 	dp[9] = 10;
		
		dp[10] = 14;
		dp[11] = 14;
		
		dp[12] = 20;
		dp[13] = 20;
	
	ll n;
	cin >> n;
	
    rep ( i, 2 , n)  
    {
    	if( i & 1)
			dp[i] = dp[i-1];
		else dp[i] = (dp[i-1] + dp[i/2]) % maxn ; 	// 取模 提前算 
	}    
	
   	cout << dp[n]  ;
  
	/*
	if( n %2 == 0)
		 cout<< n % maxn << endl;
	else cout<< (n-1) % maxn << endl;
	*/
}


