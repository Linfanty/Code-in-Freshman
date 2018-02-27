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
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll s[maxn] = {0} ;
ll m;

bool find (ll x)
{
	for( ll i = 1 ; i<= m ; i++)
	{
		if( s[i] == x )
		{
			return true;
		}
		if( x < s[i] )
			return false;
	}
	return false;
}

int main()
{
	ll b1, q, l;
	cin >> b1 >> q >> l >>m;
	
	for( ll i = 1 ; i<= m ; i++)
		cin >> s[i];
	
	sort( s+1 , s+m+1);
	
	if( q == 1 )
	{
		/*if( b1 == -1 )
		{
			if( !find(  ) )	
				cout<<"inf"<<endl;
			else	cout<<0<<endl;
		
		}
		else
		*/{
			if( !find( abs(b1) ) )	
				cout<<"inf"<<endl;
			else	cout<<0<<endl;	
		}
	}
		
	else if( q == 0 && b1 == 0)
	{
		if( find(0) )
			cout<<0<<endl;
		else cout<<"inf"<<endl;
	}

	else if( q == 0 && b1 != 0)
	{
		if( find(q)  )
		{
			if( !find(b1) )
				cout<<1<<endl;
			else cout<<0<<endl;	
		}	
		else 
		{
			if( !find(b1) )
				cout<<"inf"<<endl;
			else cout<<"inf"<<endl;		
		}
	}

	else if( q == -1 )
	{
		if( b1 == -1 || b1 == 1)
		{
			if( find(1) )
				cout<<0<<endl;
			else cout<<"inf"<<endl;			
		}
		else if( b1 == 0)
		{
			if( find(0) )
				cout<<0<<endl;
			else cout<<"inf"<<endl;
		}
		else
		{
			ll b = 0 - b1;
			if( find(b1) && find(b))
				cout<<0<<endl;
			else cout<<"inf"<<endl;
			
		}
	}
	else
	{
		ll sum = 0;
		while( abs(b1) <= l )
		{
			if( !find(b1) )
				sum++;

			b1 = b1 *q;
			//cout<<sum<<endl;
		}		
		cout<<sum<<endl;
	}
	

}
