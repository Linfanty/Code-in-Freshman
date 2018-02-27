#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 105;

struct Node {
    int x, y, s, t, num;/// 状态和时间 宝物数量
    friend bool operator<(Node a, Node b) {  /// 优先级队列 重载
        return a.t>b.t;
    }
};

int bao[maxn][maxn];// 记录每个宝物的编号
int vit[maxn][maxn][50];
int n, m, sx, sy, ex, ey, k, l;    int ans = inf;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[maxn][maxn];

bool check(int x, int y) {
    if( x >= 0 && x < n && y >= 0 && y < n && mp[x][y] != '#' ) return true;
    return false;
}

void bfs() {

    priority_queue<Node> q;
/// priority_queue<int,vector<int>,greater<int> >que3;////最小值优先  默认最大
    while( !q.empty() ) q.pop();
    q.push( Node{sx, sy, 0, 0, 0});
    vit[sx][sy][0] = 0;

    while( !q.empty() ) {
        Node top = q.top();
        ///Node top = q.front();

        q.pop();
        int x = top.x, y = top.y, s = top.s, t = top.t, num = top.num;


        rep(i, 0, 4)    {
            int nx = x + dx[i], ny = y + dy[i];

            if( !check(nx, ny) ) continue;

            Node next = top;
            next.t = t + 1;

            /// if( bao[nx][ny] != -1 && (next.s & (1<< bao[nx][ny]) ) == 0)
            /// next.s |= (1<< bao[nx][ny]);
            /// next.num++; if( next.t == k) deal with

            if( bao[nx][ny] != -1 && (next.s & (1<< bao[nx][ny]) ) == 0)
            {
                //cout << bao[nx][ny] << ' ' << (1<<bao[nx][ny]) << ' ' << next.s <<endl;
                next.s |= (1<< bao[nx][ny]); /// 001  011
                next.num++;

                if( next.num == k)
                {  //cout << nx << ' ' << ny << ' ' << tt << ' ';
                    ans = min(ans, next.t);
                    return;
                }
            }

            //cout << next.s << ' ' << vit[nx][ny][next.s] << ' ' <<next.t << endl;
            if( vit[nx][ny][next.s] > next.t)
            {
                vit[nx][ny][next.s] = next.t;
                q.push(Node{nx, ny, next.s, next.t, next.num});
            }
        }
    }


}

void init() {//初始化数组，时间为无穷大
    rep(i, 0, n)
        rep(j, 0, m)
            rep(k, 0, l)
                vit[i][j][k] = inf;
}


int main()
{
    int x, y;
    while(~scanf("%d%d", &n, &m), n+m) {
        mem(vit, 0);ans = inf;
        int cnt = 0;
        for(int i = 0; i < n; i++)  {
            scanf("%s", mp[i]);
            for(int j = 0; j < m; j++)  {
                if( mp[i][j] == '@')
                    sx = i, sy = j;
            }
        }

        scanf("%d", &k);
        mem(bao, -1);
        int i;
        for(i = 0, l = 1; i < k; i++) {
            scanf("%d %d", &x, &y);
            bao[x-1][y-1] = i;
            l = l << 1; /// 状态数 100
            /////最多4个宝物，故状态的最大值为1111 l为总的状态数加一
            //cout << x-1 << ' ' <<y-1 <<' ' << i << ' ' << l<<endl;
         }
         init();
         bfs();
         if( ans != inf) printf("%d\n", ans);
                else printf("-1\n");
    }
}

