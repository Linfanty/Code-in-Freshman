#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int N = 100000+10;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int n,m,i,j,x,L,R,cas = 1,flag;
__int64 sum[N<<2],add[N<<2], cnt[N<<2];//lazy±ê¼Ç

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    cnt[rt] = cnt[rt<<1] && cnt[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l == r)
    {
        scanf("%I64d",&sum[rt]);
        return ;
    }

    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update(int l,int r,int rt)
{
    if( l ==  r )
    {
        sum[rt] = sqrt(sum[rt]);
        if( sum[rt] <= 1)//如果为0，则标记不能再访问了
            cnt[rt] = 1;
        return;
    }
    int m = (l+r) >> 1;
//孩子已经破坏了则不需再访问
    if(L <= m && !cnt[rt<<1]) update(l,m,rt<<1);
    if(R > m && !cnt[rt<<1|1]) update(m+1,r,rt<<1|1);
    PushUp(rt);
}

__int64 query(int l,int r,int rt)
{
    if(L <= l && r <= R )
        return sum[rt];

    int m = (l+r)>>1;
    __int64 res = 0;

    if(L <= m) res += query(l,m,rt<<1);
    else if(R > m) res += query(m+1,r,rt<<1|1);
    return res;
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        build(1,n,1);

        printf("Case #%d:\n",cas++);
        scanf("%d",&m);

        while(m--)
        {
            scanf("%d%d%d",&flag,&L,&R);
            if(L > R)//这里要注意
                swap(L, R);
            if(flag)
                printf("%I64d\n",query(1, n, 1));
            else
                update(1, n, 1);
        }
        printf("\n");
    }

    return 0;
}
