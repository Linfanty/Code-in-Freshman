#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

#define lson 2*i
#define rson 2*i+1
#define LS l,mid,lson
#define RS mid+1,r,rson
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N (1005*1005)
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
const int mod = 1e9+7;

struct node
{
    int l,r,id;
} a[N];
int n,c[N],x,y;

int cmp(node a,node b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    return a.r<b.r;
}

int sum(int x)
{
    int ret = 0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=y)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}

LL ans;
int main()
{
    int i,j,k,l,r,t,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x,&y,&n);
        MEM(c,0);
        for(i = 1; i<=n; i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a+1,a+1+n,cmp);
        ans = 0;
        for(i = 1; i<=n; i++)
        {
            add(a[i].r,1);
            ans+=sum(y)-sum(a[i].r);
        }
        printf("Test case %d: %lld\n",cas++,ans);
    }

    return 0;
}
