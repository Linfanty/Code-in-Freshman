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
int cnt;//已放棋子的数目  
int sum;//放置方法的总数  
int n,k;  
void dfs(int now,int cnt)  
{  
    if(cnt==k)
	{     sum++;  return ;   }
	
    for(int i=now;i<n;i++)//枚举一行 
	  for(int j=0;j<n;j++)
        if(map[i][j]=='#'&&!vis[j]) //一列已经放过了 
		{  
        	 vis[j]=1;//标记该列已放棋子
    		 dfs(i+1,cnt+1);//继续搜索  
    	     vis[j]=0;//重置成false，它有可能出现在下一次搜索的别的路径中 
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
