#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double a=2.0,b=1.0,d,S=0;
	for (int c = 1;c <= 20;c++)
	{
		S = S + a / b;
		d = b;
		b = a;
		a = a + d;
	}
	printf("%0.2lf is the result\n",S);
	system("pause");
	return 0;
}