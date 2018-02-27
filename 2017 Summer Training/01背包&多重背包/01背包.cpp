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

/// 第i件物品的费用是c[i]，价值是w[i]
int main()
{
    /// 01 背包
    for(int i = 1; i <= n; ++i)
        for(int j = W; j >= w[i]; --j)
            f[j] = max( f[j],// no fang
                        f[ j - w[i] ] // fang
                           + value[i]); // + value


    /// 完全 背包 ( 无限 )

    for(int i = 1; i <= n; ++i)
        for(int j = w[i]; j <= W; ++j )
            dp[j] = max( dp[j],
                        dp[j - w[i]]
                        + value[i]);


    /// 多重 背包 (第 i 件 最多 可用 n[i] 件 )
    f[i][v] = max( f[i-1][ V - k*c[i]],
                   + k*w[i]


                )

    for(int i = )


}


