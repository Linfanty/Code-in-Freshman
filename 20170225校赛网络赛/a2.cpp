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

int main()
{
	//freopen("in.txt","r",stdin);
	char s[10005];
	int a[10005];
	while(gets(s))
	{
		int i;
		int n=strlen(s);
		for(i=0;i<strlen(s);i++)
		a[i]=((s[i]+10)*4-3)%10;
		
		for(i=0;i<n;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
