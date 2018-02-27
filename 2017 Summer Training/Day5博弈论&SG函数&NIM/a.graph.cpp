#include <bits/stdc++.h>
#include <iostream>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i <= b; i++)
const int maxn = 40005;

vector<pair<int, int>  > edge[maxn];

int main()  {
IO;
    int t; cin >> t;
    while( t-- )    {
        int n, m, u, v, w, op, rt, x, y, z;
        cin >> n >> m;

        rep(i, 0, n) edge[i].clear();
        rep(i, 0, n-2) {
            cin >> u >> v >> w;
            edge[u].push_back( make_pair(v,w) );
            edge[v].push_back( make_pair(u,w) );
        }

        rep(i, 1, m)    {
            cin >> op;
            if( op == 0)    {
                cin >> rt;
                int ans = 0;
                rep(i, 0, edge[rt].size() - 1)
                    ans += edge[rt][i].second;

                if( ans & 1)
                    cout << "Girls win!" << endl;
                else cout << "Boys win!" << endl;

            }
            else {
                cin >> x >> y >> z;
                rep(i, 0, edge[x].size() - 1)
                    if( y == edge[x][i].first)
                        edge[x][i].second = z;
                rep(i, 0, edge[y].size() - 1)
                    if( x == edge[y][i].first)
                        edge[y][i].second = z;
            }
        }

    }
}
