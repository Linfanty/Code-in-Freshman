#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int m,n;

char mp[507][507];

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int vis[507][507];
int a,b;

struct node{
    int x,y,step;
    node(){};
    node(int xx,int yy,int sstep):x(xx),y(yy),step(sstep){};
};

queue<node>q;

bool bfs(){
    node now;
    memset(vis,0,sizeof(vis));

    while(!q.empty()){
        now=q.front();
        q.pop();
        //cout << now.x << ' ' << now.y << endl;
        if( now.x==n-1 && now.y == m-1 )
        {
            //printf("%d %d", (now.step)/2, (now.step/2)*(a+b));
            if( now.step %2 == 0)
                printf("%d",now.step /2 *(a+b) );
            else printf("%d", ((now.step)/2)*(a+b) + b );
            return true;
        }

        for(int i=0;i<4;i++){
            int xx=now.x+dx[i];
            int yy=now.y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&& vis[xx][yy]==0 && mp[xx][yy] == '.'){
                vis[xx][yy]=1;
                q.push(node(xx,yy,now.step+1));
            }
        }
    }
    return false;
}
int main()
{
        scanf("%d%d",&m,&n);
        scanf("%d%d",&a,&b);

        for(int i=0;i<n;i++)
            scanf("%s", mp[i]);

		q.push(node(0,0,0));

        if(!bfs()){
            printf("IMPOSSIBLE\n");
        }

	return 0;
}
