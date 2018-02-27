#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		char s[105][5];
		int M=N;
		int n;
		int a[105],b[105];
		
		while(N--)
		{
			scanf("%d %d %d",&n,&a[M-N],&b[M-N]);
			sprintf(s[M-N],"%d",n);
		//	printf("%s %d %d %d %d %d %d\n",s[M-N],s[M-N][0],s[M-N][1],s[M-N][2],s[M-N][3],a[M-N],b[M-N]);
		}
		int i,k; 	
		int q=0,solve=0;
		for(k=1;k<=M;k++)
		for(i=1000;i<2000;i++) 
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
     		continue;

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
				continue;
				else if(A==b[k])
     		    {
					 solve=i;
					 q++;
					 printf("%d ",solve);
				}
		}
	//	if(q==1)
		printf("%d\n",solve);
	//	else printf("Not sure\n");
	}
	
	return 0;
}
		
