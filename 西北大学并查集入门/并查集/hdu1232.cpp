#include <cstdio>
#include <iostream>
using namespace std;

int pre[1000];
int total;

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
	}// i = j = pre[i] = r ;
	return r;
}

void join( int x, int y, int &t) //判断连通  合并
{
	int fx = find(x);
	int fy = find(y);
	//如果是不连通的，那么把这两个分支连起来
    //分支的总数就减少了1，还需建的路也就减了1
	if( fx != fy)	
		{
			pre[fx] = fy;	
			t--;		
		}
}

int main()
{
	int n, m, p1, p2, i, f1, f2;
	while(scanf("%d %d",&n,&m) && n)
	{
		//刚开始的时候，有n个城镇，一条路都没有 
		//那么要修n-1条路才能把它们连起来
		total = n-1;
		for( int i = 1; i<=n; i++)
		//每个点互相独立，自成一个集合，从1编号到n
			pre[i] = i;  //所以每个点的上级都是自己
		//scanf("%d", &m); //共有m条路
		while(m--) 	//join函数 
		{
			scanf("%d %d",&p1,&p2);
			int f1 = find(p1);
			int f2 = find(p2);
			if( f1 != f2)
			{
				pre[f2] = f1;
				total --;
			}
		}
		cout<<total<<endl;
	}
}




