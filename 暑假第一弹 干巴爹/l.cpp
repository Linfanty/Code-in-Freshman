//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 1005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<=b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

int N, M;
/*
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

vector<int> g[maxn];
vector<edge> edges; //整个有向图
int rank1[maxn]; //最短路的改进次数
double dis[maxn]; // dist[i]是源到i的目前最短路长度
bool inque[maxn];//是否走过
*/
double mp[maxn][maxn];
double d[maxn][maxn];
/*
void add(int u, int v, double w)
{
    edges.push_back(edge(u, v, w));
    int m = edges.size();
    g[u].push_back(m-1);
}
*/

bool spfa(int s, int n)
{
    /*
    for(int i = 1; i <= n; i++)
    {
        dis[i] = mp[1][i];
        rank1[i] = 0;
        inque[i] = false;
    }

    rank1[s] = 1;
    inque[s] = true;

    queue<int> q;
    q.push(s);

    //for(int i = 1; i <= 3 ; i++)
    //    cout << dis[i] << endl;

    while( !q.empty() )
    {
        int u = q.front();
        inque[u] = false;
        q.pop();

        for(int i = 0; i < (int)g[u].size(); i++)
        {
            //cout << i << ' ' << u << ' ' << g[u][i] << endl;
            edge e = edges[ g[u][i] ];
            //cout << u << ' '<<  e.to << ' ' << dis[e.to] <<' ' << dis[u] << ' ' <<  e.cost <<endl;
            if(dis[e.to] > max(dis[u], e.cost)) // 2 > 根号2 , 根号2
            {
                //cout << e.to << ' ' << dis[e.to] <<' '<<max(dis[u], e.cost) << endl;;
                dis[e.to]  = max(dis[u], e.cost);
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
    */

    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                if( mp[i][j] > max(mp[i][k], mp[k][j]))
                   mp[i][j] = max(mp[i][k], mp[k][j]);
                   printf("%.3f\n\n", mp[1][2]);
}


int main()
{
    int u, v, w;
    int s, n, t;
    int x[maxn], y[maxn], x3[maxn], y3[maxn];
    int cnt = 1;
    while( scanf("%d", &N) !=EOF )
    {
        if( N == 0)
            break;
/*
        for (int i = 0; i <= N; i++) g[i].clear();
            edges.clear();
*/
        for(int i = 1; i <= N; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            //add(x2, y2, x3, y3, sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
            //add(x3, y3, x2, y2, sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
        }
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                {mp[i][j] = sqrt((double)(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                //cout << mp[i][j] << endl;
                }
        /*
        for(int i = 1; i <= N; i++)
            for(int j = 1; i <= N; i++)
            {
                add(i, j, mp[i][j]);
                add(j, i, mp[i][j]);
            }
        */
        //init(N);


            //cout << spfa(s, N) << endl;
            //cout << dis[s] <<endl;
            //cout << dis[t] << endl;
        cout << "Scenario #" << cnt++ << endl;
        cout << "Frog Distance = ";
        spfa(1, N);

    }

    return 0;
}
