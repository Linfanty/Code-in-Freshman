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
	char s[1005];
	gets(s);
	int n = strlen(s);
	int solve = 0 ;
	for(int i= 0;i<n;i++)
	{
		for(int j= n-1;j>=0;j--)
		{
			int sum = 0 ;
			int m = i;
			while(s[i]==s[j] && i<n && j>=0 )
			{
				++i;
				--j;
				++sum;
			}
			solve = max(solve,sum);
			i = m ;
		}
	}
	cout<<solve;
}
