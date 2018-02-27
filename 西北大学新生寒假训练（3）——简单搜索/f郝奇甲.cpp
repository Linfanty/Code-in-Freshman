#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define mid ((l+r)>>1)
#define ls (id<<1)
#define rs ((id<<1)|1)
#define N 10
#define INF 0x3f3f3f3f
#define INFF ((1LL<<62)-1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PIR;
/*
�Ǹ������ʾ���ĸ������������ң�
���赱ǰ����  (x , y)��
��ô���Ϸ��ľ��� (x-1, y),
�����(x, y-1),ͬ���±ߺ��ұߡ�����
Ȼ����� (0, 1),(0, -1)������һ��һ��������ԭ�� (x, y)�ϱߣ�
��ô�ĸ�����ĵ������ȫ֪����
*/


int pre[N*N], G[N][N], dir[4][2] = {0,1,0,-1,1,0,-1,0};
bool vis[N][N];
vector <PIR> road;

struct Node{
	int x, y, id;
	Node (int _id, int _x, int _y){
		id = _id; x = _x; y = _y;
	}
};


void Output(int id){
	
	if(pre[id] == -1)
	
		cout << "(0, 0)" << endl;
	
	else
	{
		Output(pre[id]);
		cout << "(" << road[id].first-1 << ", " << road[id].second-1 << ")" << endl;
	}
	return ;
}


bool judge(int x, int y)
{
	
	if(x < 1 || x > 5 || y < 1 || y > 5)	return false;
	return true;
	
}

void bfs(){
	
	queue <Node> Q;
	mem(vis, false);
	
	int len = 0;  //�ڵ��� 
	pre[len] = -1; //ǰ�� 
	
	
	
	road.push_back(PIR(1, 1));
	Q.push(Node(len++, 1, 1));  // ��ֵ д�������� 
	
	while(!Q.empty())
	
	{
		Node h = Q.front();
		Q.pop();

		int xx = h.x, yy = h.y, id = h.id;
		
		if(xx == 5 && yy == 5)
		{
			Output(id);
			return ;
		}

		if(vis[xx][yy])	continue;
		
		vis[xx][yy] = true;
		
		rep(i, 0, 3)
		{
			int xi = xx+dir[i][0]; 
			
			int yi = yy+dir[i][1];
			
			if(judge(xi, yi) && !vis[xi][yi] && !G[xi][yi])
			
			{
				pre[len] = id;
				
				road.push_back(PIR(xi, yi));
				
				Q.push(Node(len++, xi, yi));
			}
		}
	}
	return ;
}


int main()
{IO;
	//FIN;
	rep(i, 1, 5){
		rep(j, 1, 5)	cin >> G[i][j];
	}
	bfs();
	return 0;
}
