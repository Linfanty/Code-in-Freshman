#include<stdio.h>
int main()
{
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int a=200,b=200;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a<b)
			b=a;
		}
		printf("%d\n",(100-b)*(100-b));
	}
}
