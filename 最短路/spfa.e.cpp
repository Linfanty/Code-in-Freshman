//�要注意的是，起点�0的不要等待时间，�以特判，并且不要加上60
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
vector<edge> edges; //整个有向�
int rank1[maxn]; //�短路的改进次�
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
                //����һ���� ���� 13 �� 13 �ͼ� 60
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
//楼层看成节点，楼层之间的时间看成边权�
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
                printf("%d\n",dis[k]-60); ////减去初始顶点�60s  
        }    
    }

    return 0;
}
