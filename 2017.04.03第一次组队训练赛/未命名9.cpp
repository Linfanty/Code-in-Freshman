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
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	char s[55];
	cin >> s ;
	int n = strlen(s);
	
	int cnt = 0;
	int solve = -1;
	
	for(int i = 0; i < n ; i++)
	{
		for(int j = i+1 ; j < n ; j++ )
		{
			while(s[j] > s[i] )
			{
				++cnt;
				++j;
			}
			
		}
	}
	

	
	return 0;
}
