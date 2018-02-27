#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int m,n;

string ma[507];
int a[507][507];

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int vis[507][507];

struct node{
    int x,y,num,step;
    node(){};
    node(int xx,int yy,int nnum,int sstep):x(xx),y(yy),num(nnum),step(sstep){};
};

queue<node>q;

bool bfs(){
    node now;
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x==m-1&&now.y==n-1){
            printf("%d",now.step);
            return true;
        }
        for(int i=0;i<4;i++){
            int xx=now.x+dx[i]*now.num;
            int yy=now.y+dy[i]*now.num;
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&vis[xx][yy]==0){
                vis[xx][yy]=1;
                q.push(node(xx,yy,a[xx][yy],now.step+1));
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF){

		for(int i=0;i<m;i++){
            cin>>ma[i];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j]=ma[i][j]-'0';
            }
        }

		q.push(node(0,0,a[0][0],0));
        if(!bfs()){
            printf("IMPOSSIBLE\n");
        }
    }
	return 0;
}
