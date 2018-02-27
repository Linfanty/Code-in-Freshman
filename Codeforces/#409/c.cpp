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

ll a[100005] = {0};
ll b[100005] = {0};
double c[100005] = {0};

int main()
{
	ll max1 = 0, q, w;
	ll n, p;
	cin >> n >> p;

	rep(i, 1, n)	
	{
		cin >> a[i] >> b[i];
		c[i] = (double) b[i] / a[i];
		if((double) a[i] / b[i] > max1)
		{
			max1 = (double)a[i] / b[i];
			q = a[i];	
			w = b[i];
		} 
	}	
	
	if(n == 1)
	{
	 	if( p >= a[1])
		 	cout << -1 <<endl;
		else cout << (double) (a[1] - q ) / b[1] ; 	
		exit(0);
	}
	else
		
	sort (c+1, c+n+1);
	
	//rep(i, 1, n)
	//{
	//	cout << c[i] << ' ';
		
	//}	
	a[1] = q;
	b[1] = w;
	
	cout << c[2] * p << endl << (double)b[1] <<endl << c[1] * a[1]<< endl;
	cout << (double) c[2] * p + (double) b[1] -(double) a[1] * c[2] <<endl ;//0.4 
	//c[1] * c[2] //2.4 -
	//c[2] * p  // 2.0 +
	//b[1] // 1.0 + 
	
	//0.6   c[2] * p + b[1] - c[1] * c[2] 
	double	sum = c[2] * p + b[1] - a[1] * c[2] ;
	sum = sum / a[1] ;
	
	sum += c[2];
	cout << sum << endl;
	
}



