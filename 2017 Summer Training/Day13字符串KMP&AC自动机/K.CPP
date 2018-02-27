#include<stdio.h>
// 哇 这题竟然放最后一道 有毒 公式之前弄出来的
int main()
{
	int n, m;
	while( scanf("%d%d", &n, &m)!=EOF && n )
	{
		int s=0;
		for(int i = 2;i <= n; i++)
            s= (s+m) %i;
		printf("%d %d %d\n", n, m, s+1);
	}
}
