#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
	int m,n;
	int a[105];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		memset(a,0,sizeof(a));
		
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);

		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{if(abs(a[i])>abs(a[j]))
		swap(a[i],a[j]);
		}
		
		for(int i=0;i<n;i++)
		{
		if(!i)
		printf("%d",a[i]);
		else printf(" %d",a[i]);
		if(i==n-1)
		printf("\n");
		
		}	
	}

return 0;
}
