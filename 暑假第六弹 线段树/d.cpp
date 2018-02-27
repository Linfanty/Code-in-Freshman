#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 30005
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define ll long long
int len[maxn<<2], lazy[maxn<<2], cover[maxn<<2], mx[maxn<<2];
int a, b, c, n, m;
int t, i, j, cnt, mp[maxn<<2][2], x[maxn<<2], res[maxn<<2];
int hash[10000005];

/*将-1 定义为没有颜色
0代表有多种颜色，
1到m代表各自的颜色，
线段树只要在0时向下,
其他的直接统计颜色。*/
/// 1 ，10      1，4   7,10 两个节点中还有值的话，要多加一个节点，代表两个节点中间的值。
void pushup(int rt)
{
    if( !cover[rt<<1] || !cover[rt<<1|1] || cover[rt<<1] != cover[rt<<1|1])
        cover[rt] = 0;
    else cover[rt] = cover[rt<<1|1];
}

void pushdown(int rt)
{
    if(lazy[rt] != -1)
    {
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        cover[rt<<1] =  lazy[rt];
        cover[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
    }
}

void build(){
    memset(cover, -1, sizeof(cover));
    memset(lazy, -1, sizeof(lazy));
    memset(res, 0, sizeof(res));
}

void update(int rt, int l, int r, int a, int b, int c)
{
    if( a > r || b < l) return ;
    if(a <= l && b >= r)
    {
        cover[rt] = lazy[rt] = c;
        return;
    }
    pushdown(rt);
    update(lson, a, b, c);
    update(rson, a, b, c);
    pushup(rt);
}

void query(int rt, int l, int r, int a, int b)
{

    if( cover[rt] == -1)
        return;
    else if( cover[rt] > 0)
    {
        res[ cover[rt]  ] = 1;
        return;
    }
    //if( a > r || b < l ) return;
    pushdown(rt);
    query(lson, a, b);
    query(rson, a, b);

}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);    cnt = 0;
        for(i = 1; i <= n; i ++)
        {//离散化
            scanf("%d %d", &mp[i][0] , &mp[i][1]);
            x[cnt++] = mp[i][0];
            x[cnt++] = mp[i][1];
        }
        sort(x, x + cnt);
        cnt = unique(x, x + cnt) - x;

        for(i = 1; i <= cnt; i++)
            hash[x[i-1]] = i;
        build();

        for(i = 1; i <= n; i++)
            update(1, 1, cnt, hash[mp[i][0]], hash[mp[i][1]], i );

        int ans = 0;
        query(1, 1, cnt,  1,cnt);
        for(i = 1; i <= n; i++)
            if( res[i] )
                ans++;
        printf("%d\n", ans);
    }
}
/**
for(i = 0; i <= cnt-1; i++)
    cout << x[i] << ' '<< hash[x[i]] << ' '<< i << endl;
1 1
2 2
3 3
4 4
6 5
7 6
8 7
10 8
for(i = 1; i <= n; i++)
    cout <<hash[mp[i][0]] << ' ' << hash[mp[i][1]] <<endl;
1 4
2 5
7 8
3 4
6 8
 */


