#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 10005
//const int N = 2e5 + 5;
using namespace std;

int N, M;
map<string, int> mp;

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
vector<edge> edges; //鏁翠釜鏈夊悜鍥
int rank1[maxn]; //鏈鐭矾鐨勬敼杩涙鏁
int dis[maxn]; // dist[i]鏄簮鍒癷鐨勭洰鍓嶆渶鐭矾闀垮害
bool inque[maxn];//鏄惁璧拌繃

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

            if(dis[e.to] > dis[u] + e.cost)
            {
                dis[e.to]  = dis[u] + e.cost;
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
    int s, t;
    int n, cnt;
    //printf("%d",inf);
    while( scanf("%d", &n) !=EOF)
    {

        if( n == -1)
            break;

        for (int i = 0; i <= maxn; i++) g[i].clear();
            edges.clear();
            mp.clear();
            cnt = 1;

        char a[35], b[35];
        scanf("%s %s", a, b);
        int flag = 0;
        if(strcmp(a,b)==0) //标记起点与终点是否相同
           flag = 1;

        mp[a] = cnt++;
        mp[b] = cnt++;

        for(int i = 1; i <= n; i++)
        {
            scanf("%s %s %d", a, b, &w);

            if( !mp[a] )
                mp[a] = cnt++;
            if( !mp[b] )
                mp[b] = cnt++;

            u = mp[a];
            v = mp[b];
            //cout << u << ' ' << v << ' ' << cnt << endl;
            add(u, v, w);
            add(v, u, w);
        }

        if( flag == 1)
        {
            printf("0\n");
            continue;
        }
        //init(N);
        spfa(1, maxn) ;

            //cout << spfa(s, N) << endl;
            //cout << dis[s] <<endl;
            //cout << dis[t] << endl;

        if(dis[2] != inf)
            printf("%d\n", dis[2]);
        else printf("-1\n");
    }

    return 0;
}
