#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

ll s, t, m, n, l;

void exgcd ( ll a , ll b , ll &d , ll &x , ll &y )
{//a��b�ֱ�����̵�ϵ����d����a��b�����Լ����x��y���ض�Ӧ�Ľ�
    if ( ! b )//��b����0��ʱ�򣬷��̾ͱ����ax=gcd��a��0��=a�����Դ�ʱ���Կ��Եõ����̵Ľ�Ϊx=1��y=0����ʱd��Ϊa
        d = a , x = 1 , y = 0 ;
    else
    {//�ݹ��󷽳̵Ľ�
         exgcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}
//��x+mt��-��y+nt��=kl
//(m-n)t-kl=y-x (t-s);

int main()
{
    cin >> s >> t >> m >> n >> l;
    ll a, b, d, x, y, ans;
    a = l; b = m - n; ans = t - s;
    if( b < 0 ) b = n - m, ans = s - t;
    exgcd(a, b, d, x, y);
    //cout << d  << ' ' << x << ' '<< y <<endl; 1 0 1
    if( ans % d ) cout << "Impossible" << endl;
    else
    {//x0 = x*c/d + k(b/d) ;
     //y0 = y*c/d - k(a/d);
        ans = ans/d *y %(l/d);//cishu:t
        //ans = ans/d*x  %(l/d);
        if(ans<0) ans += l/d;
        cout << ans << endl;
    }
}
