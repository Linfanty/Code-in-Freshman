#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 65;

int n, a[maxn], vit[maxn], sum, flag , len ;

void dfs(int dep, int now_len, int u)
// dep为当前已被用过的小棒数 u为当前要处理的小棒。
{
// 1.以一个小棒为开头，用dfs看看能否把这个小棒拼凑成len长，
// 如果可以，用vis[i]记录下用过的小棒，然后继续以另外一个小棒为开头，
    if( flag ) return;
    if( now_len == 0)   {//  当前长度为0，寻找下一个当前最长小棒。
        int k = 0;
        while( vit[k] ) k++;

        vit[k] = 1;
        dfs(dep+1, a[k], k+1);
        vit[k] = 0;

        /// dfs(1, 4, 1)
        /// dfs(3, 3, 2)
        return;
    }

    if( now_len == len)///又拼凑成了一根原棒。
    {
        if( dep == n )
            flag = 1;
/// 3.如果当前最长的小棒不能拼成len长，那么就返回前一步，更改前一步的最长小棒的组合情况
        else dfs(dep, 0, 0);/// dfs(2, 0, 0);
        return;
    }

/// 17,9,9,9,9,8,8,5,2……如果当前最长小棒为17 9不行 后到8
    for(int i = u; i < n; i ++)
    {
        if( !vit[i] && now_len + a[i] <= len)
        {
            if( !vit[i-1] && a[i] == a[i-1])
                continue;// 不重复搜索 最重要的剪枝


            vit[i] = 1;
            dfs(dep+1, now_len + a[i], i + 1);
            vit[i] = 0;
            /// dfs(2, 4 + 3, 2)
            /// dfs(2, 4 + 2, 3)
            /// dfs(2, 4 + 1, 4)

            /// dfs(4, 3 + 2, 3)

        }
    }
}

int main()
{
    while(scanf("%d", &n) && n != 0)
    {
        sum = 0;    mem(vit, 0);

        rep(i, 0, n)
        scanf("%d", &a[i]), sum += a[i];
        flag = 0;

        sort(a, a + n , greater<int>());///4 3 2 1 2.小棒的长度从大到小排序

        for(len = a[0]; len < sum ; len ++)
        {
            if( sum % len == 0)/// 10 / 5 枚举能被sum整除的长度
            {
                mem(vit, 0);
                dfs(0, 0, 0);
                if( flag )
                    break;
            }
        }
        printf("%d\n", len);
    }
}
