#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int N = 2e5 + 10;
using namespace std;

int s[105][105];

int main()
{
    //freopen("class.in", "r", stdin);
    //freopen("class.out", "w", stdout);
    int n, r, c, flag = 0;
    cin >> n >> r >> c;
    int min1 = min(r,c);

    //if( n >= min1 * min1 )

    if( n >= (min1 * 2) -1 )
        cout << min1 << endl;
    else cout << (n+1) / 2 <<endl;

    if( n >= min1 * min1)
    {
        rep(i, 1, min1)
            rep(j, 1, min1)
                s[i][j] = 1;
        n = n - min1 * min1;

        while( n > 0)
        {
            //cout << n << ' ';
            if( r > c)
                flag = 1;
            if( flag == 0)
            {
                for(int i = 1; i <= r && n > 0; i++)
                {
                    for(int j = min1 + 1; j <= c && n > 0; j++)
                    {
                        s[i][j] = 1;
                        n--;
                        if( n < 0)
                            break;
                        //cout << i << ' ' << ' ' << j << ' '<< n << endl;
                    }
                     if( n < 0)
                            break;
                }
            }
            if(  flag == 1 )
            {
                for(int i = min1+1; i <= r && n > 0; i++)
                {
                    for(int j = 1; j <= c && n > 0; j++)
                    {
                        s[i][j] = 1;
                        n--;
                        if( n < 0)
                            break;
                        //cout << i << ' ' << ' ' << j << ' '<< n << endl;
                    }
                     if( n < 0)
                            break;
                }
            }
        }
    }
    else if( n>= min1*2-1 )
    {
        rep(i, 1, min1)
            s[1][i] = 1;
        rep(i, 1, min1)
            s[i][1] = 1;

        n = n - (min1*2-1);

        for(int i = 2; i <= r && n > 0; i++ )
        {
            for(int j = 2; j <= min1 && n > 0 ; j++)
            {
                s[i][j] = 1;
                --n;
            }
        }
    }
    else //if( (n+1)/2 >= min1 )
    {
        if( n == 1)
            s[1][1] = 1;
        else if( n % ((n+1)/2) != 0 )
        {
            rep(i, 1, (n+1)/2)
                s[1][i] = 1;
            rep(i, 1, (n+1)/2 )
                s[i][1] = 1;
        }
        else
        {
            rep(i, 1, (n+1)/2+1)
                s[1][i] = 1;
            rep(i, 1, (n+1)/2 )
                s[i][1] = 1;
        }
    }
    rep(i, 1, r)
    {
         rep(j, 1, c)
            if( s[i][j] == 1)
                cout << '#';
            else cout << '.';
        cout << endl;
    }
}


