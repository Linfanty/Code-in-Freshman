#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=6;
bool vst[maxn][maxn]; // ���ʱ��
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // ��������   �ң����ϣ���
int migong[maxn][maxn];
int fang[maxn][maxn];//��¼��һ���ķ�������

struct State // BFS �����е�״̬���ݽṹ
{
	int x,y; // ����λ��
	int Step_Counter; // ��������ͳ����
};

State t,a[30];

bool CheckState(State s) // Լ����������
{
	if(!vst[s.x][s.y] && s.x>=0 && s.x<5 && s.y>=0 && s.y<5) // ��������
		return 1;
	else // Լ��������ͻ
		return 0;
}

void bfs(State st)
{
	queue <State> q; // BFS ����
	State now,next; // ����2 ��״̬����ǰ����һ��
	st.Step_Counter=0; // ����������
	q.push(st); // ���
	vst[st.x][st.y]=1; // ���ʱ��
	int k=0,i,j;
	while(!q.empty())
	{
		now=q.front(); // ȡ����Ԫ�ؽ�����չ
		if(now.x==4 && now.y==4) // ����Ŀ��̬����ʱΪStep_Counter ����Сֵ�������˳�����
		{
			printf("%d\n",now.Step_Counter); // ����ش���
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
			next.x=now.x+dir[i][0]; // ���չ�������	��һ��״̬
			next.y=now.y+dir[i][1];
			next.Step_Counter=now.Step_Counter+1; // ��������1
			if(CheckState(next)) // ���״̬����Լ�����������
			{
				fang[next.x][next.y]=i;
				q.push(next);
				vst[next.x][next.y]=1; //���ʱ��
			}
		}
		q.pop(); // ����Ԫ�س���
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

