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
#define maxn 10000005
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
	while( cin >> n)
	{
		rep(j, 1, n)
		{
			int i;
			rep(i, 1, 26 - j)
			cout <<' ';
		
			rep(i, 1, j)
			printf("%c", 'A' + i-1) ;  
			per(i, j-1, 1)
			printf("%c", 'A' + i-1) ;  
			
			cout << endl; 
		}
		
		
	}
		
	
}
