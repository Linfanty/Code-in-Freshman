#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

ll n, a[maxn], b[maxn];
ll sum;

bool check(int x)
{
    int i = 1;
    int j = 2;
    int bb = b[1];

    for( j = 2; j <= n; j++)
    {
        if( a[i] + a[9ij] <= b[i] + b[j] )
        {
            //枚举i,找到aj>=x-ai对应的最大的b
            //注意记录个数
            for(i = 1; i <= n ; i++)
                if( a[j] >= x - a[i]  && i!=j )
                    bb = max(bb, b[j]);
            break;
        }
        else if( a[i] + a[j] >= b[i] + b[j])
            return true;
    }



    if( bb + b[i] >= x)
        return true;
    return false;
}

/*
bool check(int x)
{
    rep(i, 1, n)
    {
        rep(j, i+1, n)
        {
            if( a[i] + a[j] <= b[i] + b[j] && a[i] + a[j] >= x )
                return true;
            else if( a[i] + a[j] >= b[i] + b[j] && b[i] + b[j] >= x )
                return true;
        }
    }
    return false;
}
*/
/*
    x = a[i] + a[j];
    while( a[i] + a[j] <= b[i] + b[j])
    {
        if( a[j] >= x - a[i])
        {
            if( b + bi >= x)
             max1 = b;
            i++;
        }
    }
*/
void solve()
{
    ll low = 0, high = maxn, ans;

    while( low <= high)
    {
        ll mid = (low+high)/2;

        if( check(mid) )
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans << endl;
}

void init()
{
    int t, w = 1, sum = 0;
    cin >> t;
    while( t-- )
    {
        cout << "Case #" << w++ << ":" << endl;
        cin >> n;
        rep(i, 1, n)
            cin >> a[i] >> b[i];
        solve();
    }
}

int main()
{
    init();
}
