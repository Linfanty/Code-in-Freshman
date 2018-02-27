#include <cstdio>
#include <cstdlib>

int main()
{
	int n;
	char s[20];
	scanf("%d", &n);
	int sum = 0, op = 0;
	for(; n--;)
	{
		int num;
		scanf("%s %d", s, &num);
		if(s[0] == 'A')
		{
			if(num < 0)
				op = abs(num) - 1;
			else
				op = 0;
		}
		else if(s[0] == 'S')
		{
			if(num <= 0)
				op = 0;
			else
				op = num - 1;
		}
		else if(s[0] == 'D')
		{
			if(num <= 0)
				op = 100;
			else
				op = 100 - 100 / num;
		}
		else if(s[0] == 'M')
		{
			if(num < 0)
				op = 100;
			else
				op = 0;
		}
		sum += op;
	}
	printf("%d\n", sum);
	
	return 0;
}
