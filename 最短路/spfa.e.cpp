//闇瑕佹敞鎰忕殑鏄紝璧风偣鏄0鐨勪笉瑕佺瓑寰呮椂闂达紝鎵浠ョ壒鍒わ紝骞朵笖涓嶈鍔犱笂60
#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 105
//const int N = 2e5 + 5;
using namespace std;

int N, M;
int speed[maxn];
int flo[maxn];

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

            if(dis[e.to] > dis[u] + e.cost + 60)
            {
                dis[e.to]  = dis[u] + e.cost + 60;
                //构成一个环 比如 13 到 13 就加 60
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

    

    while( scanf("%d %d", &n, &k) != EOF)
    {
        for (int i = 0; i <= maxn; i++) g[i].clear();
            edges.clear();

        for(int i = 0; i < n; i++)
            scanf("%d",&speed[i]);

        char c;
        for(int i = 0; i < n; i++)
        {
            int pos = 0;
            while( scanf("%d%c", &flo[pos++],&c) )
                if( c =='\n' )
                    break;
//妤煎眰鐪嬫垚鑺傜偣锛屾ゼ灞備箣闂寸殑鏃堕棿鐪嬫垚杈规潈鍊
            for(int j = 0; j < pos; j++)
            {
                for(int k  = j + 1; k < pos; k++)
                {
                    add(flo[j], flo[k], speed[i]* (flo[k] - flo[j]) );
                    add(flo[k], flo[j], speed[i]* (flo[k] - flo[j]) );   
                }
            }
        }
        //init(N);
        spfa(0, maxn) ;

        if(dis[k] == inf)
            printf("IMPOSSIBLE\n");
        else 
        {
            if(k == 0)
                printf("0\n");
            else 
                printf("%d\n",dis[k]-60); ////鍑忓幓鍒濆椤剁偣鐨60s  
        }    
    }

    return 0;
}
