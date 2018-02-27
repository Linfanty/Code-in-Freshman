#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1||n==2)
		printf("1\n");
	 else printf("-1\n");
	}
	return 0;
}
