#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define maxn 1000005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        double l = 0, r = 0 , d, ans = 0;
        ll x = 0, a;

        cin >>n >>m >> d;


        cin >>a;
        ans += d;

        d = d/2; l = (double)a - d; r = (double)a + d;

        rep(i,2,n)
        {
            cin >> a;
            if( (double)a-d >= r )
            {
                ans += (double)a+d-r;
                l = a-d;
                r = a+d;
            }
            else continue;
            /*
            else //if( a-d <= r)
            {
                ans += a+d-r;
                l = a-d;
                r = a+d;
            }
            */
            //cout << ans<<' '<< l<<' '<< r <<endl;
        }

        if( ans >= m * d *2 )
            cout << "YES" << endl;
        else cout <<"NO"<<endl;

        //cout << ans <<endl;
    }

}
