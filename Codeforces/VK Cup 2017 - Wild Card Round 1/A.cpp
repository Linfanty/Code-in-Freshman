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
#define maxn 1000000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int main()
{
	int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	ll n, sum = 0;
	
	/*if( n == 2 )		ans = 1;
	else if( n == 3)	ans = 7;
	else if( n == 4)	ans = 11;
	else if( n == 5)	ans = 71; 
	else if( n == 6) 	ans = 111;
	else if( n == 7)	ans = 711;
	else if( n == 8)	ans = 1111;
	else if( n == 9)	ans = 7111;
	else if( n == 10)	ans = 11111;
	*/
	cin >> n;
	if( n%2 == 0)
	{
		rep( i, 1, n/2)
			cout<<1;
	}
	else
	{
		cout<<7;
		rep( i, 1, (n-3)/2)
			cout<<1;
	}
	return 0;
	
}
