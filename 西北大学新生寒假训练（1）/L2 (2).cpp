#include<stdio.h>
#include<string.h>
main()
{
	int N,M,a[510][510],t[510],i,m,n,p,c[510],j; //**
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		memset(c,0,sizeof(c));

		for(i=1;i<=M;i++)
		{
		scanf("%d%d",&m,&n);
		if(a[m][n]==0)
		{
		a[m][n]=1;
	    t[n]++;
	}
	}
		int k=0;  //***
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(t[j]==0)
		    {
			p=j;   //P == TOP  
			break;
			}
		}
		c[k++]=p;//***
		t[p]=-1;
		
		for(j=1;j<=N;j++)
		if(a[p][j])
		t[j]--;
	}
	for(i=0;i<k-1;i++)
	printf("%d ",c[i]);
	printf("%d\n",c[k-1]); //***
	}
}
