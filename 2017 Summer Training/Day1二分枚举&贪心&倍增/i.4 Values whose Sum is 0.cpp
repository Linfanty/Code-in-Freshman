#include <stdio.h>
#include <iostream>
#include <algorithm>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 4005;
ll a[maxn], b[maxn], c[maxn], d[maxn], e[maxn*maxn], f[maxn*maxn];

int main()
{IO;
    int n;
    cin >> n;
    rep(i, 0, n)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    rep(i, 0, n)
        rep(j, 0, n)
            e[i*n+j] = c[i] + d[j];
/// i * n + j
    sort(e, e+n*n);
    ll sum = 0;

    rep(i, 0, n)
        rep(j, 0, n)
            sum+= upper_bound(e, e+n*n, -(a[i] + b[j]))
               - lower_bound(e, e+n*n, -(a[i] + b[j]));

    cout << sum << endl;
}
