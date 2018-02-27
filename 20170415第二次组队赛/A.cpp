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
	int a[200] = {0} ;
	string s;
	cin >> s;
	int len = s.size();
	
	rep(i, 0, len-1)
	{
		//cout << s[i] -'a' <<' ';
		a[ s[i] -'a' ] ++ ;
	}
	int cnt = 0;
	
	sort(a, a + 26, greater<int>());
	
	
	rep(i, 2, 26)
	{
		//cout << a[ i ] <<endl;
		if( a[i] )
			cnt += a[i];
		
	}
	
	//if( cnt > 2)
	cout <<  cnt  << endl;
	//else cout << 0 <<endl;
	
	
	return 0;	
} 
