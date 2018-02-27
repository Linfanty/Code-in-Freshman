#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int maxn = 2e5 + 5;
using namespace std;

ll n, m, a[maxn], b;
ll cnt = 0;
ll mp[1000005] = {0};
ll sum[1000005] = {0};
map<ll,ll>mp2;
map<ll,ll> :: iterator  it;

int main()
{
    freopen("deposits.in", "r", stdin);
    freopen("deposits.out", "w", stdout);
    scanf("%I64d", &n);
    rep(i, 1, n)
    {
         scanf("%I64d", &a[i]);
         mp2[ a[i] ]++;
    }

    scanf("%I64d", &m);
    rep(i, 1, m)
    {
        scanf("%I64d", &b);
        if( mp[b] == 1)
            cnt += sum[b];
        else
        {
            ++mp[b];
            for(it = mp.begin(); it != mp.end(); it++)
            {
                if( it->first % b == 0)
                    sum[b]++;
                sum[b] = sum[b] * it->second;

                if( a[j] % b == 0 )
                    sum[b]++;
            }
            cnt += sum[b];
        }

    }
    printf("%I64d", cnt);
}
