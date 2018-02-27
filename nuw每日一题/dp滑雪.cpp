#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int r,c,map[105][105],dp[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int DP(int x,int y)
{
    if(dp[x][y]!=0) return dp[x][y];
    int MAX = 0;
    for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(map[nx][ny]<map[x][y]&&nx>=1&&ny>=1&&nx<=r&&ny<=c){
                    if(DP(nx,ny)>MAX)
                        MAX = DP(nx,ny);
                }
            }
            dp[x][y] = MAX+1;
    return dp[x][y];
}
int main()
{
    scanf("%d%d",&r,&c);
    memset(dp,0,sizeof(dp));
    memset(map,0,sizeof(map));
    for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) scanf("%d",&map[i][j]);
    int MAX = 0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(DP(i,j)>MAX)
                MAX = DP(i,j);
        }
    }
    printf("%d",MAX);
}
