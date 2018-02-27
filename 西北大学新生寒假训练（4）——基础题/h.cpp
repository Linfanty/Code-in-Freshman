#include<stdio.h>
#include<math.h>
int prime(int m)
{
	if(m==2||m==3) return 1;	
	else 
	for(int i=sqrt(m);i>1;i--)
	{
		if(m%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int sum=0;
		for(int i=n/2;i>1;i--)
		{
			int j=n-i;
			if(prime(i)&&prime(j)&&i!=j)
			{
				//printf("%d %d\n",i,j);
				sum++;
			}
		
		}
	printf("%d\n",sum);
	}
}
