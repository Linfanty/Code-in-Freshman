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
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;i+=2)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int main()
{
	int  n;
	cin >> n;
	
	if( n == 2)
	cout << 1 << endl << 1;
	else if( n == 3)
	cout << 2 << endl << "1 3";
	else if( n == 4)
	cout << 4 << endl << "2 4 1 3";
	else //if( n == 4) 
	{
		cout << n << endl;
		cout << 1 ;
		rep(i, 3, n)
		{
			//if(i%2 == 1)
			//	cout << i << ' ';
			//else cout << i << ' ';
			cout << ' '<< i;
		}
		rep(i, 2, n)
			cout <<' '<< i;
		
			
	}
	
	
	return 0;
}


