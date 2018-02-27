#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int pre[1000];
int total;
bool t[1000];

int find (int x)		//查找根节点 
{
	int r = x;
	while( pre[r] != r)
		r = pre[r];		//返回根节点 
		
		int i = x, j;
		
	while( i!=j)   		//路径压缩 
	{
		j = pre[i];		//上级j 
		pre[i] = r;		//把i上级改为根节点 
		i = j;			//递归迭代 
	}
	return r;
}

void join( int x, int y) //判断连通  合并
{
	int fx = find(x);
	int fy = find(y);
	//如果是不连通的，那么把这两个分支连起来
    //分支的总数就减少了1，还需建的路也就减了1
	if( fx != fy)	
		pre[fx] = fy;
}

int main()  
{  
    int N,M,a,b,i,j,ans;  
    while(scanf("%d%d",&N,&M)&&N)  
    {  
        for(i=1;i<=N;i++)          //初始化   
            pre[i]=i;  
          
        for(i=1;i<=M;i++)          //吸收并整理数据   
        {  
            scanf("%d%d",&a,&b);  
            join(a,b);  
        }  
          
          
        memset(t,0,sizeof(t));  
        for(i=1;i<=N;i++)          //标记根结点  
        {  
            t[find(i)]=1;  
        }  
        for(ans=0,i=1;i<=N;i++)  
            if(t[i])  
                ans++;  
                  
        printf("%d\n",ans-1);     
    }  
    return 0;  
}




