#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
const int  maxn = 2e5 + 5;
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;

ll n, m, num[maxn];
string s;
map<string, ll> mp;
map<ll, string> mm;

int main()
{IO;
    cin >> n >> m;
    int cnt = 1;
    int aa = 0, max1 = -1;
    string ans;

    rep(i, 1, n)
    {
        cin >> s;
        aa = 0;

        rep(i, 0, m-1)
            if(s[i] == '1')
                aa++;

        if( aa < 8 || aa > 15)
            continue;

        if( !mp.count(s) )
        {
            mp[s] = i;
            ++cnt;
        }
        else   num[ mp[s] ]++;



        if( num[mp[s]] > max1)
        {
            max1 = num[mp[s]];
            ans = s;
        }

    }

    if( cnt == 1)
    {
        char s[5005];
        rep(i, 0, 7)
            cout << 1;
        rep(i, 8, m-1)
            cout << 0;
    }
    else cout << ans <<endl;
}
