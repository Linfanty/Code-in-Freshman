#include <cstdio>
using namespace std;
#define fin freopen("in.txt","r",stdin);

int main()
{
	fin;
	int n, k;
	int a[105] = {0};
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		int num;
		char s[20];
		scanf("%d %s", &num, s);
		if(s[0] == 'S')
		{
			a[num] = 1;
			for(int t = 1; t <= num; t++)
				a[t] = 1;
		}
		else
		{
			a[num] = -1;
			for(int t = num; t <= k; t++)
				a[t] = -1;
		}
	}
	int l = 0, h = 0;
	for(int i = 1; i <= k; i++)
	{
		if(a[i] == 1)
		{
			l = i + 1;
		}
	}
	for(int i = k; i > 0; i--)
	{
		if(a[i] == -1)
		{
			h = i - 1;
		}
	}
	if(l == 0)
	{
		for(int i = k; i > 0; i--)
		{
			if(a[i] == -1)
			{
				l = i;
			}
		}
	}
	if(h == 0)
	{
		for(int i = 0; i <= k; i++)
		{
			if(a[i] == 1)
			{
				h = i;
			}
		}
	}
	
	printf("%d %d", l, h);
	
	return 0;
}
