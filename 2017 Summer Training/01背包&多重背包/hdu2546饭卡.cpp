#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
using namespace std;
int n;

/// 第i件物品的费用是c[i]，价值是w[i]
int main()
{
    /*
    for(int i = 1; i <= n; ++i)
        for(int j = v; j >= c[i]; --j)
            f[j] = max( f[j],// no fang
                           f[ j - c[i] ] // fang
                           + w[i]); // + value
    */

    while( ~scanf("%d", &n) && n)
    {
        int m, price[2017] = {0},
               dp[2017] = {0};

        for(int i = 1; i <= n; ++i)
            scanf("%d", &price[i] );

        sort( price + 1, price + 1 + n);
        int maxx = price[n];

        scanf( "%d", &m); /// V

        if( m < 5)
        {
            printf("%d\n", m);
            continue;
        }

        m = m - 5;
        for(int i = 1; i < n; ++i)
            for(int j = m; j >= price[i]; --j)
                dp[j] = max( dp[j],
                             dp[j - price[i]]
                             + price[i]);
        printf("%d\n", m + 5 - dp[m] - maxx);
    }
}


