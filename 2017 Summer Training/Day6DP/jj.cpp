#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#define max(a,b) a>b?a:b
using namespace std;
int mov[][2]={1,0,-1,0,0,1,0,-1},ans,map[110][110],vis[110][110],dist[110][110],n,m;

void BFS(int x,int y){
        int j,xx,yy,i,q;
        queue<int>Q;
        q=x*n+y;

        Q.push(q);
        while(!Q.empty()){
            q=Q.front();Q.pop();

            x=q/n;y=q%n;
            vis[x][y]=1;

            for(i=0;i<4;++i){
                xx=x+mov[i][0];
                yy=y+mov[i][1];

                if(xx>=0&&xx<m&&yy>=0&&yy<n&&
                   map[xx][yy]<map[x][y]&&
                   (!vis[xx][yy]||(dist[x][y]>=dist[xx][yy]))){

                    dist[xx][yy]=dist[x][y]+1;
                    ans=max(ans,dist[xx][yy]);

                    vis[xx][yy]=1;
                    Q.push(xx*n+yy);
                }
            }
        }
}
int main()
{
    int i,j,k,a;
    scanf("%d",&k);
    while(k--){

        memset(map,0,sizeof(map));
        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
        a=0;ans=0;
        scanf("%d%d",&m,&n);

        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
                scanf("%d",&map[i][j]);

            for(i=0;i<m;++i)
                for(j=0;j<n;++j) {
                    memset(vis,0,sizeof(vis));
                    memset(dist,0,sizeof(dist));
            BFS(i,j);
            }

        printf("%d\n",ans+1);
    }
    return 0;
}
