#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, 0, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;

struct Node{
    ll x, y;
    bool operator < (const Node xx){
        if( x == xx.x )
            return y < xx.y;
        return x < xx.x;
    }
}node[maxn];

int flagx[maxn], flagy[maxn];

int main(){

    //freopen("defense.in", "r", stdin);
    //freopen("defense.out", "w", stdout);

    int w, h, n, x, y;
    mem(flagx), mem(flagy);
    cin >> w >> h >> n;
    if( n == 0){
        cout << w * h << endl;
        return 0;
    }
    flagx[0] = 1, flagx[w+1] = 1, flagy[0] = 1, flagy[h+1] = 1;

    rep(i, 0, n-1){
      cin >> x >> y;
      flagx[x] = 1;
      flagy[y] = 1;
    }
    //sort(node, node+n);
    ll max1 = 0, max2 = 0;
    ll l = 0;

    rep(i, 1, w + 1){
        if( flagx[i])
        {
            max1 = max(max1, i - l - 1);
            l = i;
        }
    }
    l = 0;
    rep(i, 1, h + 1){
        if( flagy[i])
        {
            max2 = max(max2, i - l - 1);
            l = i;
        }
    }
    cout << max1 * max2 << endl;

    return 0;
}
