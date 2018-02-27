#include<stdio.h>
#include<string.h>
main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char a[55];
	int M,i,n,j,sum,b[5];
	scanf("%d ",&M);
	for(i=0;i<M;i++)
	{
		memset(a,0,sizeof(a));
		for(j=0;j<5;j++)
		b[j]=0;
		
		sum=0;
		gets(a);
		n=strlen(a);
		for(j=0;j<n;j++)
		{
			if(a[j]>='A'&&a[j]<='Z')
			b[1]=1;
			if(a[j]>='a'&&a[j]<='z')
			b[2]=1;
			if(a[j]>='0'&&a[j]<='9')
			b[3]=1;
			if(a[j]=='~'||a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$'||a[j]=='%'||a[j]=='^')
			b[4]=1;
		}
      if(n>=8&&n<=16) 
      {
      	for(j=1;j<=4;j++)
      	{
		if(b[j]==1) sum++;
      	//printf("%d %d %d %d\n",b[j]);
		}
		  if(sum>=3) printf("YES\n");
      	else printf("NO\n");
	  }
      else
      printf("NO\n");
	}
}
