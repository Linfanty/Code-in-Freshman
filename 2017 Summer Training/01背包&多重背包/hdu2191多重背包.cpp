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

int main(){
    int t, nvalue, nkind,
        value[105], weight[105], bag[105];

    int dp[105];

    scanf("%d", &t);
    while( t-- )
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &nvalue, & nkind);

        for(int i = 0; i < nkind; ++i)
        {
            scanf("%d %d %d", &value[i], &weight[i], &bag[i]);
            for(int j = 0; j < bag[i]; ++j) // Ã¶¾Ù ¸öÊý
            {
                for(int k = nvalue; k >= value[i]; --k) // 01
                {
                    dp[k] = max( dp[k],
                                 dp[ k - value[i]] + weight[i]);
                }
            }
        }
        printf("%d\n", dp[nvalue]);

    }

/*1
8 2
2 100 4
4 100 2
*/
}
