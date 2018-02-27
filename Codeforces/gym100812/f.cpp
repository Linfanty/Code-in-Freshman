#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 10005;

int g[maxn][maxn], n, m;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
bool vis[maxn][maxn];
int num[maxn];

struct Node
{
    int x, y, step;
    Node(int xx, int yy, int sstep)
    {
        x = xx;
        y = yy;
        step = sstep;
    }
};

bool check(int x, int y)
{
    if( x < 1 || x > n || y < 1 || y > m)
        return false;
    else return true;
}

void bfs()
{
    queue <Node> q;
    memset(vis, false, sizeof(vis));
    q.push(Node(1, 1, 0));
    int len = 1;

    while( !q.empty())
    {
        Node h = q.front();
        int xx = h.x, yy = h.y, step = h.step;

        if( vis[xx][yy] ) continue;
        vis[xx][yy] = true;

		rep(i, 0, 3)
		{
			int xi = xx+dir[i][0];

			int yi = yy+dir[i][1];

			if(check(xi, yi) && !vis[xi][yi] && g[xi][yi] == '.')
			{
			    num[len] ++;
				q.push(Node(xi, yi, len + 1 ));
			}
		}
    }
}


int main()
{//IO;
    cin >> n >> m;
    rep(i, 1, n)
        rep(j, 1, m)
            cin >> g[i][j];

    bfs();
    rep(i, 1, max(n,m) )
        cout << num[i] << endl;
}
