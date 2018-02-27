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
	 ll dp[maxn] = {0};
	 	dp[1] = 2;
	 	dp[2] = 7; // 2 + 5
	 	dp[3] = 16;// 7 + 9
	 	dp[4] = 29;// 16 + 13
	 	//分割平面数= 交点数 + 顶点数 + 1
	 rep( i, 3, maxn)  //(0<a<b<50)
	 {
	 	dp[i] =  dp[i-1] + 4 * (i-1) + 1 ;
	 }
	 
	 cin >> T;
	 while(T--)
	 {
	 	
	 	int n;
	 	cin >> n ;

	    cout << dp[ n ] <<endl;
	 }
}


