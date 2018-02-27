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
#define maxn 1005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int main()
{
	ll n;
	ll a[100005];
	
	cin >> n;
	
	rep(i, 0, n-1)
		cin >> a[i];
	
	sort(a, a+n );
	
	//rep(i, 0, n-1)
	//	cout << a[i] <<endl;
		
	ll min1 = a[0] + a[ n-1  ];
	ll now;
	
	rep(i, 0, n-1)
	{
		now = a[i] + a[ n-1 -i ];
		//cout << a[i] << ' ' << a[n - 1 -i ] << ' '<< now <<endl;
		min1 = min(min1, now);
		
	}
		
	cout << min1<< endl;
		
		
		
		
		
		
	
}
