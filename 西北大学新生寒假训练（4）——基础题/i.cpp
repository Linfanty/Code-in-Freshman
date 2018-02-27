#include<stdio.h>
int main()
{
	int a,b;
	long long int s[100];
	while(scanf("%d %d",&a,&b)!=EOF&&a)
	{
		int j=0;
		for(int i=0;i<100;i++)
			{
				if((a*100+i)%b==0)
				{
					s[j]=i;
					j++;	
				}					
			}
		for(int i=0;i<j;i++)
		{
			if(!i)
			printf("%02d",s[i]);
			else printf(" %02d",s[i]);
			if(i==j-1)
			printf("\n");
		}	
	}
	return 0;
}
