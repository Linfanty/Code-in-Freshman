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
#define maxn 200005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ll n,k;	cin>> n >> k;
	ll s[100005] = {0} ;
	
	for( ll i = 1 ;i<= n;i++)
	{
		cin >> s[i];
	}
	
	sort(s+1 , s+n+1);
	ll sum = 0;
	
	for( ll i = n ;i>= 1;i--)
	{
		while( s[i] >= k*2)
		{
			s[i] = 	s[i] - 2*k;
			++sum;
		}	
	}
	sort(s+1 , s+n+1);
	
//	cout<<sum<<endl;
	
	for( ll i = 1 ;i<= n-1;i++)
	{
		if(s[i] == 0)
			continue;
		else if((s[i] <= k) && (s[i+1] <=k)) 
		{
			s[i+1] = 0;
			++sum;
			++i;
			continue;
		}
		else if( (s[i] <= k ) && (s[i+1] >k ))
		{
			s[i+1] = s[i+1] - k;
			++sum;
			continue;
		}
	//	else if( (s[i] > k ) && (s[i+1] >k ))
	//	{
	//	}
	}
	
	if(s[n] !=0 )
		sum++;
	cout << sum ;
	
	return 0;
}
