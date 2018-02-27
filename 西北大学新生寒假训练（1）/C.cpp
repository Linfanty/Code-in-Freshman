#include<stdio.h>
#include<string.h>
int main()
{
	long long int a,b,n,c;
	scanf("%lld",&n);
	
	while(n--)
	{
		getchar();
		scanf("%lld%lld",&a,&b);
		c=a+b;
		printf("%lld\n",c);
		
	}	
	return 0;
}

