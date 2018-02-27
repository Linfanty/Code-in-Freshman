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

char map[105][105];
//bool vst[105][105]; //���ʱ��
//int fang[105][105];//��¼��һ���ķ�������  
//int dir[4][2]={0,1,0,-1,1,0,-1,0}; // x��������
int dx[]={1,-1,0,0};// x��������
int dy[]={0,0,1,-1};// y��������

//0 1��
//0 -1��
//1 0��
//-1 0�� 

//����һ���ṹ�壬��ʾ�����ĵ�·��
struct State
{
	int x,y;
	int step;
}t,a[30];
/*
bool check(State s)//Լ���������� 
{
	if( !vst[s.x][s.y] && s.x && s.x <5 && s.y && s.y <5)
		return 1;
	else 
		return 0;		
}
*/
struct Node  // BFS�����е�״̬���ݽṹ  
{
	int x,y; //���� 
	int pre; //��������ͳ���� 
}q[105];  //���0���ڵ�λ�ã����ڿ��ƣ�x,y��������

void print(int i)
{
	if(q[i].pre != -1)
	{
		print(q[i].pre );
		printf("(%d,%d)\n",q[i].x ,q[i].y );	
	}
}

void bfs(int x1,int y1)
{
	int front=0,rear=1,m,n;
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
	
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(map,0,sizeof(map));
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d ",&map[i][j]);
	/*	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			printf("%d ",map[i][j]);		*/
	
	printf("(0,0)\n");	
		bfs(0,0);
	printf("(4,4)\n");		
	
	return 0;
}
