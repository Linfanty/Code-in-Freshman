#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 1255
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

struct Node { int v,next; }e[1000];
vector<int>v[N];
int n,m;
int tot,start[N];
int flag[55][55];
char str[55][55];
int w,b;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int pre[N];
bool mark[N];

void add(int u,int v)
{
    e[tot].v=v;
    e[tot].next=start[u];
    start[u]=tot++;
}

bool DFS(int i)
{
    int j;
    for(j=start[i];j!=-1;j=e[j].next)
    {
        int k=e[j].v;
        if(!mark[k])
        {
            mark[k]=true;
            if(pre[k]==0||DFS(pre[k]))
            {
                pre[k]=i;
                return true;
            }
        }
    }
    return false;
}

int Hungary()
{
    int i,count=0;
    memset(pre,0,sizeof(pre));
    for(i=1;i<=w;i++)
    {
        mem(mark,false);
        if(DFS(i))
            count++;
    }
    return count==w;
}

void dfs(int x,int y,int c,int u)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+way[i][0];
        int yy=y+way[i][1];
        if(xx<0||yy<0||xx>=5||yy>=5||str[xx][yy]=='1')
            continue;
        if(c==0)
        {
            if(flag[xx][yy])
            {
                add(u,flag[xx][yy]);
                continue;
            }
            flag[xx][yy]=b;
            add(u,b);
            dfs(xx,yy,1,b++);
        }
        else
        {
            if(flag[xx][yy])
            continue;
            flag[xx][yy]=w;
            dfs(xx,yy,0,w++);
        }
    }
}

bool slove(int x,int y)
{
    w=2;b=1;
    mem(start,-1);
    tot=0;
    flag[x][y]=1;
    dfs(x,y,0,1);
    w--; b--;
    if(w!=b)
        return false;
        return Hungary();
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        mem(flag,0);
        for(int i=0;i<5;i++)
            scanf("%s",str[i]);
        bool ans=true;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(str[i][j]=='1'||flag[i][j])
                    continue;
                if(!slove(i,j))
                    ans=false;
            }
        }
        if(ans)
            puts("lose");
        else puts("win");
    }
    return 0;
}


