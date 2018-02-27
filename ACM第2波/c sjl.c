#include<stdio.h>
int main()
{
  int n;long long min_sum,max_r2;long long q;long long max_r=0;
  long long  x1,y1,x2,y2;
  scanf("%lld%lld%lld%lld%lld",&n,&x1,&y1,&x2,&y2);
  int x[n],y[n];
  long long r1[n],r[n];
  for(int i=0;i<n;i++)
  {
  	scanf("%d%d",&x[i],&y[i]);
  	r[i]=(x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1);
  	r1[i]=(x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1);
   
  }
  for(int i=0;i<n;i++)
  {  long long  temp;
  	for(int j=i+1;j<n;j++)
  	{
  		if(r[i]<r[j])
  		{
  			temp=r[i];
  			r[i]=r[j];
  			r[j]=temp;
		  }
	  }
  }
  min_sum=r[0];
  max_r2=0;
  for(int i=1;i<n;i++)
  {
  	for(int j=0;j<i;j++)
  	{ 
		for(int t=0;t<n;t++)
  		{ if(r[j]==r1[t])
		  { q=(x[t]-x2)*(x[t]-x2)+(y[t]-y2)*(y[t]-y2);
		    if(q>max_r2)
			max_r2=q;
		    break;
		  }
		}
	}
		if(min_sum>(r[i]+max_r2))min_sum=(r[i]+max_r2);
  }
  for(int i=0;i<n;i++)
  { q=(x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2);
  if(q>max_r)max_r=q;
  }
  if(min_sum>max_r)min_sum=max_r;
  printf("%lld",min_sum);
  return 0;
} 
