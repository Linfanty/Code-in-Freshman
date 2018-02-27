#include<stdio.h>
#include<string.h>
int main()
{
	long long int a,b,n,c;

	while(	scanf("%lld%lld",&a,&b) !=EOF)
	{
		if(a==0&&b==0)
		break ;
		c=a+b;
		printf("%lld\n",c);
		
	}	
	return 0;
}

