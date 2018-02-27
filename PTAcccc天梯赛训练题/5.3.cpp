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

int main()
{
	char s1[maxn];
	char s2[maxn];
	gets(s1);
	//getchar();
	gets(s2);
	ll n = strlen(s1);
	ll m = strlen(s2);
	for( ll i =0 ;i<n;i++)
	{
		int flag=0;
		for( ll j = 0 ;j<m;j++)
		{
			if(s1[i]==s2[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag==1)
		continue;
		else
		cout<<s1[i];
	}
}
