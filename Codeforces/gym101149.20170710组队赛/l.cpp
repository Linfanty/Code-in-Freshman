#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 200005
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
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

    int u, v, w, a, b, m;
    int s, n, t;
    int e[maxn][5];
vector<int> g[maxn];
vector<edge> edges; //整个有向图
int rank1[maxn]; //最短路的改进次数
int dis[maxn]; // dist[i]是源到x的目前i最短路长度
bool inque[maxn];//是否走过
int dis1[maxn],dis2[maxn],dis3[maxn];

void add(int u, int v, int w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}

void init(int dis[])
{
    for (int i = 0; i <= m; i++) g[i].clear();
    edges.clear();

    for(int i = 0; i <= m; i++)
    {
        dis[i] = inf;
        rank1[i] = 0;
        inque[i] = false;
    }
}

bool spfa(int s, int *dis)
{
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

            if(dis[e.to] > dis[u] + e.cost)
            {
                dis[e.to] = dis[u] + e.cost;
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
    scanf("%d %d %d %d", &n, &m, &a, &b);

    init(dis1);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &e[i][0], &e[i][1]);
        add(e[i][0], e[i][1], 1);
    }

    spfa(0, dis1);

    //for(int i = 0; i <= n; i++)
    //    cout << dis1[i] << ' ';

    init(dis2);
    init(dis3);

    for(int i = 1; i <= m; i++)
        add(e[i][1], e[i][0], 1);
    //每个节点反方向 往回走 求分叉点

    spfa(a, dis2);
    spfa(b, dis3);

    int ans = n;
    for(int i = 0; i <= n; i++)
        ans = min(dis1[i] + dis2[i] + dis3[i], ans);

    printf("%d\n", ans);

    return 0;
}

