#include <stdio.h>

/* 最大公约数 */
int gcd(int a, int b)
{
	int t;
	if(a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

/* 最小公倍数 */
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);
//}

void main()
{
	int n, data[100], g, l;
	int i;
	printf("数据总数为:");
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &data[i]);
	}
	g = data[0];
	for(i = 1; i < n; ++i)
		g = gcd(g, data[i]);
	l = 1;
	for(i = 0; i < n; ++i)
		l *= data[i] / g;
	l *= g;
	printf("最大公约数 = %d\n", g);
//	printf("最小公倍数 = %d\n", l);
system("pause");
}
