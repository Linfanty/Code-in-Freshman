#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

char mp[1005][1005];
int n, m;

struct node {
	int x, y, status, step;
	node() {};
	node(int xx, int yy) {
		x = xx;
		y = yy;
	}
	node(int xx, int yy, int s) {
		x = xx;
		y = yy;
		status = s;
		step =0;
	}
	node(int xx, int yy, int s, int ss) {
		x = xx;
		y = yy;
		status = s;
		step = ss;
	}
};

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[20][1005][1005];
queue<node> q;

void bfs() {
	mem(vis, 0);
	while (!q.empty()) {
		node tmp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tmp.x + dx[i], yy = tmp.y + dy[i];
			int s = tmp.status, ss = tmp.step;

			if (mp[xx][yy] == '#') {
				printf("%d\n", tmp.step + 1);
				return;
			} 
			else if (mp[xx][yy] == '*') continue; 
			else if (mp[xx][yy] >= '5' && mp[xx][yy] <= '8') {
				int t = mp[xx][yy] - '5';
				t = pow(2, t);
				s |= t;
				if (vis[s][xx][yy]) continue;
				vis[s][xx][yy] = true;
				q.push(node(xx, yy, s, ss + 1));
				continue;
			}
			else if (mp[xx][yy] >= '1' && mp[xx][yy] <= '4') {
				int t = mp[xx][yy] - '1';
				t = pow(2, t);
				if (!(t & s)) continue;
				else {
					if (vis[s][xx][yy]) continue;
					vis[s][xx][yy] = true;
					q.push(node(xx, yy, s, ss + 1));
					continue;
				}
			}
			else {
				if (vis[s][xx][yy]) continue;
				vis[s][xx][yy] = true;
				q.push(node(xx, yy, s, ss + 1));
				continue;
			}
		}
	}
	puts("-1"); 
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while (~scanf("%d%d", &n, &m)) {
		while (!q.empty()) q.pop();
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= m + 1; j++)
				mp[i][j] = '*';
		for (int i = 1; i <= n; i++) {
			getchar();
			for (int j = 1; j <= m; j++) {
				scanf("%c", &mp[i][j]);
				if (mp[i][j] == '0')
					q.push(node(i, j, 0));
			}
		}
		bfs();
	}
} 
