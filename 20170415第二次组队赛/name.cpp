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

struct Node
{
	string first;
	string last;
}node[105];

bool cmp( Node x, Node y)
{
	if( x.last  == y.last )
		return x.first < y.first ;
	else return x.last < y.last ; 
}

int main()
{
	int n;
	cin >> n;
	
	rep(i, 0, n-1)
	{
		cin >> node[i].first >> node[i].last ;	
	}	
	
	sort(node, node + n, cmp);
	
	rep(i, 0, n-1)
	{
		cout << node[i].first <<' '<< node[i].last << endl;
	}
	
	
}



