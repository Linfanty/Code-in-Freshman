#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

#define maxn 10005
vector<int> edge[maxn];

int R[maxn];
int depth[maxn << 1];
int occur[maxn << 1];

int cnt;
void dfs(int u, int deep) {
    occur[++cnt] = u;
    depth[cnt] = deep;
    if(!R[u])
        R[u] = cnt;
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        dfs(v, deep + 1);
        occur[++cnt] = u;
        depth[cnt] = deep;
    }
}

int dp[maxn << 1][20];
void rmq() {
    for(int i = 1; i <= cnt; i++) 
        dp[i][0] = i;  
    for(int j = 1; (1 << j) <= cnt; j++)  
        for(int i = 1; i + (1 << j) - 1 <= cnt; i++) { 
            dp[i][j] = depth[dp[i][j - 1]] < depth[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
        }
}

int query(int x, int y) {
    int l = R[x], r = R[y];
    if(l > r) swap(l, r);
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    int mmin = depth[dp[l][k]] < depth[dp[r - (1 << k) + 1][k]] ? dp[l][k] : dp[r - (1 << k) + 1][k];
    return occur[mmin];
}

bool in[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            edge[i].clear();
        mem(in, 0);
        mem(depth, 0);
        mem(dp, 0);
        mem(R, 0);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            in[v] = true;
        }
        cnt = 0;
        for(int i = 1; i <= n; i++)
            if(!in[i]) {
                dfs(i, 0);
                break;
            }
        rmq();
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
}
