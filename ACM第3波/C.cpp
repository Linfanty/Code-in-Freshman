#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
using namespace std;
int main()
{
	int n,count=0,j=0,i=0;
	char a[maxn+5];
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(a[i]!='o')
		printf("%c",a[i]);
		else 
		{
			if((a[i+1]=='g')&&(a[i+2]=='o'))
			{
				printf("***");
				//count=0;
				j=i+3;
				while((a[j]=='g')&&(a[j+1]=='o'))
						j=j+2;
			i=j-1;	
			}
			else printf("o");
		}
	}
return 0;
}
