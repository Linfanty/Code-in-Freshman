#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	int a[105];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0)
		break;
		memset(a,0,sizeof(a));
		a[n]=m;
		
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n+1);
		
		for(int i=0;i<=n;i++)
		{
		if(!i)
		printf("%d",a[i]);
		else printf(" %d",a[i]);
		if(i==n)
		printf("\n");
		
		}	
	}

return 0;
}
