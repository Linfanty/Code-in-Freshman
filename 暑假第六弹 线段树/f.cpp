#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 10005
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define ll long long
int len[maxn<<2], lazy[maxn<<2], cover[maxn<<2], mx[maxn<<2];
int a, b, c, n, m;
int t, i, j, cnt, mp[maxn<<2][2], x[maxn<<2], res[maxn<<2];
int hash[10000005], vit[maxn<<2];

/*将-1 定义为没有颜色
0代表有多种颜色， -2
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
    memset(vit, -1, sizeof(vit));
}

void update(int rt, int l, int r, int a, int b, int c)
{
    if( a > r || b < l) return ;
    if(a <= l && b >= r)
    {
        if( c == 0)
            cover[rt] = lazy[rt] = -2;
        else cover[rt] = lazy[rt] = c;
        return;
    }
    pushdown(rt);
    update(lson, a, b, c);
    update(rson, a, b, c);
    pushup(rt);
}

void query(int rt, int l, int r)
{
    if( cover[rt] == -1)
        return;
    else if( cover[rt] > 0 || cover[rt ] == -2)
    {


        for(int i = l; i <= r; ++i)
         if( cover[rt] == -2)
            vit[i] = 0;
          else   vit[i] = cover[rt];
        return;
    }
    //if( a > r || b < l ) return;

    //pushdown(rt);
    query(lson);
    query(rson);
}

int main(){
    while(scanf("%d", &n) != EOF)
    {
        build();
        cnt = 0;
        for(i = 1; i <= n; i ++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if( a>= b) continue;
            update(1, 1, 8000, a+1, b, c);
            ///左开右闭
        }
        query(1, 1, 8000);
        //for(i = 0; i <= 5; i++)
        //   cout << vit[i] << ' ';

        int i = 1;
        while(i < 8005)
        {
            int color = vit[i], j = i + 1;
            if(color == -1)
            {
                ++i;
                continue;
            }
            while( vit[j] != -1 && vit[j] == color && j < 8005)
                ++j;
            ++res[color];
            i = j;
        }

        for(i=0; i<8005; ++i)
            if(res[i])
                printf("%d %d\n",i,res[i]);
        printf("\n");
    }
}
