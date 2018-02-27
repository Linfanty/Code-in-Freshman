#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
using namespace std;

char s1[3], s2[3];
int dir[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};// horse
int mp[10][10];

struct node{
    int x, y, step;
};

bool check(int x, int y)
{
    if( x < 0 || y < 0 || x >= 8 || y >= 8 || mp[x][y])
        return false;
    return true;
}

int bfs()
{
    queue<node> q;
    memset(mp, 0, sizeof(mp));
    int sx = s1[0] - 'a', sy = s1[1] - '1';
    q.push(node{sx, sy, 0 });
    int ex = s2[0] - 'a', ey = s2[1] - '1';

    memset(mp, 0, sizeof(mp));
    mp[sx][sy] = 1;
    while( !q.empty())
    {
        node h = q.front();
        q.pop();
        if( h.x == ex && h.y == ey )
            return h.step;

        for(int i = 0; i < 8; ++i)
        {
            int xx = h.x + dir[i][0];
            int yy = h.y + dir[i][1];

            if( xx == ex && yy == ey)
                return h.step + 1;
            if( !check(xx, yy) )
                continue;
            mp[xx][yy] = 1;
            q.push(node{xx,yy, h.step+1});
        }
    }

}


int main()
{
    while(~scanf("%s%s",s1,s2))
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs());
    return 0;
}
