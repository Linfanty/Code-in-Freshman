#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

//2,147,483,647
ll l, u;

int gcd(int a, int b)
{
    return b? gcd(b, a%b) : a;
}

void exgcd ( ll a , ll b , ll &d , ll &x , ll &y )
{//a，b分别代表方程的系数，d返回a，b的最大公约数，x，y返回对应的解
    if ( ! b )//当b等于0的时候，方程就变成了ax=gcd（a，0）=a，所以此时明显可以得到方程的解为x=1，y=0，此时d就为a
        d = a , x = 1 , y = 0 ;
    else
    {//递归求方程的解
         exgcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}

//x0 = x*c/d + k(b/d) ;
///y0 = y*c/d - k(a/d);

int main()
{
    ll x, y, d;
    while( cin >> l >> u)
    {
         exgcd(l, u, d, x, y);
         //cout << x <<' '<<  y <<' '<< d <<endl;
         if( d!= 1)
            cout << "sorry" <<endl;
         else
         {
             while( x < 0)
             {
                 x = x + u;
                 y = y - l;
             }
             cout << x << ' ' << y<<endl;
         }
    }
}
