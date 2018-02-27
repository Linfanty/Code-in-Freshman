#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 300005;

int n, k;   ll a[maxn], ans = 0, vit[maxn], b[maxn];
/*
bool check(ll mid)
{
    int i, j = 1, cnt = 0, p = 0, now = 0;
    mem(vit, 0);
    for(i = mid; i < n ; i++)
    {
        if( !vit[i] && a[i] / a[p] >= 2)
        {
            ++j;   // step
            p = i; // now
            vit[i] = 1;
            //cout << i << endl;
            if( j == k)
            {
                cnt++; ///是否可行
                if( cnt >= mid)
                    return true;
                i = mid - 1;
                ++now;
                p = now;
                j = 1;
            }
        }
    }
    return false;
}*/
/**
6 3
1 5 10 20 30 40
1 10 30
5 20 40
*/
/// A[]的前m个=B[]的前m个 B[p]>2×A[i-m]的B[p]作为A[i]
bool check(int m)
{
    rep(i, 0, m)
        b[i] = a[i];
    int p = m;
    rep(i, m, m*k)
    {
        while( a[p] < b[i-m] * 2 && p < n)
            p++;
        if(p==n)
            return 0;

        b[i] = a[p];///b[m] = a[m] = 10 b[m+1] = a[m+1] = 20
        p++;
    }
    return 1;
}

void erfen()
{
    ll low = 0, high = n/k;
    while( low <= high )
    {
        ll mid = (low+high) / 2;
        //cout << mid << ' ' << check(mid) << endl;
        if( check( mid ) )
        {
            ans = mid ;
            low = mid + 1;
        }
        else high = mid - 1;
    }
}


int main()
{
    int t, w = 1;
    cin >> t;
    while( t-- )
    {
        mem(vit, 0);
        ans = 0;
        cin >> n >> k;
        rep(i, 0, n)
            cin >> a[i];

        if( k == 1)
        {
            cout << "Case #" << w++ << ": " << n <<endl;
            continue;
        }
        sort(a, a + n);
        erfen();

        cout << "Case #" << w++ << ": " << ans <<endl;
    }
}
