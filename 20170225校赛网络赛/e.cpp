#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a));
#define fre freopen("in.txt","r",stdin)
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

ll maxn= 1000000000;

int main()
{
	ll n;
	char sum[1005];
	mem(sum,0);
	scanf("%lld",&n);
	//printf("%d\n",strlen(sum));
	
	sum[0]=1;
	for(ll i=2;i<= n;i++)
	{
		int m = strlen(sum)-1;
		
		if(i%4==0)
			sum[m] += 1;
		else if(i%4!=0 && i%2==0)
			sum[m] += i/2;
		else	
			sum[m] += i;
		
		int flag=0;
		int m1=m;
		while(sum[m] >=10  ) 
		{
				
			sum[m]=sum[m]-10;

			m=m-1;
			if(strlen(s)==m1==0)
			flag=1;
		}
		
		if(flag)
		{
			sum[0]=sum[0]-10;
			for(int j=strlen(sum);j>0;j--)
			{
				sum[j]=sum[j-1];
			}
			
			printf("%s\n",sum);
		}
	}
	

	//printf("%lld %lld %lld \n",a[0],a[1],b[1]);
	printf("%s\n",sum);
	
return 0;	
}
