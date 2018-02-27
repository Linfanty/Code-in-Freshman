#include<stdio.h>
#include<string.h>
int main()
{
	long int a,b,n;
	scanf("%lld",&n);
	
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",a+b);
		
	}	
	return 0;
}

