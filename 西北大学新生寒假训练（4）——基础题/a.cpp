#include<cstdio>
typedef long long ll;
using namespace std;
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		ll a,b;
		ll sum=0;
		scanf("%lld %lld",&a,&b);
		for(int i=1;i<a;i++)
		{
			if(a%i == 0)
			sum += i;
		}
		ll s=0;
		
		for(int i=1;i<b;i++)
		{
			if(b%i == 0)
			s += i;
		}
		//printf("%lld %lld   ",sum,s);
		if(sum==b && s==a)
		printf("YES\n");
		else printf("NO\n");
	}
	
}
