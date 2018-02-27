#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
const int  maxn = 2e5 + 5;
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;

int n, m, a, b, k;

int main()
{IO;
    string s[10];
    cin >> n >> k;
    rep(i, 1, n)
        cin >> s[i];
    int chazhi = 20;
    int min1[10], max1[10];

    rep(i, 0, k)
    {
        max1[i] = 0;
        min1[i] = 10;
    }

    rep(i, 0, k-1)
    {
        rep(j, 2, n)
        {
            max1[i] = max(max1[i], s[j][i]-'0');
            min1[i] = min(min1[i], s[j][i]-'0');
        }
    }

    int flag = 0;
    rep(i, 0, k-1)
    {
        if( (max1[i] - min1[i] ) < chazhi )
        {
            chazhi = (max1[i] - min1[i] );
            flag = i;
        }
    }

    cout << flag << endl;

    rep(i, 1, n)
    {
        for(int j = 0; j < k && j!= falg ; j++)
        {
            if( s[i][j]  s[i][j] )

        }

    /*    rep(j, )
        while(s[i][j]  s[i][j-1] )
        mm[flag] =
    */
    }

    //min1 = min(s[i]-s[i-1], min1);
}
