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

int main()
{
	string x, y, z;
	cin >> x >> z;
	
	int len = x.size();
	int flag = 0;
	
	rep(i, 0, len-1)
	{
		if(z[i] > x[i])
		{
			cout << -1 <<endl;
			flag = 1;
			break;
		}
	
		
	}
	if( flag == 0)
	{rep(i, 0, len-1)
		 printf("%c",z[i] );
	}
	
	
		
	return 0;
}
