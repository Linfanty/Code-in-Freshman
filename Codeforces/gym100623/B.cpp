#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int N = 2e5 + 10;
using namespace std;

ll w[N];
ll h, n, x, m, flag, a ;

struct node{
    int l, r, nmax;
}tree[N*4];

void built(int id, int l, int r){
    cout << id ;
    tree[id].r = r, tree[id].l = l;
    if( l == r){
        tree[id].nmax = m;
        return;
    }
    built(id*2, l, (l+r)/2 );
    built(id*2 + 1, (l+r)/2 + 1, r );
    tree[id].nmax = max( tree[id*2].nmax, tree[id*2+1].nmax );
}

void query(int id, int l, int r){
    if( flag )  return;
    if( tree[id].nmax < x){
        cout << -1 << endl;
        return;
    }
    if( tree[id].l == tree[id].r){
        cout << tree[id].l << endl;
        flag = 1;
        tree[id].nmax -= x;
        return;
    }
    if( tree[id*2 ].nmax >= x) query(id*2, l, (l+r)/2);
        else query(id*2+1, (l+r)/2 +1, r);
      tree[id].nmax=max(tree[id*2].nmax,tree[id*2+1].nmax);
}



int main()
{
    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);
    cin >> n >> m >> a;
    n = min(200000ll, n);
    built(1, 1, n);
    rep(i, 1, a){
        flag = 0;
        cin >> x;
        query(1, 1, n);
    }
    return 0;
}
