#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 105
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
vector<edge> edges; //��������ͼ
int rank1[maxn]; //���·�ĸĽ�����
int dis[maxn]; // dist[i]��Դ��i��Ŀǰ��̳���
bool inque[maxn];//�Ƿ��߹�
int cnt[maxn];
/*
void floyd()
{
    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
            if(reach[i][j]||(reach[i][k]&&reach[k][j])) reach[i][j] = true;
}
if(!reach[1][n])
{
    printf("hopeless\n");
     continue;
}
*/
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
        dis[i] = -inf; //  ÿ�����ʼΪ������
        rank1[i] = 0;
        inque[i] = false;
        cnt[i] = 0;
    }

    dis[s] = 100;     //��ʼ����Ϊdis[s] = 100;
    rank1[s] = 1;
    inque[s] = true;
    cnt[s] = 1;

    queue<int> q;
    q.push(s);

    while( !q.empty())
    {
        int u = q.front();
        inque[u] = false;
        q.pop();
        //g[u]  ��
        for(int i = 0; i < (int)g[u].size(); i++)
        {
            edge e = edges[ g[u][i] ];

            if( dis[u] + e.cost <= 0)  // �з�����·��
              continue;

            if(dis[e.to] < dis[u] + e.cost)
            {
                dis[e.to]  = dis[u] + e.cost;
                if(e.to == n)  return true;
                if(!inque[e.to])
                {
                    cnt[e.to]++;

                    //���һ�������n+1�Σ�˵���������һ�������ϡ�
                    if( cnt[e.to] > n)  continue;
                    if(cnt[e.to] == n)
                        dis[e.to] = inf;
                    //������������ͱ�ǳ����޴�

                    q.push(e.to);
                    inque[e.to] = true;
                    rank1[e.to]++;
                    //if( rank1[e.to] >= n)    return false;
                }
            }
        }
    }
    return false;
}


int main()
{
    int u, v, w[maxn];
    int s, n, t;
    int vit[maxn][maxn];

    while( scanf("%d", &N)!=EOF )
    {
        if( N == -1)
            break;

        for (int i = 0; i <= maxn; i++) g[i].clear();
            edges.clear();

        w[1] = 0;
        w[N] = 0;

        memset(vit,0,sizeof(vit));

        for(int i = 1; i <= N; i++)
        {
            scanf("%d %d",&w[i], &M); //&w[i] ÿ�����������ֵ
            for(int  j = 1; j <= M; j++)
            {
                scanf("%d", &v);
                /*
                vit[i][v]++;
                if( vit[v][i] >= 1 &&  (w[i]+w[v]>0 ) )  //������������ͱ�ǳ����޴�
                {
                    w[i] = inf;
                    w[v] = inf;
                }
                */
                add(i, v, w[i]);
                //add(v, i, w[i-1]);
            }
        }

        //init(N);
        spfa(1, N) ;

        //if( spfa(1, N) )
        //  printf("wwwwwwww");
        //else printf("hhhhhhhh");

        //printf("%d\n",dis[N]);

        //if(!spfa(1, N))
        //    printf("winnable\n");

        /*
        cout << inf << endl;
        cout << dis[1] << endl;
        cout << dis[2] << endl;
        cout << dis[3] << endl;
        cout << dis[4] << endl;
        cout << dis[5] << endl;
        */

        /*
        if( dis[N] != inf && dis[N] >= 1  )
            printf("winnable\n");
        else if( dis[N] == inf &&  !spfa(1, N)  )
            printf("winnable\n");
        else printf("hopeless\n");
        */
        if( spfa(1, N) )
            printf("winnable\n");
        else printf("hopeless\n");
    }

    return 0;
}
