/*一条首尾相接的数轴。设青蛙A的出发点坐标是x，
青蛙B的出发点坐标是y。青蛙A一次能跳m米，
青蛙B一次能跳n米，两只青蛙跳一次所花费的时间相同。
纬度线总长L米。现在要你求出它们跳了几次以后才会碰面。 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>
#include <stdlib.h>
typedef long long ll;
using namespace std;
//d是a，b的最大公约数

void gcd (ll a ,ll  b, ll & d , ll  &x , ll  &y) //a，b分别代表方程的系数，d返回a，b的最大公约数，x，y返回对应的解
{
	if(!b) //当b等于0的时候，方程就变成了ax=gcd（a，0）=a，所以此时明显可以得到方程的解为x=1，y=0，此时d就为a
	{
		d= a;	x=1;	y=0;
	}
	else //递归求方程的解 
	{
		gcd ( b,  a%b , d, y ,x);
		y -= x*(a/b);
	}
 } 


int main()
{
    ll x, y, m, n, l;
    ll a, b;
    ll s, t;
    while(scanf("%lld %lld %lld %lld %lld", &s, &t, &m, &n, &l) != EOF)
    {
    	ll  d;
    	ll ans = t - s;
    	if ( m-n  < 0 )
            b = n - m , ans = s - t ;
    	
    	
        gcd ( l, abs(n-m), d, x, y);
        printf ("%d %d %d %d %d\n",l,  abs(n-m),d,x,y);
        
        
        /*现在我们已经知道了ax+by=gcd（a，b）的解x0，y0，
		  即ax0+by0=gcd（a，b）；
          则等式两边同乘以c/gcd（a，b）则得
          ax0*c/gcd(a,b)+by0*c/gcd(a,b)=c;
		  则可知人如果c不是gcd（a，b）的倍数则无解
        */
        
        if ( ans % d )//无解出现的情况
            printf("Impossible\n") ;
        else
        {
            ll tmp = l / d ;        
            ans = (  ans / d * y ) % tmp ;//求出答案，因答案要求最小，故还得对答案的“周期”取余
            if ( ans < 0 )//如果出现的是负数，就要加上周期
                ans += tmp ;
            printf ("%lld\n",ans);
        }
        
    }
    return 0;
}

