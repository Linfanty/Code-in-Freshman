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
#define maxn 40005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)
int pre[maxn] = {-1}, v[maxn] = {0};
ll m, n, a, b, s, ans = 0;

int find(int x)
{
	//return pre[x] == x ? x : pre[x] = find(pre[x]);	
	if( pre[x] == -1)
		return x;
	int tmp = find(pre[x]);;
	
	v[x] += v[pre[x]];
		return pre[x] = tmp;	

}
 

void join(ll x, ll y, ll z)
{
	int px = find(x);	int py = find(y);
	 
	if( px!= py)
	{
		pre[py] = px;	
		v[py] = v[x] - v[y] + z ;
	}
	else
	{
		if( v[y] - v[x] != z )
			ans++;
	}
}

int main()
{
	cin >> n >> m;
	
	
	rep(i, 1, m)
	{
		cin >> a >> b >> s;
		
		--a;
		join(a, b, s);
		
		
	}
	cout << ans <<endl;
}

