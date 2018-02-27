#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1) 
const int N = 100005;
using namespace std;
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

void build(int id, int l, int r)
{
    tr[id].l = l;   tr[id].r = r;
    if( l == r)
    {
        tr[id].sum = tr[id].mx = a[l];
        return ;
    }
    int mid = (l+r)>>1;

    build( lid, l, mid);
    build( rid, mid+1, r);
    push_up(id);
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
        return tr[id].sum;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if( r <= mid) return query(lid, l, r);
    if( l > mid) return query(rid, l, r);
    return query(lid, l, mid) + query(rid, mid+1, r);
}

int main()
{   

}