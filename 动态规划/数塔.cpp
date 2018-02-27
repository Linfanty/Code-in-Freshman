#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
ll f[105][105];
ll a[105][105];
int n;
int dfs(int i, int j)
{
    if(i > n || j > i) return 0;
    if(f[i][j] != 0) return f[i][j];
    return f[i][j] = max(dfs(i + 1, j), dfs(i + 1, j + 1)) + a[i][j];
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(f, 0, sizeof f);
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i[1]; j++) cin >> a[i][j];
        cout << dfs(1, 1) << endl;
        /*
        for(int i = n; i >= 1; i--)
            for(int j = 1; j <= i; j++)
                f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        cout << f[1][1] << endl;
        */
    }
    return 0;
}
