#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
using namespace std;
int a[maxn+5][maxn+5];
int left[maxn+5];
int right[maxn+5];
int up[maxn+5];
int down[maxn+5];
int main()
{   int sum=0;
	memset(a,0,sizeof(a));
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	memset(up,0,sizeof(up));
	memset(down,0,sizeof(down));
	int n,m,count=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	   {
	   		for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
	        	if(a[i][j]==1&&count==0)
	        	{
			  	count=1;
			  	left[i]=j;
				}
				if(a[i][j]==1&&count==1)
				{
					right[i]=j;
				}
			}
		count=0;
		}
	count=0;
	for(int j=1;j<=m;j++)
	    {
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==1&&count==0)
	       	 	{
				  	count=1;
				  	up[j]=i;
				}
				if(a[i][j]==1&&count==1)
				{
					down[j]=i;
				}			
			}
		count=0;
	    }
    for(int i=1;i<=n;i++)
	   {
	   		for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					if(left[i]!=0)
					{
					
						if(j<left[i])
						sum++;
						else if(j>left[i]&&j<right[i])
						sum+=2;
						else if(j>right[i])
						sum++;
			        }
				if(up[j]!=0)
					{
						if(i<up[j])
						sum++;
						else if(i>up[j]&&i<down[j])
						sum+=2;
						else if(i>down[j])
 						sum++;
 					}
				}	
			}
		}
 printf("%d",sum);
 return 0;
}

