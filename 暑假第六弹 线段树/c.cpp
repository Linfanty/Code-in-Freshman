#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 100005;
    int mx[maxn*4], sum[maxn*4], lazy[maxn*4], len[maxn*4];
    char op[10];
    int a, b, c, n, t, ww = 1;
        #define lson rt<<1, l, (l+r)>>1
        #define rson rt<<1|1, ((l+r)>>1)+1, r
        #define mid (l+r)>>1

    void pushup(int rt){
        mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    void pushdown(int rt)
    {
        if( lazy[rt] )
        {
            lazy[rt<<1] += lazy[rt];
            lazy[rt<<1|1] += lazy[rt];
            sum[rt<<1] += lazy[rt] * len[rt<<1];///rt<<1.len
            sum[rt<<1|1] += lazy[rt] * len[rt<<1|1]; ///rt<<1|1.len
            lazy[rt] = 0;
         }
    }

    void build(int rt, int l, int r)
    {
        lazy[rt] = 0;
        len[rt] = r - l + 1;
        if(l == r)
            {scanf("%lld", &sum[rt]); return;}
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int rt, int l, int r)
    {
        if( a > r || b < l ) return;
        if(a <= l && b >= r) /** a l  r b  */
        {
            lazy[rt] += c;
            sum[rt] += c * len[rt];
            return;
        }
        pushdown(rt);
        update(lson);
        update(rson);
        //if( a <= mid) update(lson); /** a mid  */
        //if( b > mid ) update(rson); /** mid b   */
        pushup(rt);
    }

    int query(int rt, int l, int r)
    {
        if(a <= l && b >= r )   return sum[rt];/*a l_r  b*/
        if(a > r || b < l) return 0;/* r a */ /* b l */
        int ans = 0;
        pushdown(rt);
            ans += query(lson);
            ans += query(rson);
        //if( a <= mid) ans += query(lson);
        //if( b > mid ) ans += query(rson);
        return ans;
    }

main()
{
    int m;
    while( scanf("%lld %lld",&n, &m)  !=EOF)
    {
        build(1, 1, n);
		while (m--)
        {
            scanf("%s",op);

			if(op[0] == 'C')
            {
                scanf("%lld %lld %lld", &a, &b, &c);
                update(1, 1, n);
            }

            else if(op[0] == 'Q')
            {
                scanf("%lld %lld", &a, &b);
                printf("%lld\n", query(1, 1, n));
            }
        }
	}
    return 0;
}
