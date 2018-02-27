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
#define maxn 30005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int pre[maxn] = {0}, ans = 0;

/*
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
*/

int find(int x)
{
	return pre[x] == x ? x : pre[x] = find( pre[x] ) ; 
}


void join(int x, int y)
{
	int px = find(x);
	int py = find(y);
	
	if( px == 0 )
		pre[py] = px; //  py = pre[py];
	else if( py == 0)
		pre[px] = py; 
	//if( px!= py)
	else
		pre[px] = py;
}


int main()
{
	int n, m, k, a, b;
	while( cin >> n >> m)
	{
		if(n == 0 && m == 0)	break;
		
		rep(i, 0, n)
			pre[i] = i;
		
		rep(i, 1, m)
		{
			cin >> k;
			cin >> a;
			if( k == 1)
			{
				if( a == 0 )
					ans ++;
			}	
			else 
			{
				rep(j, 0, k-2)
				{
					cin >> b;
					join(a, b);
				}
			}
		}
		rep(i, 0, n)
		{
			//cout << i << ' ' << pre[i] << endl;
			if( find(i) == 0)
				ans++;
		}
		cout << ans << endl;	
		ans = 	0;
	}
	

	return 0;
}
