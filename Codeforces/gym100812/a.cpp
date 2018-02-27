#include <cstdio>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 200005;

ll a[maxn];

int main()
{IO;
    ll n;
    cin >> n;
    rep(i, 1, n)
        cin >> a[i];

    ll chazhi = n;
    ll diji = 0;
    int flag = 0;

    rep(i, 1, n)
    {
        ll sum = 0;
        rep(j, i, n)
        {
            sum += a[j];
            if( sum == 0)
            {
                flag = 1;
                if( j - i <= chazhi)
                {
                    diji = i;
                    chazhi = j - i ;
                }
                break;
            }
        }
    }

    if( flag == 1)
        cout << diji << ' ' << chazhi + 1<< endl;
    else cout << -1 <<endl;
}
