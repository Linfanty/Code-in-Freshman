#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
main()
{
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	long long int a,b,c,m,n,ans;
	while(scanf("%I64d%I64d%I64d",&a,&b,&c) !=EOF)
	{
	
	scanf("%I64d%I64d",&m,&n);
	if(a+c>m&&b+c<=n)
	ans=m;
	if(b+c>n&&a+c<=m)
	ans=n;
	if(a+c>m&&b+c>n)
    ans=min(m,n);
	if(a+c<=m&&b+c<=n)
	ans=a+b+c;
	printf("%I64d\n",ans);
	}
}
