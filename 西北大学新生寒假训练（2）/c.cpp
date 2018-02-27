#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>

int a[1000][1000];
using namespace std;
int main()
{
	
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		//swap(m,n)
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
				scanf("%d",&a[i][j]);	
		}
	int	max=0;int q=0;int w=0;
			for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
			{
				if(abs(a[i][j])>abs(max))
				{
					q=i;w=j;
					swap(a[i][j],max);
				}
			}
			printf("%d %d %d\n",q,w,max);
	}

return 0;
}
