#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 10005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;
ll C[72][72];

int c()
{
    	C[1][0] = C[1][1] = 1;
    for (int i = 1; i <= 71; i++)
        C[i][0] = 1;
    for (ll i = 2; i <= 71; i++)
        for (ll j = 1; j <= i; j++)
            {
            	C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
}

int main()
{
    int k, n, t, p;
    cin >> k;
    c();
    while( k-- )
    {
        cin >> n >> t >> p;
        if( p*n > t)
            cout << 0 << endl;
        else if( p*n == t)
            cout << 1 << endl;
        else
        {

        t = t-n*p;
        //分成N组需要N-1个隔板
        //M个物体,需要N-1+M个空隙

        cout << C[n+t-1][n-1]<< endl;
        }
    }

}
