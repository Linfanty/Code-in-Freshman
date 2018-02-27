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
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll fac(int n)
{	
	ll sum = 1 ;
	if(n==1)
	return 1 ;
	for(int j = 2 ;j <= n ; j++)
	{
		sum = sum * j ;
	}
	return sum;
}
int main()
{
	ll a[105];
	for(int i = 1 ;i<=100 ; i++)
	{
		a[i] = fac(i);
	}
	
	ll n,m;
	cin>>n;
	for(int i = 1 ; i <= n ;i ++)
	{
		m += a[i];
	}
	cout<<m;
}
