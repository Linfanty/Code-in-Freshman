#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, 0, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;


int main()
{
    //freopen("explicit.in", "r", stdin);
    //freopen("explicit.out", "w", stdout);
    int x[15];
    int cnt = 0;
    rep(i, 1, 10)
    {
        cin >> x[i];
        if( x[i] == 0)
            cnt ++;
    }

    int ans = 45 - cnt*(cnt-1)/2 + 120 - cnt*(cnt-1) * (cnt-2)/6;

    if( ans % 2 == 0)
        cout << 0 << endl;
    else cout << 1 << endl;
}
