#include<stdio.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int a=0,b=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a<b)
			b=a;
		}
		printf("%d\n",(100-b)*(100-b));
	}
}
