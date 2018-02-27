#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll m[123456];
ll a[123456];

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
ll lcm(ll a, ll b, ll gcd) {
    return a/gcd*b;
}
// 计算 x = a[i] mod m[i], 一共len个方程
ll exchina(ll a[], ll m[], ll len) {
    ll x0 = a[0], mod = m[0];
    for(int i = 1; i < len; i++) {
        ll k1, k0, r = a[i] - x0;
        ll gcd = exgcd(m[i], mod, k1, k0);
        if((a[i] - x0)%gcd != 0) return -1;
        k0 = r/gcd*k0;
        ll res = m[i]/gcd;
        k0 = (k0%res + res)%res;
        x0 = x0 + k0*mod;
        mod = lcm(mod, m[i], gcd);
    }
    return x0;
}

int main() {
    int k;
    while(cin >> k) {
        for(int i = 0; i < k; i++) {
            cin >> m[i] >> a[i];
        }
        ll ans = exchina(a, m, k);
        cout << ans << endl;
    }
    return 0;
}
