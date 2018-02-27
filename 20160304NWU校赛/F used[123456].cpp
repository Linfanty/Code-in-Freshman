//循环六次找到该数的最小表示法
//大数标记法 ans[123456]++
 
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
#define maxn 10000
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a)) 
#define fre freopen("in.txt","r",stdin)
#define  atoi atof
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

int main()
{
	ll n;
	while( cin>> n )
	{
		bool used[1000005];
		mem(used,false);
		ll ans= 0;
		while(n--)
		{
		
	
		ll num;
		cin>>num;
		ll min1 = num ;
		int i = 5 ;
		while( i-- )
		{
			num = (num % 10) * 100000 + (num/10);
			if( num < min1 )
			min1 = num ;
		}
		if( !used[min1] ) 
		{
			used[min1] = true;
			ans ++ ;
		}
		
		}
		cout<<ans<<endl;
		/*int min1 = 0 ; 
		for( int i = 1 ; i < 5 ; i++)
		{
			if( num[i] < min1 )
			min1 =  i ;
		}		
		for( int i = min1 ; i < min1 + 6 ; i++ )
		{
			t[i] = 
		}
		*/
	}	
	return 0;
}




