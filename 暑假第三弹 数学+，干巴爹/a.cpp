#include <cstdio>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int m[] = {23, 28, 33};
int a[3], dd;

void exgcd (int a ,int b ,int &d ,int &x ,int &y )
{
    if ( ! b )
        d = a , x = 1 , y = 0 ;
    else
    {
         exgcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}

int exchina(int *a, int *m, int len)
{
    int M = 1, ans = 0;
    rep(i, 0, len-1)
        M *= m[i];
    rep(i, 0, len-1)
    {
        int w = M/m[i];
        int x, y, d;
        exgcd(w, m[i], d, x, y);
        ans += w * x * a[i];
        ans %= M;
    }
    return ans;
}
/*  AC代码 http://blog.csdn.net/zzyy17/article/details/15504863
    int p, e, i, d, cas = 1, ans = 0, icm = 21252;
    while(scanf("%d%d%d%d", &p, &e, &i, &d))
    {
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        ans = (5544 * p + 14421 * e + 1288 * i - d + icm) % icm;
        if(ans == 0)
            ans = icm;
        printf("Case %d: the next triple peak occurs in %d days.\n", cas++, ans);
    }
*/

int main()
{IO;
    int s, t = 0, tt, _;
    cin >> _;
    while( cin >> a[0] >> a[1] >> a[2] >> dd )
    {
        if( a[0] == -1) break;
        int ans = exchina(a, m, 3);

        // x = ai mod(mi)
        // a[]: mod 后的 余数
        // m[]: 对 mi mod 取模

        int M = 23*28*33;// M = 21252
//cout <<"ans: " <<ans << ' ' << dd - ans << ' ' << (dd - ans)/M + 1<< endl<<endl;

        if( dd - ans >= 0 )//是否要加 21252
            tt = ( dd - ans ) /M +1;
        else tt = 0;
//cout << "tt : " << tt <<endl;
        ans += M*tt - dd;
         cout << "Case " << ++t<< ": the next triple peak occurs in " << ans << " days." << endl;


    }
}
