#include <stdio.h>

/* ���Լ�� */
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

/* ��С������ */
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);
//}

void main()
{
	int n, data[100], g, l;
	int i;
	printf("��������Ϊ:");
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
	printf("���Լ�� = %d\n", g);
//	printf("��С������ = %d\n", l);
system("pause");
}
