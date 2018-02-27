#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=6;
bool vst[maxn][maxn]; // 访问标记
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // 方向向量   右，左，上，下
int migong[maxn][maxn];
int fang[maxn][maxn];//记录上一步的方向向量

struct State // BFS 队列中的状态数据结构
{
	int x,y; // 坐标位置
	int Step_Counter; // 搜索步数统计器
};

State t,a[30];

bool CheckState(State s) // 约束条件检验
{
	if(!vst[s.x][s.y] && s.x>=0 && s.x<5 && s.y>=0 && s.y<5) // 满足条件
		return 1;
	else // 约束条件冲突
		return 0;
}

void bfs(State st)
{
	queue <State> q; // BFS 队列
	State now,next; // 定义2 个状态，当前和下一个
	st.Step_Counter=0; // 计数器清零
	q.push(st); // 入队
	vst[st.x][st.y]=1; // 访问标记
	int k=0,i,j;
	while(!q.empty())
	{
		now=q.front(); // 取队首元素进行扩展
		if(now.x==4 && now.y==4) // 出现目标态，此时为Step_Counter 的最小值，可以退出即可
		{
			printf("%d\n",now.Step_Counter); // 做相关处理
			a[k++]=now;
			next=now;
			while(1)
			{
				switch(fang[now.x][now.y])
				{
					case 0:
						next.y=now.y-1;
						break;
					case 1:
						next.y=now.y+1;
						break;
					case 2:
						next.x=now.x-1;
						break;
					case 3:
						next.x=now.x+1;
				}
				a[k++]=next;
				now=next;
				if(next.x==0&&next.y==0)
                    break;
			}
			k--;
			while(k>=0)
			{
				printf("(%d, %d)\n",a[k].x,a[k].y);
				k--;
			}
			return;
		}
		for(int i=0;i<4;i++)
		{
			next.x=now.x+dir[i][0]; // 按照规则生成	下一个状态
			next.y=now.y+dir[i][1];
			next.Step_Counter=now.Step_Counter+1; // 计数器加1
			if(CheckState(next)) // 如果状态满足约束条件则入队
			{
				fang[next.x][next.y]=i;
				q.push(next);
				vst[next.x][next.y]=1; //访问标记
			}
		}
		q.pop(); // 队首元素出队
	}
 	return;
}

int main()
{
		freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			scanf("%d",&migong[i][j]);
			if(migong[i][j]==1)
			{
				vst[i][j]=true;
			}
		}
	t.x=0;
	t.y=0;
	bfs(t);
 	return 0;
}

