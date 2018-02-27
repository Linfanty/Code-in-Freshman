//ËØÊı 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*bool cmp1(result x,result y)
{
	if(x.num ==y.num)
	return 
	strcmp(x.name,y.name)<0?1:0;
	
	else return x.num>y.num; 
}
*/
bool a(int j)
{
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
{   int k=2;
	int n,q,w;
	while(scanf("%d",&n)!=EOF)
	{int min=10005;
		for(int i=n/2;i<=n;i++)
		{
			int j=n-i;
			if(a(i)&&a(j)&&i+j==n)
			{
				printf("%d %d\n",j,i);
				break;
			}
		}
	
	}
	return 0;
}
