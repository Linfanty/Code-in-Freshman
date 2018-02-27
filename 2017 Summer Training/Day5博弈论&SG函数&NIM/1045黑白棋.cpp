/// 敌对搜素
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i <= b; i++)
const int maxn = 40005;

int chess[7][7];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int t;

int dfs(int x, int y)   {
    chess[x][y] = 1;
    rep(i, 0, 3)
    if(  chess[ x + dx[i]] [y + dy[i]] == 0
       && dfs(x + dx[i], y + dy[i]) == 0 )
        {
            chess[x] [y] = 0;
            return 1;
        }
    chess[x][y] = 0;
    return 0;
}

int main()  {
    int _;
    scanf("%d", &_);
    rep(i, 0, 6)
        chess[i][0] = chess[i][6] = chess[0][i] = chess[6][i] = 1;
    while( _-- ) {

        rep(i, 1, 5)
            rep(j, 1, 5)
                scanf("%1d", &chess[i][j]);

        int flag = 0;
        rep(i, 1, 5)
            rep(j, 1, 5)
                if( chess[i][j] == 0 &&  dfs(i, j)  == 0)
                    { flag = 1; break;}

        if( flag )
            puts("win");
        else puts("lose");
    }

}
