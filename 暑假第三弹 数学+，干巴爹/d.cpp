#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

ll x[30], y[30];
ll ans, t, n, m ,k, d;
ll lx, rx, ly, ry, area, xc;

ll dfs(ll a)
{
    lx = inf, ly = inf, rx = 0, ry = 0;
    d = 0;

    rep(j ,1, k) ///1到k种遍历一次
        if( a&(1<<(j-1))) //a<<n:a左移n位 a乘以2的n次方
        {
///001 与 001 010 100 与运算 看二进制每一位是否选取， 状压
            //cout <<"a: " << a << ' ' << (1<<(j-1)) << ' ' << (a&(1<<(j-1))) << endl;
            lx = min(lx, x[j]);
            ly = min(ly, y[j]);
            rx = max(rx, x[j]);
            ry = max(ry, y[j]);
            d++;
        }

    //cout << "lx: " << lx << ly << rx << ry <<endl;
    area = lx * ly * ( n - rx + 1 ) * ( m - ry + 1 );
    //cout << endl << ans1 << ' ' << ans2 << ' ' << xc << endl;

    if( d%2 == 1) //奇数- (本应为 奇数加 偶数减， 但ans要减它们)
        ans -= area;
    else ans += area; // 偶数 +
}

int main()
{//IO;
    //cin >> t;
    scanf("%I64d", &t);
    while( t-- )
    {
        scanf("%I64d %I64d %I64d",&n,&m,&k);
        //cin >> n >> m >> k;
        rep(i, 1, k)
            //cin >> x[i] >> y[i];
            scanf("%I64d %I64d",&x[i],&y[i]);

        ans = ( (n*(n+1) ) * ( m*(m+1)) ) /4;

        ll aaa =  pow(2,k)-1;
        rep(i, 1, aaa)
            dfs(i);/// 000 到 111 种选择方式 状态压缩
        //cout <<ans<<endl;
        printf("%I64d\n",ans);
    }
}
