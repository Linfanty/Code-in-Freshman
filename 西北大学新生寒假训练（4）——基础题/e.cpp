#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
int main()
{
	int m,n;
	scanf("%d",&m);
	while(m--)
	{
		int a[505];
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		sort(a,a+n);
		
		ll sum=0;
	//	if(n&1)
		for(int i=0;i<n;i++)
		{
			sum += abs(a[i]-a[n/2]);
		}
	/*	else
		for(int i=0;i<n;i++)
		{
			sum += abs(a[i]-a)
		}
	*/	
		printf("%lld\n",sum);
	}
}
