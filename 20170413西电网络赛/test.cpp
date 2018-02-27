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
{IO;

	int n;

	while( cin >> n )
	{
	int flag[5005] = {0}, flag1 = 0;
	string yuan[5005], s[5005];
	
	rep(i, 1, n)
	{
		cin >> yuan[i];
		s[i] = yuan[i]; 
		int len = s[i].size();
		//rep(j, 0, len-1)
		//	a[i][ s[j] ] ++;
		rep(j, 0, len-1)
			rep(k, 0, len-1)
			{
				if(s[i][k] < s[i][j])
					swap(s[i][k], s[i][j]);
			}
		
		int flag2 = 0;
		
		//flag[i] = flag1 + 1;
		rep(j, 1, i-1)
		{
			if( s[i] == s[j] )
			{
				flag[i] = flag[j];
				flag2 = 1;
				break;	
			}
		}
		
		if(flag2 == 0)
		{
			flag[i] = flag1 + 1;
			flag1++;	
		}
	}
	
	//rep(j, 1, 10)
	//	cout << flag[j] << ' ';
	///	cout<<flag1<<endl;
	
	int mark[5005] = {0};
	
	rep(i, 1, flag1  )
	{
		rep(j, 1, n)
		{
			if( flag[j] == i && mark[ flag[j] ] != 0)
				cout << ' ' << yuan[j] ;
			else if(flag[j] == i && mark[ flag[j] ] == 0)
			{
				cout << yuan[j];
				mark[flag[j]] = 1;		
			}
		}
		//if( i != flag1  )
		cout << endl;
	}
	
	}
	
	
	
}
