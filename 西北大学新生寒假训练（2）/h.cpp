#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	int a[105];
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		int ans=0;
		for(int i=0;i<n;i++)
		{
		scanf("%d",&a[i]);	
		ans+= a[i];
		}	
	
		printf("%d\n",ans);
	
		
		
	}

return 0;
}
