#include<stdio.h>
#include<string.h>
long long int a[25][25];

int solve(int m,int n)
{
	if(m<n)  return 0;
	else	if(m==0) return 0;
	else	if(n==0||m==1) return 1;
	else    return  
	solve(m-1,n)+solve(m,n-1);
	
}

int main()
{
	//for(int )
	
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
				printf("%lld\n",solve(m,n));
}
