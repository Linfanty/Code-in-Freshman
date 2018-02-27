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
		
		//1000 s[0][0]=1
		
	//	for(int i=0;i<4;i++)
	//	printf("    %d     ",s[1][i]);       //s[1]  [i]  49 48 48 48
		//0 1 2 3 4 5  
		int i,k; 	
		int q=0,solve=0;//memset(sovle,0,solve);
		for(k=1;k<=M;k++)
		for(i=1000;i<9999;i++) //---9999
		{
			int count=0;
			char array[5];
			int calculation[10],c1[10];
			int calculations[10],c2[10];
			
			memset(calculation,0,sizeof(calculation));
			memset(calculations,0,sizeof(calculations));
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			
			sprintf(array,"%d",i);
			int A=0;
      		for(int j=0;j<4;j++) 
				{
        		if(s[k][j] == array[j]) A++; //相同 
     			}
     			
     		if(A!=b[k])
     		continue;
			/*
			for(int j=0;j<4;j++)
			for(int num=0;num<10;num++)
			{
				if(array[j]-'0'==num)
				calculation[num]++;   //用 calculation[num]表示 从1000开始的循环猜测数列 记录每个数字出现次数  
				
			//	printf("%d %c\n",s[k][j],s[k][j]);
				if(s[k][j]-'0'==num)
				calculations[num]++;	 //用 calculations[num]表示 从input 数z组4815 记录每个数字出现次数
			//	printf("%d %d\n",s[k][j],calculations[num]);
			}
			
			*/
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
				//printf("%d\n",count);
				if(count!=a[k])
				continue;
				else if(A==b[k])
     		    {
					 solve=i;
					 q++;
				}
		//	B=B+min()
			/*
			for(int j=0;j<4;j++)
			{
				if(array[j]==s[k][j])
				count++;
			}
			*/
			
			
			/*
				for(int num=0;num<10;num++)
				{
					printf("%d %d %d\n",calculation[num],calculations[num],a[k]);
					if(calculation[num]==calculations[num]&&calculation[num]==a[k])
					solve[q]=i;
					q++;
					
					
				}
				*/
		}
		//	for(int i=0;i<q;i++)
		//	printf("%d ",solve[i]);
		if(q==1)
		printf("%d",solve);
		else printf("Not sure\n");
	}
	
	return 0;
}
