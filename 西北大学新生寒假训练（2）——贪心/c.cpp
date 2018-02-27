#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;

struct Node
{
	ll c;
	ll d;
}node[100001];

bool cmp(Node x,Node y)
{
	if(x.d == y.d ) return x.c < y.c ;
	return x.d < y.d ;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		ll m;
		scanf("%lld",&m);
		for(int j=0;j<m;j++)
			scanf("%lld %lld",&node[j].c  ,& node[j].d );
		
		sort(node, node +m, cmp);
		ll max = 0;
		ll mid =0;
		ll count=0;
		for(int j=0;j<m;j++)
		{
			//if(node[j].d >= mid)
			{
				count+= node[j].c ;
				mid = count- node[j].d;
				if(count- node[j].d  >max)
				swap(mid,max);
			}
		}
		printf("Case %lld: %lld\n",i,max);
	}
	return 0;
}
