#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int M_node = 1090,M_edge = 500009,INF = 0x3f3f3f3f;

struct edge
{
    long long int to,cap,next;
    bool is_rev;
}edge[M_edge],edge2[M_node];

int head[M_node],level[M_node];
int pre[M_node];
int tot;
int n,m;
int s,t;
int ss,tt;
int vis[M_node];

void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
    memset(vis,0,sizeof(vis));
}

void add_edge(int u,int v,int cap)
{
    edge[tot].to = v;edge[tot].cap = cap;edge[tot].is_rev = false;edge[tot].next = head[u];head[u] = tot++;
    edge[tot].to = u;edge[tot].cap = 0;edge[tot].is_rev = true;edge[tot].next = head[v];head[v] = tot++;
}

bool bfs(int s,int t)
{
     memset(level,-1,sizeof(level));
     level[s] = 0;
     queue<int> q;
     q.push(s);
     while(!q.empty())
     {
         int v = q.front();
         q.pop();
         for(int i = head[v];i != -1;i = edge[i].next)
         {
             int u = edge[i].to;
             if(level[u] < 0 && edge[i].cap > 0)
             {
                 level[u] = level[v] + 1;
                 q.push(u);
             }
         }
     }
     return level[t] != -1;
}

int dfs(int v,int t,long long int f)
{
    if(v == t) return f;
    for(int &i = pre[v];i != -1;i = edge[i].next)
    {
        int u = edge[i].to;
        if(level[u] > level[v] && edge[i].cap > 0)
        {
            long long int d = dfs(u,t,min(f,edge[i].cap));
            if(d > 0)
            {
                edge[i].cap -= d;
                edge[i^1].cap += d;
                //pre[v] = i;
                //printf("i = %d,v = %d,u = %d, d = %d\n",i,v,u,d);
                //printf("edge[i].cap = %d\n",edge[i].cap);
                return d;
            }
        }
    }
    level[v] = -1;
    return 0;
}

long long int max_flow(int s,int t)
{
    long long int flow = 0;
    while(bfs(s,t))
    {
        for(int i = 0;i <= t;i++) pre[i] = head[i];
        long long int f = 0;
        while((f = dfs(s,t,INF)) > 0) flow += f;
    }
    return flow;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);

        init();
        for(int i = 0;i < m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            add_edge(u,v,cost);
        }

        add_edge(0, s, INF);
        add_edge(t, n+1, INF);
        long long int ans = max_flow(0, n+1);

        //printf("debug ---- ans = %d\n",ans);
        for(int i = 0;i < n;i++)
        {
            for(int j = head[i];j != -1;j = edge[j].next)
            {
                if(edge[j].cap == 0 && edge[j].is_rev == false)
                {
                    edge[j].cap = 1;
                    edge[j^1].cap = 0;
                    //add_edge(t+1+i,t+1+edge[j].to,1);
                    //printf("add_edge u = %d,v = %d\n",i,edge[j].to);
                }
                else if(edge[j].is_rev == false)
                {
                    edge[j].cap = INF;
                    edge[j^1].cap = 0;
                }
                //add_edge(t+1+i,t+1+edge[j].to,INF);
            }
        }

        ans = max_flow(0, n+1);
        printf("%lld\n",ans);
    }
    return 0;
}
