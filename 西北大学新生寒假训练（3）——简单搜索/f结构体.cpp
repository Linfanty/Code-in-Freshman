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

//Bfs(ÿ����Ҫ��¼��һ��״̬)������ٵݹ��������·��


/*Ҫ�࿪һ��5*5�����飬����¼ÿһ��������һ����ʲô��
������Լ�¼��һ��������ķ���������Ҳ����ֱ�Ӽ�¼��һ�������ꡣ
��BFSѰ�ҵ����½ǵĵ��ʱ�򣬴����һ���㿪ʼ����ͨ��������������ƣ�
�õ�һϵ�����꣬���Դ����ջ�У�Ҳ����ֱ�ӷ���һ�������У���������Щ����Ϳ����ˡ�*/

int map[maxn][maxn];
bool vst[maxn][maxn]; //���ʱ��
int fang[maxn][maxn];//��¼��һ���ķ�������  
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // x��������
//             00 01 10 11 20 21 30 31 40 41
//int dx[]={1,-1,0,0};// x��������
//int dy[]={0,0,1,-1};// y��������

//0 1��
//0 -1��
//1 0��
//-1 0�� 

//����һ���ṹ�壬��ʾ�����ĵ�·��
struct State
{
	int x,y;
	int step1;
}t,a[30];

bool check(State s)//Լ���������� 
{
	if( !vst[s.x][s.y] && s.x>=0 && s.x <5 && s.y>=0 && s.y <5)
		return 1;
	else 
		return 0;		
}

//���ݽṹ����� �ṹ��st �� �ṹ��t ���β� 
void bfs(State st)
{
	queue <State> q;// BFS ����  
	State now , next;//2��״̬ 
	st.step1=0;//���� 
	q.push(st); //���
	vst[st.x][st.y]=1;//��� 
	int k=0;
	while( !q.empty())
	{
		now = q.front(); //ȡ����Ԫ�ؽ�����չ
		// q.pop();  //ȡ���е���λ,��ɾ����λ
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
	
		for(int i=0;i<4;i++) //for(�о����п��ܵ����)
		{								  //��ȡ��״̬new;
			next.x = now.x + dir[i][0];   //���չ������� 
			next.y = now.y + dir[i][1];   //��һ��״̬
			next.step1 = now.step1 + 1;
		
			if(check(next))  //�����жϺ����� �����״��� 
								/*	if(����������������)
									{�����or���´�;
    							    return;
      	                          }
        	                        vis[new] = vis[now]+1;
      	                          q.push(new);//��״̬�����
        	  		              }
								*/
			{
				fang[next.x ][next.y ] = i;
				q.push(next);   
				vst[next.x ][next.y ]=1; //��� 
			}
		}
			q.pop(); //����Ԫ�س��� 
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
	vst[x][y]=1; // ��Ǹýڵ㱻���ʹ�
	if(map[x][y]==G) // ����Ŀ��̬G
		{
		...... // ����Ӧ����
		return;
		}
	for(int i=0;i<4;i++)
	{
		if(CheckEdge(x+dir[i][0],y+dir[i][1])) // ���չ���������һ���ڵ�
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // û���²������ڵ㣬����
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
