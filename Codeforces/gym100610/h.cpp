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
    //freopen("horrible.in", "r", stdin);
    //freopen("horrible.out", "w", stdout);
    int n;
    cin >> n;
    if( n == 1)
    {
        cout << 1 << endl;
        cout << 1 << ' ' << 0 <<endl;
        return 0;
    }
    cout << 3 + (n-1) * (2*n-1) << endl << n << ' ' << -1 << endl;

    rep(i, 1, n-1)
    {
        cout << i << ' ' << 0 << endl;
        for(int j = 1, k = 1; j <= n &&k <= n; j++ , k++)
        {
            if( j == i) j++;
            if( k == i+1) k++;
            cout  << j << ' ' << i << endl;
            cout << k << ' ' << -(i+1) << endl;
        }
    }
    cout << n << ' ' << 0 <<endl;
    cout << 1 << ' ' << n << endl;


}
