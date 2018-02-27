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

int main()
{IO;
	ll n;
	ll road[maxn];
	ll min1 = LONG_MAX;
	cin>>n;
	for(ll i = 1;i <= n ;i++)
	{
		cin>>road[i];
	}
	
	sort(road+1, road+1+n);
	
	for(ll i = 2;i <= n ;i++)
	{
	
		min1 = min( road[i] - road[i-1] , min1 );
	}
	
	ll cnt = 0;
	for(ll i = 2;i <= n ;i++)
	{
		if( road[i] - road[i-1] == min1 )
			++cnt;
	}
	cout<<min1<<' '<<cnt<<endl;
	return 0;
}
