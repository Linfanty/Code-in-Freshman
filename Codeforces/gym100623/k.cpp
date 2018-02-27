#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
#define maxn 40
const int N = 2e5 + 10;
using namespace std;

map<ll, ll> mp;
vector<ll> ans;//记录答案

int main()
{
    //freopen("key.in", "r", stdin);
    //freopen("key.out", "w", stdout);
    ll pos = 1, n, m, x[maxn];
    cin >> n >> m;
    rep(i, 1, n){
        cin >> x[i];
        mp[ x[i] ]++;
    }

    sort(x+1, x+n+1);
    if( !mp[1] )
        ans.push_back(1), m--;
    else pos++;

    if( !m ){
        cout << 1 <<endl;
        return 0;
    }

    ll sum = 1;
    // sum pos用一个pos标记就好   x[] n m
    while(m){
        //pos已经超出n个 || pos的数字已经大于sum+1
        if( pos == n + 1 || x[pos] > sum+1 ){
            ans.push_back( sum+1 );
            sum = sum*2 + 1;
            m --;
            continue;
       }
        else {
            sum += x[pos];
            pos++;
        }
    }
    rep(i, 0, ans.size()-1)
        if( i == 0)
            cout << ans[i] ;
        else cout << ' ' << ans[i];
}
