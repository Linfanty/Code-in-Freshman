#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
#define maxn 40
const int N = 2e5 + 10;
using namespace std;

char s[10][10];
bool vit[10][10];
int dir[2][4] = {0,1,0,-1,1,0,-1,0};
struct Node
{
    int x, y, st;
    Node(){}
    Node(int xx, int yy, int idd)
    {
        x = xx, y = yy, st = idd;
    }
};

bool check(int x, int y)
{
    if( x < 1 || x > 5 || y < 1 || y > 5 || vit[x][y] == 1 || s[x][y] == '1')
        return false;
    return true;
}

void bfs()
{
    mem(vit);
    queue<Node(x, y, 0)> q;
    vit[x][y] = 1;

    while( !q.empty())
    {
        Node h = q.front();
        q.pop();
        int xx = h.x, yy = h.y, stt = h.st;
        vit[xx][yy] = 1;

        rep(i, 0, 3)
        {
            int xi = xx + dir[0][i];
            int yi = yy + dir[1][i];
            if( !check(xi, yi) )
                q.push(Node(xi, yi, stt+1));
        }
    }
}

int main()
{IO;
    cin >> t;
    while( t-- )
    {
        rep(i, 1, 5)
            rep(j, 1, 5)
                cin >> s[i][j];

        rep(i, 1, 5)
            rep(j, 1, 5)
                if( s[i][j] == '1')
                    bfs(i, j);

    }

}
