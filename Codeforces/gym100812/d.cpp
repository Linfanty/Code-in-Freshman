#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define inf 0x3f3f3f3f
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 200005;

ll a[maxn];
map<ll, ll> mp;

int main()
{IO;
    ll n, sum = 0, diji, chazhi = inf, flag = 0;;

    cin >> n;
    mp[0] = 0;

    rep(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];

        if( mp.count(sum) )
        {
            flag = 1;
            if( i - mp[sum]  < chazhi) // i - mp[sum] -1  < chazhi ÊÇ´íµÄ
            {
                chazhi = i - mp[sum] ;
                diji = mp[sum] + 1;
            }
        }
        mp[sum] = i;
    }

    //map<int, int>::iterator  iter;
    //for(iter = mp.begin(); iter != mp.end(); iter++)
    //  cout<< iter->first <<"   " << iter->second<<endl;

    if( flag == 1)
        cout << diji << ' ' << chazhi << endl;
    else cout << -1 <<endl;
}
