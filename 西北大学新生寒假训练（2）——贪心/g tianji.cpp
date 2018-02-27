#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int tian[1005],king[1005];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF &&n)
	{
		
			for(int i=0;i< n;i++)
				scanf("%d",&tian[i] ); 
			for(int i=0;i< n;i++)
				scanf("%d",&king[i]);
			
			int tf=0,kf=0,count=0;  // tf:tian fastest
			int ts=n-1,ks=n-1;      // ks:king slowest
			sort(tian, tian + n,greater<int>());	
			sort(king, king + n,greater<int>());	
			
			for(int i= 0; i<n ;i++)
			{
				if(tian[tf] > king [kf] )
				{count++; tf++; kf++; continue;}
				else if(tian[tf]<king[kf])
				{count--; ts--; kf++; continue;}
				else if(tian[tf] == king[kf])
				{
					if(tian[ts] > king[ks] )
					{count++; ts--; ks--; continue;}
					else if(tian[ts] < king[ks] )
					{count--; ts--; kf++; continue;}
					else if(tian[ts] == king[ks] )
					{
						if (tian[ts]<king[kf])  // ts 与 kf 比较 终止条件 
						{count--; ts--; kf++; continue;}
					}
				}
			}
			printf("%d\n",count*200);
	}
	
	
return 0;
}
