#include<stdio.h>
#include<string.h>
char s[105][5];
		int a[105],b[105];
		int solve=0;
		int final=0;
		
bool deal(int M,int i)
{
	int q=0;
	//solve=0;
	for(int k=1;k<=M;k++)
	{
			int count=0;
			char array[5];
				
			sprintf(array,"%d",i);
			int A=0;
      		for(int j=0;j<4;j++) 
				{
        		if(s[k][j] == array[j]) A++; //ÏàÍ¬ 
     			}
     			
     		if(A!=b[k])
     		return false;

			int isy[100];
			memset(isy,1,sizeof(isy));
			for(int j=0;j<4;j++)
			for(int num=0;num<4;num++)
			{
				if(s[k][num]==array[j]&&isy[num])
				{
						count ++;
						isy[num]=0;
						break;
					
				}
			}
				if(count!=a[k])
				return false;
				else 
				q++;
				
				if(q==M)
				{
					solve=i;
					final++;
				//	printf("%d     ",solve);
					return true; 
				}

	}	
}
int main()
{
	int N,M,n;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
		break;
		int w=0;
		final=0;
		solve=0;
		M=N;
		while(N--)
		{
			scanf("%d %d %d",&n,&a[M-N],&b[M-N]);
			sprintf(s[M-N],"%d",n);
		}

		for(int i=1000;i<9999;i++) 
		{
			if ( deal(M,i) )
			{
				w++;
				continue;
			}
			
		}
			
		if(w==1&&final==1)
		printf("%d\n",solve);
		else printf("Not sure\n");
	}
	
	return 0;
}
		
