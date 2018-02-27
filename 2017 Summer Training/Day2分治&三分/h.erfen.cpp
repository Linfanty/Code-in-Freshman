#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 50005;
ll n, l, r, s = 1, ans;

void solve(ll a, ll b, ll l, ll r, ll d)
{
    if( a > b || l > r) return;
    else{
        ll mid = (a+b)>>1;
        if( r < mid ) solve(a, mid - 1, l , r, d / 2);
        else if( mid < l) solve(mid + 1, b, l, r, d / 2);
        else {
            ans += d % 2;
            solve(a, mid - 1,
                  l, mid - 1, d / 2);
            solve(mid + 1, b,
                  mid + 1, r, d / 2);
        }
    }
}

int main()
{
    cin >> n >> l >> r;
    ll p = n;
    while( p >= 2)
    {
        p /= 2;
        s = s * 2 + 1;
    }
    //cout << p << ' ' << s << endl;
    solve(1, s, l, r, n);
    cout << ans << endl;
    return 0;
}
