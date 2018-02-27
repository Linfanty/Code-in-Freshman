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

set<ll> st;
set<ll> :: iterator it;
map<ll, ll> mp;
int flag = 0;

ll fac[] ={2,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000
,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
int prime[9] = {2,3,5,7,11,13,17,19};


int dfs(ll x, int step, int pos)
{
    //cout << x << ' ' << step << endl;
    it = st.find(x);
    //if( x == 1)
    if( it != st.end() || x == 1 )
    {
        flag = 1;
        return 1;
    }
    if ( step <= 0)
        return 0;

    int ff = -1;

    for(int i = 1; i <=8 ; ++i)
    {
        if( x % mp[i] == 0)
        {
            ff = i;
            if( x / mp[ff] == 1 )
                flag = 1;
            break;
        }
    }

    //cout << x << ' ' << fac[prime[ff]] << endl;
    if( ff != -1)
    {
        if( x / mp[ff] == 1 )
                flag = 1;
        dfs(  x / mp[ff] , step-1, pos);
    }

    else
    {

        ff = -1;
        for(int i = pos; i >= 1; --i)
        {
            if( x % fac[i] == 0)
            {
                 ff = i;
                 break;
            }
        }
        //cout << ff << ' ';

        if( ff != -1)
        {
            if( x / fac[ff] == 1 )
                flag = 1;
            dfs(  x / fac[ff], step-1, ff);
        }

        else return 0;
    }
}

int main()
{
    rep(i, 0, 18)
        st.insert(fac[i]);
    st.insert(1);
mp[1] = 121645100408832000, mp[2] = 355687428096000, mp[3] = 6227020800, mp[4] = 39916800, mp[5] = 5040, mp[6] = 120, mp[7] = 6, mp[8] = 2;
    int n;
    cin >> n;
    while(n -- )
    {
        flag = 0;
        ll num; int pos;
        scanf("%I64d", &num);
        if( num == 1 || num == 2 )
        {
            cout << "YES" <<endl;
            continue;
        }
        if( num %2 == 1 )
        {
            cout << "NO" <<endl;
            continue;
        }

        dfs(num ,20, 19);
        if( flag == 1 )
            cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}




