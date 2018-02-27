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
	ll a[10005]={10,9,8,7,6,5,4,3,2,1,0};
	

	
		
	sort( a+2, a+5 );
	// sort 结尾 要 多加一 9 6 7 8 5 4 3 2 1 0
	
	rep( i, 1, 10)
			cout << a[i] <<' ';
			
			cout<<endl;
	
}
