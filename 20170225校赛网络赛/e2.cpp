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


ll solve(ll m)
{
	ll sum=0;
	if(m==0)
	return 0;
	if(m==1)
	return 1;
	else if(m%4==0)
		{
			//printf("%d  %d ",( m/4 ) *((m/4-1)/2 +1 )/2 , (m/8)   );	
			if(m/4==1)
			return 1;
			else if(m==8)
			return 2;
			/*if((m/4)%2==0)
			{sum = (m/8)+1 ;  	printf("1  %lld\n",sum);}
			else {sum = (3 + m/4 ) *(m/4-1)/2/ 2; printf("2   %lld\n",sum); } 
			return sum;
			*/
			else if((m/4)%2==0)
			sum = ( m/4 ) *((m/4-1)/2 +1 )/2  ;
			else sum = (1 + m/4 ) *((m/4-1)/2 +1 )/2  ;
			
			if((m/8) %2  == 0)
			sum += (m/8) /2 +  (m-8, ) /8 ;
		
		} 
	else if(m%2==0)
		return 	(1+m/2)*(m+2)/4/2;
	else
		return  (1+m)*(m+1)/4 ;
		
}

int main()
{
	ll n;
	while(	scanf("%lld",&n)!=EOF)
	{
		if(n==1)
		printf("1\n");
		else if(n==2)
		printf("2\n");
		else if(n%2==0)
		printf("%lld\n",solve(n) + solve(n-1) + solve(n-2));
		else 
		printf("%lld\n",solve(n) + solve(n-1) + solve(n-3));
		
		printf("%lld %lld %lld %lld \n",solve(n) , solve(n-1) ,solve(n-2) ,solve(n-3));
		
	}
return 0;	
}
