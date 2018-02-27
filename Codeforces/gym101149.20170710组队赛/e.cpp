#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 200005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

int n;
ll l[maxn], r[maxn];
/*
bool check(ll x)
{
    rep(i, 1, n)
    {
        if( l[i] <=  &&  <= r[i] )
            sum++;
        if( sum >=  )
            return true;
    }
    return false;
}

void erfen()
{
    int low = 1, high = n, ans;
    while( low < high)
    {
        ll mid = (low + high);
        if( check( mid) )
        {
            ans = mid ;
            low = mid + 1;
        }
        high = mid + 1;
    }
}
*/
int main()
{
    cin >> n;
    ll max1 = -1e9 -5;
    rep(i, 1, n)
    {
        cin >> l[i] >> r[i];
        max1 = max(max1, l[i]);
    }
    ll ans = 0;
    rep(i, 1, n)
    {
        if( r[i] >= max1)
            ans ++;
    }
    cout << ans << endl;
}

