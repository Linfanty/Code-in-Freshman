//dfs
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<stdio.h>
typedef long long ll;
const int maxn = 105;
using namespace std;

char map[10][10];
int vis[10];
int cnt;//�ѷ����ӵ���Ŀ  
int sum;//���÷���������  
int n,k;  
void dfs(int now,int cnt)  
{  
    if(cnt==k)
	{     sum++;  return ;   }
	
    for(int i=now;i<n;i++)//ö��һ�� 
	  for(int j=0;j<n;j++)
        if(map[i][j]=='#'&&!vis[j]) //һ���Ѿ��Ź��� 
		{  
        	 vis[j]=1;//��Ǹ����ѷ�����
    		 dfs(i+1,cnt+1);//��������  
    	     vis[j]=0;//���ó�false�����п��ܳ�������һ�������ı��·���� 
    	}     
} 
int main()
{
    while(scanf("%d %d%*c",&n,&k))
	{
		//getchar();
		if(n==-1)
		break;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
   		cnt=sum=0;
        dfs(0,0);
        printf("%d\n",sum);
    }
    return 0;
}
