#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
typedef long long ll;
const int maxn = 105;
using namespace std;
ll fac(int n)
{
	if(n==1) return 1;
	else if(n==2) return 2;
	else return fac(n-2)+fac(n-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	/*ll s[51]={1,2};
	for(int i=2;i<=50;i++)
	s[i]=s[i-1]+s[i-2];*/
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		
	//	printf("%lld\n",s[n-1]);
	printf("%lld\n",fac(n));
	}
	return 0;
}
