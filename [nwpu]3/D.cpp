#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

bool a(int j)
{
		if(j==1)
		return false;
		int count = 0;
		for(int i=2;i<=sqrt(j);i++)
		{
				if(j%i==0)
			{	
				count=1;
				return false;
			}
		}
		if(count==0)
		return true;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int c=0;
		for(int i=n/2;i<n;i++)
		{
			int j=n-i;
			if(a(i)&&a(j)&&i+j==n&&(i!=j))
			{
				//printf("%d %d\n",i,j);
				c++;
			}
		}
	printf("%d\n",c);
		
	}
}
