#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 100005;

struct Node
{
    ll a, b, id;
    bool operator < (const Node& x) const{
        if( a == x.a ) return b < x.b;
        return a < x.a;
    }
}dra[maxn];

ll n, ans[maxn], j , flag = 0, cnt = 1, k, fflag;

/*1.set<pair<int,int> >的用法
set默认的比较规则先按照first比较，如果first相同，再按照second 比较
所以不能用set
set< pair<ll, ll> > s;
        set< pair<ll, ll > > :: iterator it;
        set< pair<ll, ll > > :: iterator it1;
*/
vector< pair<ll,ll> > s;
vector< pair<ll,ll> > ::iterator it;
map<ll, ll> mp;

int main()
{IO;

    cin >> n;
    if( n == 1)
    {
        int q, w;
        cin >> q >> w;
        if(q <= 1)
            cout << 1 << endl << 1 <<endl;
        else cout << "No such luck" << endl;
    }
    else
{

    dra[0].a = 0, dra[0].b = 1 , dra[0].id = 0;
    rep(i, 1, n)
        cin >> dra[i].a >> dra[i].b, dra[i].id = i;
    sort(dra, dra+n+1);

    rep(i, 0, n)
        mp[ dra[i].id ] = i;

    //rep(i, 1, n)    cout << dra[i].a << dra[i].b << dra[i].id << endl;

    rep(i, 0, n-1)
    {
        j = i + 1;
        //cout << i << j<<endl;
        for(; dra[i].b >= dra[j].a && j <= n; j++ )
            s.push_back( make_pair( dra[j].b, dra[j].id ));
        //在set j中找比 i.b最大的
        ll max1 = -1, maxid = -1;

        for(it = s.begin(); it!= s.end(); it++)
        {
            //cout << it->first <<' ' << it ->second << ' ' << max1 <<endl<<endl;
            if( it->second == n )
            {
                flag = 2;
                ans[ cnt++ ] = n;
                break;
            }
            if( it->first >= max1)
            {
                max1 = it-> first;
                maxid = it-> second;
            }
        }

        //it = upper_bound(s.begin(), s.end(), make_pair( dra[i].b, -1ll));
        //    cout << it->first << "   " << it->second << endl;
        if( flag == 2)
            break;

        if( maxid == -1 )
        {flag = 1; break;}

        ans[ cnt++ ] = maxid;
        s.erase( s.begin() + mp[maxid] );
        //cout << "mp[maxid] : " << mp[maxid] <<endl;
        //for(it = s.begin(); it!= s.end(); it++)
        //    cout << it->second << ' ';
        i =  mp[maxid] -1;
    }


    if( flag == 1)
        cout << "No such luck" << endl;
    else
    {
        cout << cnt-1 << endl;
        rep(i, 1, cnt-1 )
            if( i == 1)
                cout <<ans[i];
            else cout << ' ' << ans[i] ;
    }
}
}
