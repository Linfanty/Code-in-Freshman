//区间段内的数进行整体的更新
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 100005
int sum[MAX<<2];
void push_up(int idx)
{
    sum[idx] = (sum[idx<<1]==sum[idx<<1|1]) ? sum[idx<<1] : -1;
}
void build(int l,int r,int idx)//建树
{
    if(l==r)
    {
        sum[idx]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,idx<<1);
    build(mid+1,r,idx<<1|1);
    push_up(idx);
    return;
}
int p, a, b;
void updata(int l,int r,int idx)//更新
{
    if(a<=l&&r<=b){
        sum[idx]=p;
        return;
    }

    if(sum[idx]>0)
        sum[idx<<1] = sum[idx<<1|1] = sum[idx];//由于后面必定对子树操作，所以更新子树的值等于父亲的值

    int mid = (l+r)>>1;
    if( a<=mid && sum[idx<<1]!=p ) updata(l, mid, idx<<1);
    if( b>mid && sum[idx<<1|1]!=p ) updata(mid+1, r, idx<<1|1);
    push_up(idx);
}

int query(int l,int r,int idx)//查询//区间求和
{
    if(sum[idx]>0)//纯色直接算这个区间
        return sum[idx]*(r-l+1);

    int mid=(l+r)>>1;
    int res=0;

    if(a<=mid) res += query(l,mid,idx<<1);//不存则左右子树去找
    if(b>mid)  res += query(mid+1,r,idx<<1|1);//不存则左右子树去找
    return res;
}

int main()
{
    int n, m, t, ww = 1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        build(1,n,1);
        while(m--)
        {
            scanf("%d %d %d",&a, &b, &p);
            updata(1, n, 1);
        }
        a=1, b=n;
        printf("Case %d: The total value of the hook is %d.",ww++,query(1,n,1));
    }
return 0;
}
