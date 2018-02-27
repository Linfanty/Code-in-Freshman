#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
	int n;
	char a[55];
	while(scanf("%d",&n)!=EOF)
	{getchar();
	
	while(n--)
	{
		
		//scanf("%s",a);
		gets(a);
		int sum =0;
		int m=1;
		//	printf("%c\n",a[0]);
			
		if(isalpha(a[0])==0 && a[0]!='_')  
		{
			printf("no\n");
			continue;
		}
	 		
		for(int i=1;i<strlen(a);i++)
		{
			if(isalnum(a[i]) || a[i]=='_' )
			{
			sum++;
			}else 	{m=0; printf("no\n");break;	}
		}

	     if(m&&(sum+1==strlen(a)))
		printf("yes\n"); 
	}
	}

return 0;
}
