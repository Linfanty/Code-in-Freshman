#include <stdio.h>
#include <bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;

ll n, k;

int main()
{
    int w = 1;
    while ( cin >> n >> k)
    {
        if( k <= n)
cout <<"Case #" << w++ << ": "<< k << endl;
        else
        {
            ll t = (n-1) * 2;
            ll ans;
            int mod = (k-n) % t;
            //cout << t << ' '<< mod << endl;
            if( mod == 0)
                ans = n;
            else if( mod == (n-1) )
                ans = n-1;
            else if( mod == 2*(n-1))
                ans = n;
            else if( mod >= (n-1))
                ans = mod - (n-1);
            else ans = mod;
            cout <<"Case #" << w++ << ": "<< ans << endl;
        }
    }
}
