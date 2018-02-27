#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int S = 1010;
int n,m;
int q,sx,sy,dx,dy;
int grid[S][S],Min[S][S];
const int dirx[4]={-1,1,0,0},diry[4]={0,0,-1,1};

typedef struct {
    int x,y,dir,turn;
}point;

queue<point>que;

//��P�ܲ�����
inline bool check(point &P){
    if(P.x>=1&&P.x<=n&&P.y>=1&&P.y<=m) return true;
    return false;
}

bool bfs(){
    point cur,next;
    while(que.size()){
        cur = que.front();
        //cout<<"x:"<<cur.x<<" y:"<<cur.y<<" dir:"<<cur.dir<<" turn:"<<cur.turn<<endl;
        que.pop();
        if(cur.x==dx&&cur.y==dy&&cur.turn<=2) return true;
        for(int i=0;i<4;i++){
            //��ǰ��������һ��ĳ���һ����ת��
            if(cur.dir!=i){
                next.dir=i;
                next.turn=cur.turn+1;
            }
            else{
                next.dir=cur.dir;
                next.turn=cur.turn;
            }
            if(next.turn>2) continue;//һ�������ϣ���֦
            next.x=cur.x+dirx[i],next.y=cur.y+diry[i];
            /*Min[next.x][next.y]>=next.turn,����Ҫע������ط���">="��������">"*/
            if(check(next)&&(!grid[next.x][next.y]||(next.x==dx&&next.y==dy))&&Min[next.x][next.y]>=next.turn){
                que.push(next);
                Min[next.x][next.y]=next.turn;
            }
        }
    }
    return false;
}

int main(){
    while(scanf("%d %d",&n,&m)&&(n||m)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%d",&grid[i][j]);
        }
        //������Գɹ�����
        //Print();
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d %d",&sx,&sy,&dx,&dy);
            //cout << sx << sy << dx << dy << endl;
            //��ʼɸѡ
            if((grid[sx][sy]!=grid[dx][dy])||!grid[sx][sy]||!grid[dx][dy]||(sx==dx&&sy==dy)){
                printf("NO\n");
                continue;
            }
            while(que.size()) que.pop();
            memset(Min,1,sizeof(Min));
            point start;
            start.x=sx,start.y=sy,start.turn=0;
            //���������ܷ�������Ŀ��㣬�Ȱ����ַ������������ȥ����Ȼ������鷳
            for(int i=0;i<4;i++){
                start.dir=i;
                que.push(start);
            }
            Min[sx][sy]=0;
            if(bfs()) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
