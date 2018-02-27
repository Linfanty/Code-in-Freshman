#include<string.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<map>
#include<set>
typedef long long ll;
const int maxn = 105;
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll Y,n;
		scanf("%lld %lld",&Y,&n);
		while(Y)
		{
			if((Y%4==0 && Y%100!=0) || Y%400==0)
				n--;
				Y++;
				if(!n)
				break;
					
		}
	
		printf("%lld\n",Y-1);
	}
}
