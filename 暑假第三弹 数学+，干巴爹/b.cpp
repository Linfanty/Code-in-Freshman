#include <cstdio>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;
#define int long long int
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int m[550000];
int a[550000], dd;

void exgcd (int a ,int b ,int &d ,int &x ,int &y )
{
    if ( ! b )
        d = a , x = 1 , y = 0 ;
    else
    {
         exgcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}
/*
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = exgcd(b, a%b, x, y);
    ll res = x;
    x = y;
    y = res - a/b*y;
    return gcd;
}
*/
ll lcm(ll a, ll b, ll gcd)
{
    return a/gcd * b;
}

ll exchina(ll a[], ll m[], ll len) {
    ll x0 = a[0], mod = m[0];
    for(int i = 1; i < len; i++) {
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


main()
{
    int t;
    while( cin >> t )
    {
        rep(i, 0, t-1)
            cin >> m[i] >> a[i];

        ll ans = exchina(a, m, t);
        cout << ans << endl;
    }
}



