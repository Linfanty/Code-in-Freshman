#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 35
//const int N = 2e5 + 5;
using namespace std;

int N, M;
map<string, int> mp;

struct edge
{
    int from, to;
    double cost;
    edge() {}
    edge(int ffrom, int tto, double ccost)
    {
        from = ffrom;
        to = tto;
        cost = ccost;
    }
};

vector<double> g[maxn];
vector<edge> edges;
int rank1[maxn];
double dis[maxn];
bool inque[maxn];
double t[maxn][maxn];

void add(int u, int v, double w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}


int spfa(int s, int n)
{
    for(int i = 0; i <= maxn; i++)
    {
        dis[i] = 0.0;
        rank1[i] = 0;
        inque[i] = false;
    }

    dis[s] = 1.0;
    rank1[s] = 1;
    inque[s] = true;

    queue<int> q;
    q.push(s);

    while( !q.empty())
    {
        int u = q.front();
        inque[u] = false;
        q.pop();

        /*
        for(int i = 0; i < n; i++)
        {
            //edge e = edges[ g[u][i] ];
            //cout <<dis[s] << ' ' <<dis[i] <<' ' <<t[u][i]<<endl;
            //cout << u  << ' '  << i <<' ' << t[u][i] <<endl;
            if(dis[i] < t[u][i] * dis[u])
            {
                dis[i]  = dis[u] * t[u][i];


                if(dis[s] > 1.0)
                    return 1;

                if(!inque[i])
                {
                    q.push(i);
                    inque[i] = true;
                    //rank1[e.to]++;
                    //if( rank1[e.to] >= n)    return 1;
                }
            }
        }
        */
        for(int i = 0; i < (int)g[u].size(); i++)
        {
            edge e = edges[ g[u][i] ];

            if(dis[e.to] < dis[u] * e.cost )
            {
                dis[e.to]  = dis[u] * e.cost ;

                if( dis[s] > 1.0)
                    return 1;
                if(!inque[e.to])
                {
                    q.push(e.to);
                    inque[e.to] = true;
                    rank1[e.to]++;
                    if( rank1[e.to] >= n)    return 1;
                }
            }
        }

    }
    return 0;
}


int main()
{

    int s,  m;
    int n, cnt, k = 1;

    while( scanf("%d", &n) !=EOF)
    {

        if( n == 0)
            break;

        for (int i = 0; i <= maxn; i++) g[i].clear();
            edges.clear();
            mp.clear();


        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                if( i == j)
                   t[i][j] = 1.0;
                else t[i][j] = 0.0 ;

        cnt = 0;
        char s[35];

        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            if( !mp[s] )
                mp[s] = cnt++;
        }

        scanf("%d", &m);
        char u[35], v[35];
        double w;

        for (int i = 0; i < m; i++)
        {
             scanf("%s", u);
             scanf("%lf", &w); // ATTENTION MUST BE LF!
             scanf("%s", v);
             //cout << w <<' ' << endl;

             add(mp[u], mp[v], w);

             //t[mp[u]][mp[v]] = w;


             //add( mp[u], mp[v], w);
             //add(mp[v], mp[u], 1.0/w);
        }

        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            flag = spfa(i, n);

            //cout << flag <<endl;
            if( flag == 1)
               break;
        }

        //cout << mp["USDollar"] <<mp["BritishPound"] <<mp["FrenchFranc"]<<endl;
        //cout << dis[0] <<' ' <<dis[1] <<' ' <<dis[2] <<endl;
        if( flag == 1)
            printf("Case %d: Yes\n",k++);
        else  printf("Case %d: No\n",k++);

    }

    return 0;
}
