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
    //freopen("acm.in", "r", stdin);
    //freopen("acm.out", "w", stdout);
    int n, m;
    int a, max1 = 0, min1 = 20;
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a;
        cout << "(10" ;
        rep(j, 1, a)
            cout <<"-1";
        cout << ")";
        if( i != n)
            cout << "*";
    }
    rep(i, 1, m)
        cin >> a;
    cout << "=0"<<endl;
}

