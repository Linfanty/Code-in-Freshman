#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 110
#define inf 1000000000

vector<int>ve[N];

int w[N];
int Q[N*N];
bool inq[N];
int dis[N], cnt[N];
int id;
bool spfa(int n)
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = -inf, inq[i] = 0, cnt[i] = 0;
    }
    dis[1] = 100;
    int top = 0;
    Q[top++] = 1;
    inq[1] = cnt[1] = 1;
    for(int i = 0; i < top; i++)
    {
        int u = Q[i];
        inq[u] = 0;
        if(dis[u]+w[u] <= 0) continue;
        int m = ve[u].size();
        for(int j = 0; j < m; j++)
        {
            int v = ve[u][j];
            if(dis[v] < dis[u] + w[u])
            {
                dis[v] = dis[u] + w[u];
                if(v == n) return true;
                if(!inq[v])
                {
                    cnt[v]++;
                    if(cnt[v] > n) continue;
                    if (cnt[v] == n)
                        dis[v] = inf;
                    Q[top++] = v;
                    inq[v] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n;
    while(~scanf("%d", &n), ~n)
    {
        for(int i = 1; i <= n; i++) ve[i].clear();
        for(int i = 1; i <= n; i++)
        {
            int m, t;
            scanf("%d", &w[i]);
            scanf("%d", &m);
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &t);
                ve[i].push_back(t);
            }
        }
        bool res = spfa(n);
        if(res) puts("winnable");
        else puts("hopeless");
    }
    return 0;
}
