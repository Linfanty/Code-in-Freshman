#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 250005
typedef long long ll;
//const int N = 2e5 + 5;
using namespace std;

int N, M;

struct fff
{
    int u, v, w;
}ff[250003];

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
vector<edge> edges; //��������ͼ
int rank1[maxn]; //���·�ĸĽ�����
int dis[maxn][2]; // dist[i]��Դ��i��Ŀǰ���·����
bool inque[maxn];//�Ƿ��߹�


void add(int u, int v, int w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}


bool spfa(int s, int n, int flag)
{
    for(int i = 0; i <= n; i++)
    {
        dis[i][flag] = inf;
        rank1[i] = 0;
        inque[i] = false;
    }

    dis[s][flag] = 0;
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

            if(dis[e.to][flag] > dis[u][flag] + e.cost)
            {
                dis[e.to][flag]  = dis[u][flag] + e.cost;
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
    while( scanf("%d %d", &N, &M) !=EOF)
    {

        for (int i = 0; i <= N; i++) g[i].clear();
            edges.clear();

        for(int i = 1; i <= M; i++)
        {

            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
            ff[i].u = u;
            ff[i].v = v;
            ff[i].w = w;
        }

        spfa(0, N-1, 0);
        spfa(N-1, N-1, 1);
        ll sum = 0;
        for(int i = 1; i <= M; i++)
        {//����������ÿ��M���� ���ܲ�����������������
            int u = ff[i].u, v = ff[i].v, w = ff[i].w;
cout << u << ' ' << dis[u][0] <<' ' << v  << ' ' << dis[v][1] <<' ' << w << ' '<< dis[N-1][0] << endl;
            if( dis[u][0] + dis[v][1] + w == dis[N-1][0]
               //Դ��0��u  Դ��n-1��v + u��v�м��һ��
               || dis[v][0] + dis[u][1] + w == dis[N-1][0]  )
               //Դ��0��v  Դ��n-1��u + u��v�м��һ��
                sum += w;
        }

        cout << sum * 2<< endl;
    }

    return 0;
}
