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
#define max1 100005
#define maxn 50005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

ll pre[max1] = {0}, n, t, a, b;
string s;

int find(int x)
{
	int r = x;
	
	while( pre[r] != r)
		r = pre[r]; // 返回根节点 
		
	int i = x, j;
	
	if( i != j )
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}  
	return r;
}
/*
int find(int x)
{
	return pre[x] == x ? x : pre[x] = find( pre[x] ) ; 
}
*/
void join(int x, int y)
{
	int px = find(x);
	int py = find(y);
	//cout <<x<<' '<< px <<' '<<y<<' ' << py <<endl;
	if( px != py)
		pre[px] = py;
}

int ans = -1;
	
void op()
{
	rep(i, 1, t)
	{
		//cout << "Sass";
		
		cin >> a >> b;
		cin >> s;
		
		if(ans != -1)
			continue;
		
		a = (a - 1) % maxn; 
		b = b % maxn;
		//cout <<a << ' '<< b <<' '<< s << endl;
		
		if( find(a) == find(b + maxn))
				ans = i - 1;
		else if( s == "even" ) // even
		{

			join(a, b);
			join(a+maxn, b+maxn);
		}
		else  // odd
		{
			join(a, b+maxn);
			join(a+maxn, b);
		}
	}
}

int main()
{
	
	cin >> n >> t;
	
	pre[0] = 1;
	rep(i, 1, max1)
		pre[i] = i;

	op();
	
	if(ans == -1)
		ans = n;
	cout << ans << endl;	
	return 0;
}
