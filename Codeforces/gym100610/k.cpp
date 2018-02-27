#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 205
//const int N = 2e5 + 5;
using namespace std;
typedef long long ll;

int N, M;
int w, h;
int u, v;
int s, n, t;

double dis(int x1, int y1, int x2, int y2)
{
    double mid[4];
    mid[0] = sqrt((x1 + x2)*(x1 + x2) + (y1 - y2)*(y1 - y2));
    mid[1] = sqrt((2 * w - x1 - x2)*(2 * w - x1 - x2) + (y1 - y2)*(y1 - y2));
    mid[2] = sqrt((x1 - x2)*(x1 - x2) + (y1 + y2)*(y1 + y2));
    mid[3] = sqrt((x1 - x2)*(x1 - x2) + (2 * h - y1 - y2)*(2 * h - y1 - y2));
    sort(mid, mid + 4);
    return mid[0];
}

double dis1(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double dis2(int x, int y)
{
    double mid[4] = {x, y, w - x, h - y};
    sort(mid, mid + 4);
    return mid[0];
}

int pp[20][2];
double sum = 0, d[20], range[20][20], ans = inf;
bool vis[20];

void dfs(int x, int depth, double len)
{
    //cout << len << endl;
    if( len > ans)
        return;
    if( depth == n) {
        //cout << len + dis2(pp[x][0], pp[x][1]) << endl;
        ans = min(ans, len + dis2(pp[x][0], pp[x][1]));
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if( len + range[x][i] > ans)
            continue;
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(i, depth + 1, len + range[x][i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    //freopen("kitchen.in", "r", stdin);
    //freopen("kitchen.out", "w", stdout);

    scanf("%d %d", &w, &h);
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        pp[i][0] = u, pp[i][1] = v;
    }

    scanf("%d %d", &s, &t);
    for(int i = 0; i < n; i++)
        for(int j = i+1 ; j < n; j++)
            range[i][j] = range[j][i] = dis(pp[i][0], pp[i][1], pp[j][0], pp[j][1]);
    for(int i = 0; i < n; i++)
        range[n][i] = dis1(s, t, pp[i][0], pp[i][1]);
    /*
    for(int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        dfs(i, 1, range[n][i]);
    }*/
    double sum = 0;
    double dp[20][20];
    for(int i = 0; i < n; i++)
        dp[0][i] = dp[i][0] = inf;

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            //for(int k = i + 1; k < j; k ++ )
            dp[i][j] = min(dp[i][j-1] + range[j-1][j], dp[i][j]);
            ans = min(ans, dp[i][j]);
        }
    }
    printf("%.14f\n", ans);


    return 0;
}
