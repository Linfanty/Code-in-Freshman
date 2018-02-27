#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 100000+10;

int n,sum;

struct node
{
    int l,r,n;
} tree[maxn<<2];

void init(int l,int r,int i)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].n = 1;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(l,mid,2*i);
        init(mid+1,r,2*i+1);
    }
}

void insert(int i,int x,int y,int m)
{
    if(tree[i].n == m)//相同则不用修改了
        return ;
    if(tree[i].l == x && tree[i].r == y)//找到了区间，直接更新
    {
        tree[i].n = m;
        return ;
    }
    if(tree[i].n != -1)//如果该区间只有一种颜色
    {
        tree[2*i].n = tree[2*i+1].n = tree[i].n;//由于后面必定对子树操作，所以更新子树的值等于父亲的值
        tree[i].n = -1;//由于该区域颜色与修改不同，而且不是给定区域，所以该区域必定为杂色
    }
    //父区间为杂色时对所有子节点进行操作
    int mid = (tree[i].l+tree[i].r)>>1;

    if(x>mid)   insert(2*i+1,x,y,m);
    else if(y<=mid) insert(2*i,x,y,m);
    else
    {
        insert(2*i, x, mid, m);
        insert(2*i+1, mid+1, y, m);
    }
}

int find(int i)//区间求和
{
    if(tree[i].n != -1)//纯色直接算这个区间
        return (tree[i].r - tree[i].l+1)*tree[i].n;
    else//不存则左右子树去找
        return find(i*2)+find(i*2+1);
}

int main()
{
    int t,i,k,x,y,m;
    int cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        init(1,n,1);
        while(k--)
        {
            scanf("%d%d%d",&x,&y,&m);
            insert(1,x,y,m);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas++,find(1));
    }

    return 0;
}
