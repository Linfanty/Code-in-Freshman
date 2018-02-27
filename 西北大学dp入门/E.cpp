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
	 ll dp[51] = {0};
	 	dp[1] = 1;
	 	dp[2] = 2;
	 	dp[3] = 3;
	 	
	 rep( i, 3, 51)  //(0<a<b<50)
	 {
	 	dp[i] =  dp[i-1] + dp[i-2];
	 	//每一步都可以是前面的一步或者两步走过来
	 }
	 cin >> T;
	 while(T--)
	 {
	 	
	 	int n, m;
	 	cin >> n >> m;
	 	if(m - n == 1)
	 	cout<< 1 << endl;
	 	else if(m- n == 2 )
	 	cout<< 2 << endl;
		else cout << dp[ m - n ] <<endl;
	 }
}


