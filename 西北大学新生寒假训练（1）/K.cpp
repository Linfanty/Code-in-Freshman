#include<stdio.h>
#include<string.h>
bool cmp(char s[])
{
		char s1[10005];
		char s2[10005];
	    int	count=0,k,q,w;
		for(int i=0;i<strlen(s)/2;i++)
		{
	//		s1[i]=s[strlen(s)-i-1];
			
			if(s[i]==s[strlen(s)-i-1])
			count++;
		}

		if(count == strlen(s)/2)
		return false;
		else return true;
}
//回文字的处理
/*void deal(char s[])
{
		char s1[10005];
		char s2[10005];
		memset(s2,0,sizeof(s2));
	    int	count=0,k=0;
		for(int i=0;i<strlen(s);i++)
			s1[i]=s[strlen(s)-i-1];
		


			for(int i=0;i<strlen(s);i++)
			{
			//	printf("%c %c %c \n",s[i],s1[i],s2[i]);
				s2[i]=s[i]+s1[i]+k-'0';
				printf("%c %c %c \n",s[i],s1[i],s2[i]);
				//break;
				k=0;
				if(s2[i]>'9')
					{
					k=s2[i]/10;
					s2[i]=s2[i]%10;
					}
			}	
//	for(int i=0;i<=strlen(s);i++)
		printf("%s\n",s2);
		strcpy(s,s2);
}
*/
long long int  deal(char s[])
{
	long long int a,b;
	
		char s1[10005];
		memset(s1,0,sizeof(s1));
		for(int i=0;i<strlen(s);i++)
			s1[i]=s[strlen(s)-i-1];
			
	sscanf(s,"%lld",&a);
	sscanf(s1,"%lld",&b);
//	printf("%lld %lld\n",a,b);
	return a+b;
}
int main()
{
	long long int n,m;
	char s[100005],s2[10005];
	while(scanf("%lld",&n)!=EOF)
	{
		int num=0;
		sprintf(s,"%lld",n);
		strcpy(s2,s);
		while ( cmp(s2) )//如果不是回文字 
		{
			m=deal(s2);
			num++;
			sprintf(s2,"%lld",m);
		}
		printf("%d\n",num);
		
			
		while ( cmp(s) )//如果不是回文字 
		{
			printf("%s--->",s);	 
			n=deal(s);
			sprintf(s,"%lld",n);
		}
		printf("%s\n",s);

		 
	}
	
return 0;
}

