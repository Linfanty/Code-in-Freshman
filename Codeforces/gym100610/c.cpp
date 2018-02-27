#include <bits/stdc++.h>
#include <iostream>
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define  fin freopen("commuting.in", "r", stdin);
#define  fout freopen("commuting.out", "w", stdout);
using namespace std;
int f[200005], g[200005], n, len[200005], vis[200005], f_[200005];
int dfs(int x, int l) {
    if( vis[x]) {
        int minx = len[l];
        rep(i, 1, l-1)
            if(l % i == 0)
                if(len[i] != -1)
                    if( minx > len[i])
                        minx = len[i];
                        return g[x] = minx;
    }
    vis[x] = true;
    return g[x] = f[dfs(f_[x], l + 1)];
}

int solve(int x)
{
    if( vis[x])  return 0;
    vis[x] = true;
    return 1 + solve(f[x]);
}
int main()
{
    //fin;
    // fout;
    cin >> n ;
    rep(i, 1, n)
        cin >>  f[i], f_[f[i]] = i;

    mem(vis,0);
    mem(len,-1);
    mem(g,-1);

    rep(i,1,n)
    {
        if( vis[i]) continue;
        int l = solve(i);
        if( len[l] == -1)
            len[l] = i;
    }

    rep(i, 1, n)
        if( g[i] == -1)
            g[i] = dfs(i, 0);

    rep(i, 1, n)
            cout << g[i] << ' ';
}

