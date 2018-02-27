#include <stdio.h>
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 100005;

int ans_l, ans_r;
ll a[maxn], sum[maxn], ans;

// 长度为n的序列 求区间min乘sum
// 枚举每一个点 找以其为最小值的区间
// 暴力： 超时
// 单调递增栈 对于每个新a[i]
// 小于等于 栈顶： 以栈顶为最小值的区间的右端是i
// 栈顶a[j] 出栈 ： a[k] < a[j] 更新栈顶

// 右端值 新元素左端的值也要更..新为a[j]的左端
// 重复操作直到栈顶  大于 新元素

// 出栈时 前计算 其左右区间 为答案

struct Node {
    int l, r;//num数值 pre向前延伸多少个 next向后延伸多少个
    ll num;
}s[maxn];

void update(int top)    {
    int l = s[top].l , r = s[top].r;
    cout << top << ' ' << l << ' ' << r << ' ' << ans << endl;
    if( (sum[r] - sum[l-1]) * s[top].num > ans) // sum 前缀和左区间l要减1 l-1;
    {
        ans = (sum[r] - sum[l-1]) * s[top].num;
        ans_l = l;
        ans_r = r;
    }
    if( top > 0)
        s[top - 1].r = s[top].r;
}


int main()  {
    ll n;
    while( cin >> n )
    {
        ans = -1;  sum[0] = 0;

        rep(i, 1, n)
            cin >> a[i], sum[i] = sum[i-1] + a[i];// 3 1 6 4 5 2

        int top = -1; /// 栈底记为-1
        rep(i, 1, n)    {
            Node v = {i, i, a[i]};
            while( top != -1 && s[top].num >= a[i])
            {
                update(top);/// 0 1
                v.l = s[top].l; /// V.L = S[TOP].L = S[0].L = 1
                top--;
            }
                                   // top
            s[++top].l = v.l;     // 1 1 3 3 5 3
            s[top].r = v.r;       // 1 2 3 4 5 6
            s[top].num = v.num;   // 3 1 6 4 5 2
            // cout << s[top].l << ' ' << s[top].r << ' ' << s[top].num << endl;
        }

        while( top!= -1)
        {
            update(top);
            top--;
        }
        cout << ans << endl;
        cout << ans_l<< ' ' << ans_r << endl;
    }
}
