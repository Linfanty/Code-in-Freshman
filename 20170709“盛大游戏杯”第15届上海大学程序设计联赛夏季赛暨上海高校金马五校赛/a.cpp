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

int main()
{
    int n, m, mp[105], a;

while ( cin >> n >> m)
{
    rep(i,1,m)
        mp[i] = 0;

    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> a;
            if( a == 1)
                mp[j]++;
        }
    }
    rep(i, 1, m)
        if( i != 1)
        cout << ' ' << mp[i];
        else cout << mp[i];

    cout <<  endl;

}
}
