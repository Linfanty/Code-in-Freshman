#include <stdio.h>
#include <bits/stdc++.h>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 100005;
const ll mod = 1e9+7;

int mp[maxn][30];
int flag[30];
string s[maxn];
int ans[30];
int n, w = 1;

int main()
{
    while( cin >> n)
    {
        mem(mp, 0);mem(flag, 0);mem(ans, 0);
        int max1 = 0;

        for(int j = 1; j<= n; j++)
        {
            cin >> s[j];
            int len = s[j].size(); // 2
            max1 = max(max1, len);
            if( len != 1)
                flag[ s[j][0] -'a' ] = 1;

            for(int i = len-1; i >= 0; i--) // 1 0
                mp[i][ s[j][ len - i - 1] - 'a' ] ++;
        }
        for(int i = 0 ; i < max1-1; i++)
        {
            for(int j = 0; j <= 25; j++)
            {
                if( mp[i][j] >= 26)
                {
                    mp[i+1][j]++;
                    mp[i][j] -= 26;
                }
            }
        }

        int mmx = 0, cnt = 25, ff = -1, vit[30], ans_[30];
        mem(vit, 0);

        for(int i = max1 - 1; i >= 0; i--)
        {
            for(int k = 0; k <= 25; k++)
            {
                mmx = 0;
                ff = -1;
                for(int j = 0; j <= 25; j++)
                {
                    if( vit[j] == 0 && mp[i][j] > mmx )
                    {
                        mmx = mp[i][j];
                        ff = j;
                    }
                }
                if( ff != -1)
                {
                    vit[ff] = 1;
                    ans[ff] = cnt;
                    ans_[cnt] = ff;
                    --cnt;
                }
           }
        }
        int fff = -1, min1 = 30;

        if( cnt == -1)
        for(int i = 0; i <= 25; i++)
        {
            if( flag[ i ] == 1)
            {
                for(int j = 0 ; j <= 25 ; j++)
                {
                    if( i != j  && flag[ j ] == 0)
                    {
                        if( ans[j] < min1)
                        {
                            fff = j;
                            min1 = ans[j];
                        }
                    }
                }
            }
            if( fff != -1)
            {
                swap(ans[i], ans[fff]);
                break;
            }
        }

        //cout << ans['m'-'a'];
        ll res = 0, result = 0;
        for(int j = 1; j<= n; j++)
        {
            res = 0;
            for(int i = 0; i < s[j].size(); i++)
            {
                res = res*26 + ans[ s[j][i] -'a' ];
                res = res%mod;
            }
            //cout << s[j]  << ' '<< res << ' ';
            result += res;
            result = result % mod;
        }
       cout <<"Case #" << w++ << ": "<< result << endl;
    }
}



