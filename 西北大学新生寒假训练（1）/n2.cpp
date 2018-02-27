#include<stdio.h>
#include<string.h>

int main()
{
	long long int s[25][25];
	
	 memset(s,0,sizeof(s));
   for(int i=0;i<=25;i++)
        s[i][0]=1;
        
		for(int j=1;j<=20;j++)
			for( int i=1;i<=20;i++)
			{
				if(i<j)
				continue;
			//break;
				s[i][j]=s[i-1][j]+s[i][j-1];
			}
			
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
			printf("%lld\n",s[m][n]);
}
