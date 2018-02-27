#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 100005
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define ll long long
int len[maxn<<2], lazy[maxn<<2], sum[maxn<<2], mx[maxn<<2];
int a, b, c, n, m;

void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt)
{
    if(lazy[rt])
    {
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] =  lazy[rt] * len[rt<<1];
        sum[rt<<1|1] = lazy[rt] * len[rt<<1|1];
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    lazy[rt] = 0;
    len[rt] = (r-l+1);
    if( l == r)
    {
        sum[rt] = 1;
        return;
    }

    build(lson);
    build(rson);

    pushup(rt);
}

void update(int rt, int l, int r)
{
    if( a > r || b < l ) return;
    if( a <= l && b >= r) /**a l r b*/
    {
        lazy[rt] = c;
        sum[rt] = c * len[rt];
        return;
    }

    pushdown(rt);
    update(lson);
    update(rson);

    pushup(rt);
}

ll query(int rt, int l, int r)
{
    if( a > r || b < l ) return 0;
    if( a <= l && b >= r)
        return sum[rt];

    pushdown(rt);

    ll ans = 0;
    ans += query(lson);
    ans += query(rson);
    return ans;
}


int main()
{
    int t, ww = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n,&m);
        build(1, 1, n);
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &c);
            update(1, 1, n);
            //cout << sum[1] << endl;
        }
        printf("Case %d: The total value of the hook is %d.\n", ww++, sum[1]);
    }
}
