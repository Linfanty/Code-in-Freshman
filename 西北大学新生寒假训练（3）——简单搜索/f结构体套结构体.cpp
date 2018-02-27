#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;
int map[6][6];
struct ss {
    int x , y;
};
struct TnT {
    deque<ss>mm;
};
int vis[6][6] , dr[4][2] = {1 , 0 , -1 , 0 , 0 , 1 , 0 , -1};
TnT bfs(int x , int y) {
    memset(vis , 0 , sizeof(vis));
    TnT gg;
    ss gl;
    gl.x = x , gl.y = y;
    vis[x][y] = 1;
    gg.mm.push_back(gl);
    queue<TnT>q;
    q.push(gg);
    while(!q.empty()) {
        TnT ml = q.front();
        ss xg = ml.mm.back();
        if(xg.x == 4 && xg.y == 4) {
            return ml;
        }
        for(int i = 0 ; i < 4 ; i++) {
            TnT sg = ml;
            ss xl = ml.mm.back();
            xl.x += dr[i][0];
            xl.y += dr[i][1];
            if(xl.x >= 0 && xl.x < 5 && xl.y >= 0 && xl.y < 5 && !map[xl.x][xl.y] && !vis[xl.x][xl.y]) {
                vis[xl.x][xl.y] = 1;
                sg.mm.push_back(xl);
                q.push(sg);
            }
        }
        q.pop();
    }
    return q.front();
}
int main()
{
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            cin >> map[i][j];
        }
    }
    TnT q = bfs(0 , 0);
    while(!q.mm.empty()) {
        ss sl = q.mm.front();
        q.mm.pop_front();
        cout << "(" << sl.x << ", " << sl.y << ")" << endl;
    }
    return 0;
}
