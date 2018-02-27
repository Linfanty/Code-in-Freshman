#include<stdio.h>
#include<string.h>
char a[12][12];
char b[12][12];
int cut(int i,int j)
{
	int m=0;
	if(a[i-1][j]=='*')
	m++;
	if(a[i-1][j-1]=='*')
	m++;
	if(a[i-1][j+1]=='*')
	m++;
	if(a[i][j-1]=='*')
	m++;
	if(a[i][j+1]=='*')
	m++;
	if(a[i+1][j]=='*')
	m++;
	if(a[i+1][j-1]=='*')
	m++;
	if(a[i+1][j+1]=='*')
	m++;
	return m;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d%*c",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]);
		
		for(int i=1;i<=n;i++)
			scanf("%s",b[i]);
		
		int flag=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
				if(b[i][j]=='x' && a[i][j]=='*')
				flag=1;	
		if(flag==0)
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
			{
				if(b[i][j]=='x')
					{
						printf("%d",cut(i,j));
					}
				else printf(".");
				if(j==n-1)
				printf("\n");
			}
		else 
			for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
			{
				if(a[i][j]=='*')
					printf("*");
				else if(b[i][j]=='x' && a[i][j]=='.')
						printf("%d",cut(i,j));
				else  printf(".");
				if(j==n-1)
				printf("\n");
			}
	}
	return 0;
}
