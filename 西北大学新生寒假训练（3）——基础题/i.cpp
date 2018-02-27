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
int main()
{
//	freopen("in.txt","r",stdin);
//	freoprn("out.txt","w",stdout);
	ll a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		int c[5];
		c[1]=a%10;
		ll sum=c[1]*c[1];
		for(int i=2;i<5;i++)
		{
			c[i]=sum%10;
			sum=c[i]*c[1];
		}
		//printf("%d %d %d %d %d\n",c[0],c[1],c[2],c[3],c[4]);
		printf("%d\n",b%4==0?c[4]:c[b%4]);
	}
	return 0;
}
