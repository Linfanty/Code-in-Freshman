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
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	int T ; 
	cin >> T;
	while( T-- )
	{
		int n , m;
		int a[105];
		cin >> n >> m ;
		a[0] = 0 ;
		a[n+1] = 100 ;
		for ( int i = 1 ; i <= n ; ++i)
		{
			cin >> a[i] ;
		}
		
		int sum = 0 ,max = -1 ;
		
		if(n == 1 && m == 1 )
		{
			cout<<100<<endl;
			continue ;
		}
		else if( m >= n )
		{
			cout<<100<<endl;
			continue ;
		}
				
		else  if( m < n )
		
		for ( int i = 0 ; i <= n-m+1 ; ++i)
		{
			sum = a[ i + m+1 ] - a[i ] - 1;
			if(sum > max )
			max = sum ;
		}
		cout<<max<<endl;		
	}//http://hihocoder.com/problemset/problem/1051
}
