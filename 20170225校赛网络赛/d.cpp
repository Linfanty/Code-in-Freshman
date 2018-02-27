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
#define maxn 1000000005
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem memset(a,b,sizeof(a));
#define fre freopen("in.txt","r",stdin)
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

int main()
{
	ll n,l;
	ll a[maxn],b[maxn];
	scanf("%d",&n)
	{
		ll cnt==0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		
		}
			
		l=a[0];
		
		for(int i=1;i<n;i++)
		{
			cnt++;
			if(b[i-1]==1 && b[i] == 0 )
			{
				if(a[i]<a[i-1])
				{
					cnt--;
					l = a[i-1];
					continue;	
				}	
				else
				{
					r = a[i];
					cnt--;
					continue;
				}
			}
			
			if(b[i-1]==1 && b[i]== 1)
			{
				
			}
				
		
		}	
		
	}
	
	return 0;
}



