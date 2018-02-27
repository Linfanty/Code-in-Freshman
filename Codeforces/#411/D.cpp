#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[1000005];
ll mod = 1e9 + 7;
int main()
{
    a[1] = 1;
    //cout <<mod;
    for(int i = 2; i < 1000005;i++)
        a[i] = ((a[i-1]+1) * 2 - 1 )% mod;

    string s;
    cin >> s;
    int len = s.size();
    int flag = 0;
    ll ans = 0;

    for(int i = 0; i < len; i++)
    {
       if(s[i] == 'b')
       {
           ans = (ans + a[flag]) % mod;
       }
       if(s[i] == 'a')
        flag++;
    }

    cout << ans%mod <<endl;

}
