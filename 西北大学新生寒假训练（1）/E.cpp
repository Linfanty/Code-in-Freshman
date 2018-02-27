
#include<stdio.h>

int main()
{   int n;
    scanf("%d",&n);
 //   n=n+1;
	while(n--)
	{
		long long int sum=0,x=0,m=0;
		scanf("%lld",&m);
		while(m--)		
		{
			scanf("%lld",&x);
				sum+=x;
		}
		printf("%lld\n",sum);
   }
	return 0;
}

