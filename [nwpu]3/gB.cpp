#include<stdio.h>
#include<string.h>
main()
{
	int T,i,n,a[10],t,m,k,s,p,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		if(n<=9)
		{
			for(p=0;p<=n;p++)
			{
				t=p%10;
				a[t]++;
			}
		}
		else if(n<=99)
		{
			for(p=0;p<=9;p++)
			{
				t=p%10;
				a[t]++;
			}
			for(p=10;p<=n;p++)
			{
				t=p%10;
				m=p/10;
				a[t]++;
				a[m]++;
			}
		}
		else if(n<=999)
		{
				for(p=0;p<=9;p++)
			{
				t=p%10;
				a[t]++;
			}
			for(p=10;p<=99;p++)
			{
				t=p%10;
				m=p/10;
				a[t]++;
				a[m]++;
			}
			for(p=100;p<=n;p++)
			{
				t=p%10;
				m=(p/10)%10;
				k=p/100;
				a[t]++;
				a[m]++;
				a[k]++;
			}
		}
		else
		{
				for(p=0;p<=9;p++)
			{
				t=p%10;
				a[t]++;
			}
			for(p=10;p<=99;p++)
			{
				t=p%10;
				m=p/10;
				a[t]++;
				a[m]++;
			}
			for(p=100;p<=999;p++)
			{
				t=p%10;
				m=(p/10)%10;
				k=p/100;
				a[t]++;
				a[m]++;
				a[k]++;
			}
			for(p=1000;p<=n;p++)
			{
				t=p%10;
				m=(p/10)%10;
				k=(p/100)%10;
				s=p/1000;
				a[t]++;
				a[m]++;
				a[k]++;
				a[s]++;
			}
		}
		for(j=0;j<9;j++)
		printf("%d ",a[j]);
		printf("%d\n",a[9]);
	}
}