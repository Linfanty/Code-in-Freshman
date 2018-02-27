//bfs
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
#define FIN freopen("in.txt", "r", stdin)
using namespace std;
typedef long long LL;
const int N = 10;

int n, m, G[N][N];
int pre[N*N];     //����ǰ�����
int roadx[N*N], roady[N*N];     //·�������
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
bool vis[N][N];

struct Node{
    int id, x, y;
    Node(int _id, int _x, int _y){
        id = _id;
        x = _x;
        y = _y;
    }
};
bool judge(int x, int y){
    if(x < 1 || x > 5 || y < 1 || y > 5)    return false;
    return true;
}
void outPut(int p){
    if(pre[p] == -1){
        cout << "(0, 0)" << endl;
    }
    else{
        outPut(pre[p]);     //���ǵ�һ���㣬�����������֮ǰ�ĵ�
        cout << "(" << roadx[p]-1 << ", " << roady[p]-1 << ")" << endl;
    }
}
void bfs(){
    queue <Node> Q;
    memset(vis, false, sizeof(vis));

    int len = 0;        //�����
    pre[len] = -1;      //ǰ��
    roadx[len] = 1;     //·������
    roady[len] = 1;

    Q.push(Node(len++, 1, 1));
    vis[1][1] = true;
    while(!Q.empty()){
        Node h = Q.front();
        Q.pop();

        int idd = h.id, xx = h.x, yy = h.y;
        if(xx == 5 && yy == 5){     //�ҵ��յ㣬ֱ�����
            outPut(idd);
            return ;
        }
        for(int i = 0;i < 4;++ i){
            int xi = xx+dir[i][0];
            int yi = yy+dir[i][1];

            if(judge(xi, yi) && G[xi][yi] == 0 && !vis[xi][yi]){
                pre[len] = idd;
                roadx[len] = xi;
                roady[len] = yi;
                vis[xi][yi] = true;
                Q.push(Node(len++, xi, yi));

            }
        }
    }
}
int main()
{
    //FIN;
    for(int i = 1;i <= 5;++ i){
        for(int j = 1;j <= 5;++ j)  cin >> G[i][j];
    }
    bfs();
    return 0;
}
