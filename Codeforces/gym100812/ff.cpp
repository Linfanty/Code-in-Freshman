#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 100005;

int g[maxn], n, m;
int flag[maxn];
int num[maxn];
string s;

void solve2(int hang)
{
    //cout << hang <<endl;
    int cnt, j;
    rep(k, 0, m-1)
    {
        if( s[k] == '+')
        {
            cnt =  hang - flag[k] ;
            int fflag = flag[k];

            rep(j, 2, cnt)
            {
//cout <<"cnt:"<< cnt << " flag[k]: "<<flag[k]<<" fflag: "<< fflag <<endl;
                num[j] += hang - fflag - 1;
                ++fflag;
            }

            flag[k] = hang +1;
        }
    }
}

void solve()
{
    int cnt, j;
    rep(i, 0, m-1)
    {
        cnt = 0, j = i;
        while( s[j] == '.' )
            j++;

        cnt = 1;
        int k = j;
        while( j - i > 0)
        {
            num[cnt++] += j - i ;
            j--;
        }
        i = k;
    }
}

int main()
{//IO;
    cin >> n >> m;

    rep(i, 0, m)
        flag[i] = 1;

    rep(i, 1, n)
    {
        cin >> s;
        solve();
        if( i == 1)
        {
            rep(j, 0, m-1)
                if(s[j] == '+')
                    flag[j] = i +1;
        }
        if( i != 1 )
            solve2(i);
    }

    rep(i, 0, m)
        s[i] = '+';
    solve2(n+1);

    rep(i, 1, max(n,m) )
        if( i == 1)
            cout << num[i] ;
        else cout <<' ' <<  num[i] ;
}
