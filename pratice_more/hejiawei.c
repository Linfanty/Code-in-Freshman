#include<stdio.h>
int main()
{
	int a=0,n,b=2,sum=0;
	printf("Please enter a number:");
	scanf("%d",&n);
	for(b;b<=n;b++)
	{
		a=10*a+n;
		sum+=a;
	}
    printf("%d\n",sum);
	system("puase");
	return 0;
}
