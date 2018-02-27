#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define maxn 100
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a));
#define fre freopen("in1.txt","r",stdin)
#define  atoi atof
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

ll a,b;
bool cmp (const string &s1 , const string &s2)
{
	for( int i = 0 ; i < s1.size() ; i ++ )
	{
		if( s1[i] != s2[i] )
		return s1[i] < s2[i] ;
	}
	return true ;
}

bool isok (string &s1)
{
	ll x = 0;
	ll y = 0;
	for( int i = 0 ; i < s1.size() ; i++)
	{
		x = (x * 10 + s1[i] - '0') % a ;
		y = (y * 10 + s1[i] - '0') % b ;					
	}	
	return x !=0 && y != 0;
}

void addone (string &s1)
{
	for(int i = s1.size() - 1 ; i >= 0 ; i-- )
	{
		if( s1[i] == '9')
		s1[i] = 0 ;
		else 
		{
			s1[i] ++;
			break;
		}
	}
}

int main()
{
//	fre;
 //   freopen("out.txt", "w", stdout);
	string s1 , s2 , ans = "-1";
	while(cin >> a >> b >> s1 >> s2 )
	{
		//ll ans = -1 ;
		
		if( a == 1 || b == 1)
		{
			cout << -1 << endl;
			continue;
		}
		
		s2.insert ( 0 ,"0" );
		while( s1.size() < s2.size() )
			s1.insert( 0 , "0" );
			
		while( cmp( s1 ,s2 ) && s1 != s2 )
		{
			if( isok(s1) )
			{
				ans = s1 ;
				break;				 
			}
			else addone(s1) ;
		}	
		ans.erase( 0 , ans.find_first_not_of("0"));
		cout << ans << endl ;		
	}
	
return 0 ;
}
/*
-1  10001
*/
