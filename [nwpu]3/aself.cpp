/*һ����β��ӵ����ᡣ������A�ĳ�����������x��
����B�ĳ�����������y������Aһ������m�ף�
����Bһ������n�ף���ֻ������һ�������ѵ�ʱ����ͬ��
γ�����ܳ�L�ס�����Ҫ������������˼����Ժ�Ż����档 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>
#include <stdlib.h>
typedef long long ll;
using namespace std;
//d��a��b�����Լ��

void gcd (ll a ,ll  b, ll & d , ll  &x , ll  &y) //a��b�ֱ�����̵�ϵ����d����a��b�����Լ����x��y���ض�Ӧ�Ľ�
{
	if(!b) //��b����0��ʱ�򣬷��̾ͱ����ax=gcd��a��0��=a�����Դ�ʱ���Կ��Եõ����̵Ľ�Ϊx=1��y=0����ʱd��Ϊa
	{
		d= a;	x=1;	y=0;
	}
	else //�ݹ��󷽳̵Ľ� 
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
        
        
        /*���������Ѿ�֪����ax+by=gcd��a��b���Ľ�x0��y0��
		  ��ax0+by0=gcd��a��b����
          ���ʽ����ͬ����c/gcd��a��b�����
          ax0*c/gcd(a,b)+by0*c/gcd(a,b)=c;
		  ���֪�����c����gcd��a��b���ı������޽�
        */
        
        if ( ans % d )//�޽���ֵ����
            printf("Impossible\n") ;
        else
        {
            ll tmp = l / d ;        
            ans = (  ans / d * y ) % tmp ;//����𰸣����Ҫ����С���ʻ��öԴ𰸵ġ����ڡ�ȡ��
            if ( ans < 0 )//������ֵ��Ǹ�������Ҫ��������
                ans += tmp ;
            printf ("%lld\n",ans);
        }
        
    }
    return 0;
}

