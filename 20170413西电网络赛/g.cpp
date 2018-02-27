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
#define maxn 200005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

ll a[maxn];
int main()
{IO;
	ll n, m;
	while( cin >> n >> m)
	{
		rep(i, 1, n)
			cin >> a[i];
		
		ll max1 ;
		ll sum = 0;	
		 
		rep(i, 1, m)
			sum += a[i];
		
		max1 = sum;
		
		rep(i, 1, n-m )
		{
			sum  += a[i + m] - a[i] ; 		
			max1 = min ( sum, max1 );
		//	cout << sum << ' ';
		}
		cout << max1 << endl;
	}	
	
} 
