#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
bool prime(int m)
{
		if(m==2||m==3)
		return true;
		for(int i=2;i<=sqrt(m);i++)
		{
			if(m%i==0)
			return false;
		}
		return true;
}
int main()
{
	int N;	
	scanf("%d",&N);

	while(N--)
	{
		int n;
		scanf("%d",&n);
		int sum=n;
		for(int i=2;i<=n;i++)
		{
			if(n%i==0&&prime(i))
			sum*=(1.0-1.0/i);
		}
		printf("%d\n",sum);
	}	
	return 0;
} 
