#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	char a[105];
	char s;
	while(scanf("%s",a)!=EOF)
	{
		s=a[0];
		for(int i=0;i<strlen(a);i++)
		{
		if(a[i]>=s)
		s=a[i];
		}
			
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]==s)
			printf("%c(max)",a[i]);
			else printf("%c",a[i]);
			
		}
	printf("\n");
	
	}
return 0;
}
