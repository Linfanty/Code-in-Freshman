#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define max1 100005
#define maxn 50005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

ll  n, t, a, b, c;


void gcd ( ll a , ll b , ll &d , ll &x , ll &y )
{//a，b分别代表方程的系数，d返回a，b的最大公约数，x，y返回对应的解
    if ( ! b )//当b等于0的时候，方程就变成了ax=gcd（a，0）=a，所以此时明显可以得到方程的解为x=1，y=0，此时d就为a
        d = a , x = 1 , y = 0 ;
    else
    {//递归求方程的解，等下证明
         gcd ( b , a % b , d , y , x ) ;
         y -= ( a / b ) * x ;
    }
}

int main()
{
    while (cin >> a >> b >> c )
    {

    ll x = 0, y = 0, d = 0;

    //if(b < a)
    //    swap(a,b);

    gcd (a ,b, d, x, y);
    ll a1 =  a / d;
    ll b1 = b / d;
    cout << a1 << ' ' << b1<<endl;


    if(d == 0)
        cout << 0 << endl;
    //if ( a == 0 && b == 0)
    else if( c % d != 0)
        cout << -1 <<endl;
    else
        cout << x *c /d << ' ' << y*c/d <<endl;

    // k zhengshu
        cout << x *c /d - b1 << ' ' << y *c /d + a1 << endl;
        cout << x *c /d + b1 << ' ' << y *c /d - a1 << endl;



    cout << d <<' ' << x <<' '<< y << endl;



    }
    return 0;
}
