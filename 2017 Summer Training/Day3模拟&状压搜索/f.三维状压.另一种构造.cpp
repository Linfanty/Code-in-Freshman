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
    int x, y, t, key, snake;
};

bool vit[maxn][maxn][10][40];
int n, m, sx, sy, ex, ey;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[maxn][maxn];

bool check(int x, int y) {
    if( x >= 0 && x < n && y >= 0 && y < n && mp[x][y] != '#' ) return true;
    return false;
}

void bfs() {
    int ans = inf;
    mem(vit, 0);
    queue<Node> q;
    while( !q.empty() ) q.pop();
    q.push( Node{sx, sy, 0, 0, 0});

    while( !q.empty() ) {
        Node top = q.front();
        q.pop();
        int x = top.x, y = top.y, t = top.t, key = top.key, snake = top.snake;

        if( key == m && mp[x][y] == 'T')
            {ans = min(ans, t);  continue;}

        if( vit[x][y][key][snake] != 0)
            continue;
        vit[x][y][key][snake] = 1;

        rep(i, 0, 4)    {
            int nx = x + dx[i], ny = y + dy[i];

            if( !check(nx, ny) ) continue;

            Node NEXT = top;// 不能用top top四  次更新 会覆盖原来的


            /// if( bao[nx][ny] != -1 && (next.s & (1<< bao[nx][ny]) ) == 0)
            /// next.s |= (1<< bao[nx][ny]);
            /// next.num++; if( next.t == k) deal with


            if( mp[nx][ny] >= 'A' && mp[nx][ny] <= 'G') ///five shakes
            {
                int s = mp[nx][ny] - 'A';
                if( ( 1 << s ) & NEXT.snake )  ;// 如果蛇被打了
                else {
                    //cout << NEXT.snake <<' ' << (1<<s) <<' ';  0 & 1 = 0
                    NEXT.snake |= ( 1<<s ); // 没被打  NEXT.snake |= ( 1<<s )
                    //cout << NEXT.snake << endl;
                    NEXT.t++;
                }
            }
            else if( mp[nx][ny] - '0' == key + 1) /// key
                NEXT.key ++;
            NEXT.t++;
            q.push(Node{nx, ny, NEXT.t, NEXT.key, NEXT.snake});
        }
    }

    if( ans != inf) printf("%d\n", ans);
    else printf("impossible\n");
}


int main()
{
    while(~scanf("%d%d", &n, &m), n+m) {
        int cnt = 0;
        for(int i = 0; i < n; i++)
             scanf("%s", mp[i]);

        for(int i = 0; i < n; i++) {
             for(int j = 0; j < n; j++) {
                 if(mp[i][j] == 'K') sx = i, sy = j;
                 if(mp[i][j] == 'S') {mp[i][j] = cnt+'A'; cnt++;}
             }
         }
         bfs();
    }
}

3 2
K#T
.S.
21.

ANS = 8 