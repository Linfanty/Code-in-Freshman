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
	ll n, r, l, a[10005]={0}, b[10005]={0};
	cin >> n >> l >> r;
	
	rep( i, 1, n)
		cin >> a[i];
	rep( i, 1, n)
		cin >> b[i];
		
	sort( a+l, a+r+1 );
	sort( b+l, b+r+1 );
	
	//rep( i, 1, n)
	//		cout << a[i] <<' '<< b[i]<<endl;
			
	//		cout<<endl;
	int flag = 0;
	rep( i, l, r)
	{
	//	cout << a[i] <<' '<< b[i]<<endl; 
		if( a[i] != b[i])
		{
			cout<<"LIE";
			flag = 1;
			break;	
		}	
	}
	
	if( flag == 0)
		cout << "TRUTH";
	
}
