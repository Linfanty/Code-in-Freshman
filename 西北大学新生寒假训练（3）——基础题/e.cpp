#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<math.h>
typedef long long ll;
const int maxn = 105;
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF && n && m )
	{
		for(int i=sqrt(2*m);i>0;i--)
		{
			ll a1 = m/i - (i-1) /2;
			if((2*a1+i-1) *i==2*m)
			printf("[%lld,%lld]\n",a1,a1+i-1);
		/*	if(m%i==0)
			{
				ll k=m/i
				for(ll j=m/i;;j++)
				{
					if(j)
				}
			}
			printf("[%lld,%lld]\n",m/i-i/2,m/i+i/2);
			else 	printf("[%lld,%lld]\n",m/i-1,m/i+2);*/
			
		}
		printf("\n");
	}

return 0;
}
