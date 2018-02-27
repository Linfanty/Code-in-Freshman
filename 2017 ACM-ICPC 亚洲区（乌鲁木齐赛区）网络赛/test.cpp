#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define inf 0x3f3f3f3f
#define maxn 100005
//const int N = 2e5 + 5;
using namespace std;
int N, M;

struct edge
{
    int from, to, cost;
    edge() {}
    edge(int ffrom, int tto, int ccost)
    {
        from = ffrom;
        to = tto;
        cost = ccost;
    }
};

vector<int> g[maxn];
vector<edge> edges; //整个有向图
int rank1[maxn]; //最短路的改进次数
int dis[maxn]; // dist[i]是源到i的目前最短路长度
bool inque[maxn];//是否走过

void add(int u, int v, int w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}


bool spfa(int s, int n)
{
    for(int i = 0; i <= n+2; i++)
    {
        dis[i] = -inf;
        inque[i] = false;
    }
    dis[s] = 0;
    inque[s] = true;

    queue<int> q;
    q.push(s);

    while( !q.empty())
    {
        int u = q.front();
        inque[u] = false;
        q.pop();

        for(int i = 0; i < (int)g[u].size(); i++)
        {
            edge e = edges[ g[u][i] ];

            if(dis[e.to] < dis[u] + e.cost && e.to > u )
            {
                dis[e.to] = dis[u] + e.cost;
                // cout << u << ' ' << e.to << ' ' << dis[e.to] << endl;
                if(!inque[e.to])
                {
                    q.push(e.to);
                    inque[e.to] = true;
                }
            }
        }
    }
    return true;
}


int main()
{
    int u, v, w;
    int s, n, t, tt;
    scanf("%d", &tt);
    while( tt-- )
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N+2; i++) g[i].clear();
            edges.clear();

        for(int i = 1; i <= M; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            if( v > u )
                add(u, v, w);
            else add(v, u, w);

            if( u < v)
                add(0, u, 0);
            else add(0, v, 0);
            //add(u, 0, 0);
            //add(N+1, v, 0);

            if( v > u)
                add(v, N+1, 0);
            else add(u, N+1, 0);

        }

        spfa(0, N+2);
        printf("%d\n", dis[N+1]);
    }

    return 0;
}
