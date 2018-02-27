#include<algorithm>
#include<sstream>
#include<iostream>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
#include<stdio.h>
typedef long long ll;
const int maxn = 10;
using namespace std;

//Bfs(每个点要记录上一个状态)，最后再递归地输出最短路径


/*要多开一个5*5的数组，来记录每一个坐标上一步是什么。
这里可以记录上一步到这里的方向向量，也可以直接记录上一步的坐标。
当BFS寻找到右下角的点的时候，从最后一个点开始向上通过这个数组往回推，
得到一系列坐标，可以存放在栈中，也可以直接放在一个数组中，最后输出这些坐标就可以了。*/

int map[maxn][maxn];
bool vst[maxn][maxn]; //访问标记
int fang[maxn][maxn];//记录上一步的方向向量  
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // x方向向量
//             00 01 10 11 20 21 30 31 40 41
//int dx[]={1,-1,0,0};// x方向向量
//int dy[]={0,0,1,-1};// y方向向量

//0 1右
//0 -1左
//1 0上
//-1 0下 

//定义一个结构体，表示经过的点路径
struct State
{
	int x,y;
	int step1;
}t,a[30];

bool check(State s)//约束条件检验 
{
	if( !vst[s.x][s.y] && s.x>=0 && s.x <5 && s.y>=0 && s.y <5)
		return 1;
	else 
		return 0;		
}

//传递结构体变量 结构体st 是 结构体t 的形参 
void bfs(State st)
{
	queue <State> q;// BFS 队列  
	State now , next;//2个状态 
	st.step1=0;//归零 
	q.push(st); //入队
	vst[st.x][st.y]=1;//标记 
	int k=0;
	while( !q.empty())
	{
		now = q.front(); //取队首元素进行扩展
		// q.pop();  //取队列的首位,并删除首位
		/*if(now==G)
		{
			...
			return;
		}
		*/
		if(now.x ==4 && now.y ==4)
		{
		//	printf("%d\n",now.step1 );
			a[k++] = now;
			next = now;
			while(1)
			{
				switch(fang[now.x ][now.y ])
				{
					case 0: next.y =now.y -1; break;
					case 1: next.y =now.y +1; break;
					case 2: next.x =now.x -1; break;
					case 3: next.x =now.x +1; //break;
				}
				a[k++]=next;
				now=next;
				if(next.x == 0 && next.y ==0) break;
			}
			
			
			k--;
			while(k>=0)
			{
				printf("(%d, %d)\n",a[k].x ,a[k].y );
				k--;
			}
			return ;
		}	
	
		for(int i=0;i<4;i++) //for(列举所有可能的情况)
		{								  //获取新状态new;
			next.x = now.x + dir[i][0];   //按照规则生成 
			next.y = now.y + dir[i][1];   //下一个状态
			next.step1 = now.step1 + 1;
		
			if(check(next))  //事先判断好条件 降低易错性 
								/*	if(满足题中所给条件)
									{输出答案or更新答案;
    							    return;
      	                          }
        	                        vis[new] = vis[now]+1;
      	                          q.push(new);//新状态入队列
        	  		              }
								*/
			{
				fang[next.x ][next.y ] = i;
				q.push(next);   
				vst[next.x ][next.y ]=1; //标记 
			}
		}
			q.pop(); //对手元素出列 
	}
		return;
	/*
	q[front].x = x1;
	q[front].y = y1;
	q[front].pre = -1;
	while(front<rear)
	{
		for(int i=0;i<4;i++)
		{
			m = q[front].x + dx[i];
			n = q[front].y + dy[i];
			if(m<0 || n<0 || n>4 || map[m][n])
			continue;
			else
			{
				map[m][n]=1;
				q[rear].x =m;
				q[rear].y =n;
				q[rear].pre =front;
				rear++ ;
			}
			if(m==4 && n==4)
			print(front);
		}
		front++;
	}
	*/
}
/*

void dfs(int x,int y)
{
	vst[x][y]=1; // 标记该节点被访问过
	if(map[x][y]==G) // 出现目标态G
		{
		...... // 做相应处理
		return;
		}
	for(int i=0;i<4;i++)
	{
		if(CheckEdge(x+dir[i][0],y+dir[i][1])) // 按照规则生成下一个节点
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // 没有下层搜索节点，回溯
}

*/

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(map,0,sizeof(map));
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			{
				scanf("%d ",&map[i][j]);
				if(map[i][j]==1)
					vst[i][j]=true;
			}
			
	/*	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			printf("%d ",map[i][j]);*/	
	t.x = 0;  t.y = 0;
	bfs(t);
	/*printf("(0,0)\n");	
		bfs(0,0);
	printf("(4,4)\n");		
	*/
	return 0;
}
