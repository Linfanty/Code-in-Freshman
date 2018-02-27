#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
using namespace std;
int main()
{
	
int a[maxn+5];
int l[maxn+5];
int r[maxn+5];
int c=0;
int sum=0;
memset(a,0,sizeof(a));
memset(l,0,sizeof(l));
memset(r,0,sizeof(r));
	int n,m,j=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
		for(j=l[i];j<=r[i];j++)
		c+=a[j];
	
		if(c>=0)
		{   
			for(j=1;j<=n;j++)		
			if(j>=l[i]&&j<=r[i])
			sum+=a[j];
		}
		c=0;
	}
	printf("%d",sum);
	return 0;
}
