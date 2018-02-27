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
#define maxn 10000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#db从n个数中选m个使得他们的和尽可能的接近x

int dp[ 10005 ] = {0};


int solve()
 {
     for(int i=0;i<n-1;i++)
     {
         for(int k=rema-5;k>=val[i];k--)
         {
             dp[k]=max(dp[k],dp[k-val[i]]+val[i]);
         }
     }
     return dp[m-5];
 }

int main()
{
	int n, price[1005], 
	while( cin >> n)
	{
		if( n == 0)
			break;
		rep( i, 0, n-1)
			cin >> price[i];
		
		int rema;
		cin >> rema;
		
		sort ( price, prince + n);
		
		int cc = solve();
		
		if( n == 1 && ream >= 5)
			cout << rema - price[1] << endl;
		else if( n == 1 && ream < 5)
			cout << rema << endl;
		else
		
			
			
				
	}
	
}


