#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
const int maxn = 10;
#include <climits>
using namespace std;

int main()
{
	int t,n;
	ll maxx=LONG_MIN,maxy=LONG_MIN;
	ll minx=LONG_MAX,miny=LONG_MAX;
	ll x,y;
	cin>>n;
	while(n--)
	{
	
		cin>>x>>y;
		if(x>maxx)
		maxx=x;
		if(y>maxy)
		maxy=y;
		if(x<minx)
		minx=x;
		if(y<miny)
		miny=y;
	}
	ll Max=max(maxx-minx,maxy-miny);
	cout<<Max*Max;
	return 0;
}
