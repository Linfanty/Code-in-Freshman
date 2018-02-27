#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1) 
const int N = 2e5 + 5;
using namespace std;
//http://blog.csdn.net/panyanyany/article/details/6776300
struct segtree
{
    int l, r;
    int mx, sum;
}tr[N*4];

int a[N];
void push_up (int id)
{
    tr[id].sum = tr[lid].sum + tr[rid].sum;
    tr[id].mx = max( tr[lid].mx, tr[lid].mx); 
}

int build(int id, int l, int r)
{
    tr[id].l = l;   tr[id].r = r;
    if( l == r)
    {
        return tr[id].mx = a[l];
    }
    int mid = (l+r)>>1;
    int a, b;
    a = build( lid, l, mid);
    b = build( rid, mid+1, r);
    //push_up(id);
    return tr[id].mx = max(a, b);
}

void updata(int id, int x, int v)
{
    if( tr[id].l == tr[id].r)
    {
        tr[id].sum = tr[id].mx = v;
        return;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    updata( x <= mid ? lid : rid, x, v);
    push_up(id);
}

int query(int id, int l, int r)
{
    if(tr[id].l == l && tr[id].r == r)
        return tr[id].mx;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if( r <= mid) return query(lid, l, r);
    if( l > mid) return query(rid, l, r);
    return max(query(lid, l, mid) , query(rid, mid+1, r));
}

/*
int query(int r,int A,int B)  
{  
    int mid;  
    if (B<tr[r].l||tr[r].r<A)  
        return 0;  
    if (A<=tr[r].l&&tr[r].r<=B)  
        return tr[r].mx;  
    return max(query(r*2,A,B),query(r*2+1,A,B));  
}  
*/
/*
int query(int root, int left, int right)  
{  
    int mid ;  
    // 若此区间与 root 所管理的区间无交集  
    if (tr[root].l > right || tr[root].r < left)  
        return 0 ;  
    // 若此区间包含 root 所管理的区间  
    if (left <= tr[root].l && tr[root].r <= right)
        return tr[root].mx ;  
    // 若此区间与 root 所管理的区间部分相交  
  
    int a, b ;  // 不能这样 max (find(...), find(...));  
    a = query (2 * root, left, right) ;  
    b = query (2 * root + 1, left, right) ;  
    
    return max (a, b) ;  
} 
*/
int main()
{   
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    
    build(1,1,n);

    char ch;
    int x, y;
    for(int i = 1; i <= m; i++)
    {
        getchar();  
        scanf("%c%d%d",&ch, &x, &y);
        if(ch == 'Q')
            printf("%d\n",query(1,x,y));
        else 
        {
            a[x] = y;
            updata(1,x,y);
        }
    }
}