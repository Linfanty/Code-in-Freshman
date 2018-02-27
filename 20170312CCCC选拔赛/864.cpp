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
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Node
{
	ll num;
	char name[10];
	int score;
}node[maxn];

bool cmp1(Node x, Node y)
{
	return x.num < y.num ;
}

bool cmp2(Node x, Node y)
{
	if( strcmp(x.name ,y.name )!= 0 )
	return strcmp(x.name ,y.name )<0 ;
	else return x.num < y.num ;
}

bool cmp3(Node x, Node y)
{
	if(x.score != y.score )
	return x.score < y.score ;
	else return x.num < y.num ;
}


int main()
{
	fin;
	ll n;
	int c;
	cin>>n>>c;
	for(int i = 0;i<n;i++)
	scanf("%lld %s %d",&node[i].num , node[i].name ,&node[i].score );
	if(c==1)
	sort(node,node+n,cmp1);
	if(c==2)
	sort(node,node+n,cmp2);
	if(c==3)
	sort(node,node+n,cmp3);
	
	for(int i = 0;i<n;i++)
	printf("%06lld %s %d\n",node[i].num , node[i].name ,node[i].score );
	
}
