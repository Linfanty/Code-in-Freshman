#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	long long int c;
	long long int m,n;
	while(scanf("%lld",&n)!=EOF)
	while(n--)
	{	
		long long int sum=0;
		scanf("%lld",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%lld",&c);
			sum+=c;
		}
		if(n==0)
		printf("%lld\n",sum);	
		else printf("%lld\n\n",sum);	
		
	}
return 0;
}
