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

map<string, int> mymap;

int main() 
{
	int n;
	cin >> n;
	char s[5005][10];
	rep(i, 1, n)
	{
		cin >> s[i];
		int len = strlen(s[i]);
		int k = 0, min1 = 30;
		rep(j, 0, len-1)
		{
			if( s[i][j] - 'a' +1 < min1)
			{
				min1  = s[i][j] - 'a' +	1;
				k = j;
			}
		}
		rep(j, len , 2*len)
			s[i][j] = s[i][j-len] 
		rep(j, 0, len - 1)
			s[i][j] = 
		
		cout << k << ' ';
	}
}





