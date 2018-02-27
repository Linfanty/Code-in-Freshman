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
	string s;
	cin >> s;
	int len = s.size(), cnt = 0;
	
	if( len == 1)
		cout << 0 <<endl;
	else if( len == 0)
		cout << 1 << endl;
	else
	{
		rep(i, 0, len-2 )
		{
			if(s[i] == 'V' && s[i+1] == 'K' )	
				cnt ++ ;
		}	
		int sum = cnt;
		
		cnt = 0;
		
		rep(i, 0, len -1 )
		{
			cnt = 0;
			string s1 = s;
			if( s[i] == 'V')
				s1[i] = 'K';
			else s1[i] = 'V';
			
			rep(j, 0, len-2)
			{
				if(s1[j] == 'V' && s1[j+1] == 'K' )	
					cnt ++ ;		
			}
			sum = max(cnt, sum);
		///	cout << sum << ' ';		
		}
		cout << sum <<endl; 

	}	
	
		
	return 0;
}
