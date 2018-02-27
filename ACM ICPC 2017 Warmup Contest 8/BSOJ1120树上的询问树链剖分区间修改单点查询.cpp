#include<iostream>
#include<cstdio>
#include<cstring>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
using namespace std;
struct Edge
{
    int to,next;
}w[300005];
int cnt=0,h[300005]={0};
struct SegmentTree
{
    int l,r,sum,lazy;
}tree[300005];
int fa[300005]={0},tid[300005]={0},dep[300005]={0},son[300005]={0},size[300005]={0},top[300005]={0};
int rank[300005]={0}, st[300005]={0}, tim=0,n,q,m;

void add(int x,int y)
{   cnt++;w[cnt].to=y;w[cnt].next=h[x];h[x]=cnt;}

void DFS1(int x,int f,int d)
{
    dep[x]=d;
    fa[x]=f;
    size[x]=1;
    for(int i=h[x];i;i=w[i].next)
    {
        int to=w[i].to;
        if(to!=f)
        {
            DFS1(to,x,d+1);
            size[x]+=size[to];
            if(son[x]==0||size[to]>size[son[x]])son[x]=to;
        }
    }
}

void DFS2(int x,int tp)
{
    top[x]=tp;
    tid[x]=++tim;
    rank[tim]=x;//反向映射
    if(son[x]==0)return;
    DFS2(son[x],tp);
    for(int i=h[x];i;i=w[i].next)
    {
        int to=w[i].to;
        if(to!=son[x]&&to!=fa[x])DFS2(to,to);
    }
}

void Pushup(int x)
{  tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;}

void Pushdown(int x)
{
    if(tree[x].lazy)
    {
        int d=tree[x].lazy;
        tree[L(x)].sum+=d;
        tree[R(x)].sum+=d;
        tree[L(x)].lazy+=d;
        tree[R(x)].lazy+=d;
        tree[x].lazy=0;//清零哦。
    }
}

void Build(int l,int r,int root)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].sum=0;tree[root].lazy=0;
    if(l==r)//l=r时就直接给他赋值
    {
    tree[root].sum=st[rank[l]];
    return;
    }
    int mid=(l+r)>>1;
    Build(l,mid,L(root));
    Build(mid+1,r,R(root));
    Pushup(root);//儿子变了，合并标记给父亲节点
}

void update(int l,int r,int root,int delta)
{
    if(l<=tree[root].l&&tree[root].r<=r)
    {
        tree[root].sum+=delta;
        tree[root].lazy+=delta;//懒惰标记一起加哦。
        return;
    }
    Pushdown(root);
    int mid=(tree[root].l+tree[root].r)>>1;
    if(l<=mid)update(l,r,L(root),delta);
    if(r>mid)update(l,r,R(root),delta);
}

void change(int x,int y,int v)
{
    int t1=top[x],t2=top[y];
    while(t1!=t2)
    {
        if(dep[t1]<dep[t2]){swap(t1,t2);swap(x,y);}
        update(tid[t1],tid[x],1,v);
        x=fa[t1];t1=top[x];
    }

    if(dep[x]>dep[y])swap(x,y);
    update(tid[x],tid[y],1,v);
}

int ask(int x,int root)
{
    if(tree[root].l==x&&tree[root].r==x)return tree[root].sum;
    Pushdown(root);//一定要relax一下，更新下层标记
    int mid=(tree[root].l+tree[root].r)>>1;
    if(x<=mid)return ask(x,L(root));
    else return ask(x,R(root));
}
void pre()
{
    memset(w,0,sizeof(w));
    memset(h,0,sizeof(h));
        memset(son,0,sizeof(son));
    memset(size,0,sizeof(size));
    memset(rank,0,sizeof(rank));
    memset(tid,0,sizeof(tid));
    memset(dep,0,sizeof(dep));
    memset(top,0,sizeof(top));
    memset(fa,0,sizeof(fa));
        tim=0;
        cnt=0;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&q) != EOF)
    {
        pre();
        for(int i=1;i<=n;i++)scanf("%d",&st[i]);
        int a,b;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        DFS1(1,0,0);DFS2(1,1);
        Build(1,n,1);
        while(q--)
        {
            char cmd;
            scanf("%s",&cmd);
            if(cmd=='Q')
            {
                int a;
                scanf("%d",&a);
                printf("%d\n",ask(tid[a],1));
            }
            if(cmd=='I')
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                change(a,b,c);
            }
            if(cmd=='D')
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                change(a,b,-c);
            }
        }
    }
}
