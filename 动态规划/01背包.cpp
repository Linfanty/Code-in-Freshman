#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
ll f[105][10005] = {0};
ll a[105][2];
int main()
{
    ll n, w;
    cin >> n >> w;
    for(int i =1; i <= n; i++)
        cin >> a[i][0] >> a[i][1];
    for(ll i = 1; i <= n; i++)
        for(ll j = 0; j <= w; j++)
            if(j >= a[i][0]) f[i][j] = max(f[i - 1][j - a[i][0]] + a[i][1], f[i - 1][j]);
            else f[i][j] = f[i - 1][j];
    cout << f[n][w] << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++) cout << f[i][j] << " "; cout << endl;
    }
    return 0;
}
