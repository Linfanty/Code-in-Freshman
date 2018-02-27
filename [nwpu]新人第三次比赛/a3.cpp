#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
//d是a，b的最大公约数	

void gcd ( __int64 a , __int64 b , __int64 &d , __int64 &x , __int64 &y )
{
    
    if ( ! b ) 
        d = a , x = 1 , y = 0 ;
    else 
        gcd ( b , a%b , d , y , x ) , y -= x * ( a / b ) ; 
}

int main()
{
    __int64 s , t , m , n , l ;
    while ( ~ scanf ("%I64d%I64d%I64d%I64d%I64d" , & s , & t , & m , & n , & l ) )
    {
        __int64 a , b , d , ans ;
        __int64 x , y ;
        a = l ;
        b = m - n ;
        ans = t - s ;
        if ( b < 0 )
            b = n - m , ans = s - t ;
        gcd ( a , b , d , x , y ) ;
        
         printf ("%d %d %d %d %d\n",a,b,d,x,y);
         
        if ( ans % d )//无解出现的情况
            printf("Impossible\n") ;
        else
        {
            __int64 tmp = l / d ;        
            ans = (  ans / d * y ) % tmp ;//求出答案，因答案要求最小，故还得对答案的“周期”取余
            if ( ans < 0 )//如果出现的是负数，就要加上周期
                ans += tmp ;
            printf ("%I64d\n",ans);
        }
    }
    return 0;
}
