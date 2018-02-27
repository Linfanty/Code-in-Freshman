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

int main()
{
	ll n;
	int num[maxn];
	int vis[100]={0};
	cin>>n;
	
	for(int i = 0 ;i<n;i++)
	{
	
		cin>>num[i];
		++vis[num[i]];
	}
	sort(num,num+n);
	for(int i = 0 ;i<n;i++)
	{
		if(i>0 && num[i]==num[i-1])
		continue;
		cout<<num[i]<<":"<<vis[num[i]]<<endl;
	}
	
}
