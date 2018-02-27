#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
using namespace std;

struct Node
{
	long int c;
	long int v;  
}node[maxn+5];

bool cmp(Node x,Node y)
{
	return x.c <y.c ;
}
int main()
{
	int count=0;
	long int sum=0;
	long int max,time=0;
	long int g[maxn+5];
	memset(g,0,sizeof(g));	
	long int n,k,s,t;
	scanf("%ld %ld %ld %ld",&n,&k,&s,&t);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%ld %ld",&node[i].c ,&node[i].v);
	}
	    
	for(int i=1;i<=k;i++)
	{
		scanf("%ld",&g[i]);
	}
	sort(node+1,node+n+1,cmp);
	sort(g+1,g+k+1);
	
	g[0]=0;
	g[k+1]=s;
	
	if(g[1]-g[0]<g[k+1]-g[k])
	max=g[k+1]-g[k];
	else max=g[1];

	/*
		for(int i=1;i<=n;i++)
	{
		printf("%ld %ld\n",node[i].c ,node[i].v);
	}
	    
	for(int i=1;i<=n;i++)
	{
		printf("%ld\n",g[i]);
	}
    */ 
    for(int i=1;i<=k;i++)
    {
    	if(g[i]-g[i-1]>max)
    	max=g[i]-g[i-1];
	}
//	for(int i=1;i<=n;i++)
//	{
//		if(max>=node[i].v)
//	}
//	printf("%d",node[n].v);
//	printf("%d",max);
	
//	if(node[n].v<max)
//			count=1;
//	if(node[n].v>=max)
	for(int i=1;i<=n;i++)
	{
				time=0;
				count=0;
		if(node[i].v<max)
		{
			count=1;
			continue;
		}
		if(node[i].v>=max)
		for(int j=1;j<=k+1;j++)
		{  
			sum=(g[j]-g[j-1]);
		
			if(node[i].v== sum	)
			time+=2*sum;
			else if(node[i].v>sum&&node[i].v<2*sum )
			time+=3*sum-node[i].v;
			else if(node[i].v>=2*sum)
			time+=sum;
			
		}
		
		if(time<=t)
		{
			printf("%ld",node[i].c);
			break;
		}
		if(i==n)
		count=1;
	}
	if(time>t||count==1)
	printf("-1");
	
	return 0;
}
