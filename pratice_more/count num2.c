#include <stdio.h>
int main()
{
	static int a[51];
	int n=100;
	int i;
	int num;
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个数字：",i);
		while(1)
		{
			if(scanf("%d",&num)&&num>=1&&num<=50)
			{
				a[num]++;
				break;
			}
			else
			{
				printf("输入错误，重输：");
				fflush(stdin);
			}
		}
	}
	for(i=1;i<=50;i++)
	{
		if(a[i])
			printf("%d:%d\n",i,a[i]);
	}
	return 0;
}
