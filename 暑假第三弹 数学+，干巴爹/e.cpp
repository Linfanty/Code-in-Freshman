#include <cstdio>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int mod = 1e9+7;

ll a[550000], b[550000];
ll n, m, k;

ll gcd(ll a, ll b)
{
    return b?a:gcd(b,a%b);
}

void exgcd (ll a ,ll b ,ll &d ,ll &x ,ll &y )
{
    if ( ! b )
        d = a , x = 1 , y = 0 ;
    else
    {
         exgcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}

ll lcm(ll a, ll b, ll gcd)
{
    return a/gcd * b;
}

ll exchina(ll m[], ll a[], ll len) {
    ll x0 = a[0], mod = m[0];
    for(ll i = 1; i < len; i++) {
        ll k1, k0, r = a[i] - x0;

        ll gcd;
        exgcd(m[i], mod, gcd, k1, k0);

        if((a[i] - x0)%gcd != 0) return -1;
        k0 = r/gcd*k0;
        ll res = m[i]/gcd;
        k0 = (k0%res + res)%res;
        x0 = x0 + k0*mod;
        mod = lcm(mod, m[i], gcd);
    }
    return x0;
}
bool check()
{
    ll l = exchina(a, b, k);
    ll j;
    if( l > n || l <= 0)
        return false;
    rep(i, 1, k)
        b[i] = 1 - i;
    j = exchina(a, b, k);

    if( j + k-1 > m || j <= 0)
        return false ;

    rep(i, 1, k)
        if(gcd(l, j+i-1) != a[i] )
           return false;
    return true;
}

main()
{
    cin >> n >> m >> k;
    rep(i, 1, k)
        cin >> a[i];
    if( check() )
        cout << "YES" <<endl;
    else cout <<"NO" <<endl;
}
