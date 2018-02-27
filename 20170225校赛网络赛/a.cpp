#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define maxn 100
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem memset(a,b,sizeof(a));
#define fre freopen("in.txt","r",stdin)
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

char s[10001];
int main()
{
	fre;
	while( scanf("%s",s)!=EOF )
	{
		for(int i=0;i<strlen(s);i++)
		printf("%d",((s[i]+10)*4-3)%10);
		printf("\n");
	}
	return 0;
}
