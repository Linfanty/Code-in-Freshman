
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
int main()
{
	cin >> s;
	int f = s.find("happiness");
	string ss = s.substr(f + 1);
	int rf = f + 1 + ss.find("happiness");
	int rrf = f + 1 + ss.rfind("happiness");
	if(f >= 0)
	{
		if(f == rf)
		{
			printf("YES\n");
			printf("%d %d\n", f + 3, f + 8);
		}
		else if(f != rf && rf == rrf)
		{
			printf("YES\n");
			printf("%d %d\n", f + 3, rf + 8);
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		int ok = 1;
		for(int c = 'a'; c <= 'z'; c++)
		{
			int cc = s.find(c), rcc = s.rfind(c);
			if(cc != rcc)
			{
				ok = 0;
				printf("YES\n");
				printf("%d %d\n", cc + 1, rcc + 1);
				break;
			}
		}
		if(ok)
		{
			printf("YES\n");
			printf("1 2\n");
		}
	}

	return 0;
}
