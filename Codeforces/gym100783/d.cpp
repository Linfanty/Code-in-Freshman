#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int maxn = 20005;
using namespace std;

int pre[maxn], n, m, d;
bool vit[maxn];
int l[maxn], r[maxn];
int ans[maxn];

vector<int> g[maxn];

bool dfs(int x)
{
    for(int i = 0; i < g[x].size(); i++)
    {
        int v = g[x][i];
        if( vit[v] == false )
        {
            vit[v] = true;
            if( ( ans[v] == -1) || dfs(ans[v]) )
            {
                ans[v] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int a, b;
    cin >> n >> m;
    rep(i, 0, n)
        ans[i] = -1;


    rep(i, 1, m)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    if( n > m)
    {
        cout << "NO" <<endl;
        return 0;
    }

    rep(i, 0, n-1)
    {
        mem(vit);//Òª³õÊ¼»¯mem£¨vit£©
        dfs(i);
    }
    int fflag = 1;

    rep(i, 0, n-1)
    {
        if(ans[i] == -1)
        {
            fflag = 0;
            break;
        }
    }

    if( fflag == 1)
        cout << "YES" <<endl;
    else cout << "NO" <<endl;
}
