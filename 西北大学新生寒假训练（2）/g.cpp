#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>

using namespace std;
int main()
{
	char s[105];

	while(gets(s))
	{
		//getchar();
		printf("%c",s[0]-32);
			
			for(int i=1;i<strlen(s);i++)
			{
				if(isalpha(s[i]) && s[i-1]==' ')
				printf("%c",s[i]-32);
				else printf("%c",s[i]);
			}
			printf("\n");
	}

return 0;
}
