#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define mem(a, b) memset(a, b, sizeof(a)) 
using namespace std;

struct node {
	int x, y;
	vector<int> v;
	node() {}
	node(int i, int j, node n) {
		x = i;
		y = j;
		v = n.v;
		v.push_back(i*10+j);
	}
	node(int i, int j) {
		x = i;
		y = j;
		v.push_back(i*10+j);
	}
};

int mp[10][10], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void bfs() {
	queue<node> q;
	q.push(node(1, 1));
	int vis[10][10];
	memset(vis, 0, sizeof(vis));
	vis[1][1] = 1;
	while (!q.empty()) {
		node t = q.front(); q.pop();
		if (t.x == 5 && t.y == 5) {
			for (int i = 0; i < t.v.size(); i++)
				printf("(%d, %d)\n", (t.v[i]) / 10 - 1, (t.v[i]) % 10 - 1);
		}
		for (int i = 0; i < 4; i++) {
			int xx = t.x + dx[i];
			int yy = t.y + dy[i];
			if (mp[xx][yy] && !vis[xx][yy]) {
				vis[xx][yy] = 1;
				q.push(node(xx, yy, t));
			}
		}
	}
}//习惯在while循环里面先判断跳出条件再入队
//出队肯定是每次while循环刚要进行一次的


int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	mem(mp, 0); 
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++){
			scanf("%d", &mp[i][j]);
			mp[i][j] = !mp[i][j];
		}
	bfs();
}

