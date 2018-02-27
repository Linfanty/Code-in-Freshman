#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
bool check(ll num)
{
while(num)
{
	if(num%10==4)
	return false;
	else if(num%10==2 && num/10%10 == 6)
	return false;
	num=num/10;
}
return true;
}

int main()
{
	ll n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF && n)
	{
		ll sum=0;
		for(ll i=n;i<=m;i++)
		{
			//printf("%lld  %lld\n",n,m);
			//printf("%lld  ",i);
			if( check(i) )
			{
				//printf("%lld  ",i);
				sum++;
			}
		}
		printf("%lld\n",sum);
	}
}
