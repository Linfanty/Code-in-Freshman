#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 25
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
vector<edge> edges;
int rank1[maxn];
int dis[maxn];
bool inque[maxn];

void add(int u, int v, int w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}


bool spfa(int s, int n)
{
    for(int i = 0; i <= n; i++)
    {
        dis[i] = inf;
        rank1[i] = 0;
        inque[i] = false;
    }

    dis[s] = 0;
    rank1[s] = 1;
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

            if(dis[e.to] > dis[u] + e.cost )
            {
                dis[e.to]  = dis[u] + e.cost ;
                if(!inque[e.to])
                {
                    q.push(e.to);
                    inque[e.to] = true;
                    rank1[e.to]++;
                    if( rank1[e.to] >= n)    return false;
                }
            }
        }
    }
    return true;
}


int main()
{
    int u, v, w;
    int s, n, t;
    int m, k;
    int cnt = 1;

    while( scanf("%d", &n) != EOF)
    {
        for (int i = 0; i <= maxn; i++) g[i].clear();
            edges.clear();

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            add(1, m, 1);
            add(m, 1, 1);
        }


        for(int i = 2; i < 20; i++)
        {
           scanf("%d", &n);
           for(int j = 1; j <= n; j++)
           {
                scanf("%d", &m);
                //cout << i << " to " << m <<endl;
                add(i, m, 1);
                add(m, i, 1);
           }
        }

        //init(N);

        printf("Test Set #%d\n", cnt++);
        scanf("%d", &m);

        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            spfa(u, 20);  //每一次都要 spfa (u， n);
            printf("%2d to %2d: %d\n", u, v, dis[v]);
        }

        printf("\n");
    }

    return 0;
}
