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

int a[maxn];
/**
void fenzhi(ll left, ll right, ll low)
{
    if(left == right) {
        ans++;
        return;
    }

    ll min1 = inf, max1 = -1;

    repp(i, left, right)
        min1 = min(min1, a[i] - low), max1 = max(max1, a[i] - low );

    ans += min(right - left + 1, min1);
    if( max1 == min1)
        return;
    low += min1;

    int flagl = -1, flagr = 0;

    repp(i, left, right) {
        if( a[i] - low > 0 && flagl == -1)
            flagl = i;
        else if( a[i] - low > 0 && flagl != -1)
            continue;
        else if(a[i] - low <= 0 && flagl != -1)
        {
            //cout << flagl <<  ' ' << i-1 <<' ' << low << ' ' <<ans<<endl;
            fenzhi(flagl, i-1, min1);
            flagl = -1;
        }
    }
    if( flagl != -1 && a[right] - low <= 0)
          fenzhi(flagl, flagl, min1);
    else if( flagl != -1 && a[right] - low > 0)
        fenzhi(flagl, right, min1);
}
10
3 3 6 4 2 3 2 2 3 3*/

int solve(int l, int r, int k) {
    int Min = inf;
    if (l == r) return 1;

    for (int i = l; i <= r; ++i)
            Min = min(Min, a[i] - k);

    int ans = 0;
    for(int i = l; i <= r; i++){
        if (a[i] - k > Min) {
            int ll = i, rr = i + 1;

            while (rr <= r && a[rr] - k > Min) ++rr;
            --rr;


    return min(r - l + 1, Min + ans);
}

int main()
{
    int n; cin >> n;
    repp(i, 1, n)
        cin >> a[i];
    cout << solve(1, n, 0) << endl;
}
