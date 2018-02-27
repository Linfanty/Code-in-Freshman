#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int sum=0;
		char s[1000];
		scanf("%s",&s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>= '0' && s[i] <= '9')
		sum++;
	}
	printf("%lld\n",sum);
	}
}
