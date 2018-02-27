#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;

int main()
{
	int a[1000] , b[1000];
	int s[10000];
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		int count =0;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[a[i]+1+count] =  1 ;
			count++;
		}
		
		int k=1;
		int sum=0;
		for(int i=1;i<=(a[n]+count);i++)
		{
			sum=0;
			if(s[i]==1)
				for(int j=i-1; j>=1 ; j--)
				{
					
					if(s[j]==0)
					{
						s[i] = 100;
						s[j] = -1;
					
						b[k] = i-j-sum;
						k++;
						break;
					}
					else if(s[j]==100)
					sum++;
					
				}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			printf("%d",b[i]);
			else printf(" %d",b[i]);
			if (i==n)
			printf("\n");
		}
		
		
	}
return 0;
}
