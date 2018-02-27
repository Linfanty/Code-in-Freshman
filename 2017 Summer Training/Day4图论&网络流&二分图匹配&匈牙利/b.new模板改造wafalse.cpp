//最小生成树 MST
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdpio(0),cin.tie(0)
using namespace std;

#define MAX 1001000

int k, x[110010], y[110010];
int n, m;       //n点， m边
int st[MAX], ed[MAX], cost[MAX];     //边的两个端点，权重
int pre[MAX], edge[MAX];             //父节点， 边序号

int cmp(const int a, const int b) { return  cost[a] < cost[b]; }        //间接排序比较函数
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //并查集的find

int Kruskal()
{
    int ans = 0;
    for(int i = 0; i <= n; i++) pre[i] = i; // 初始化并查集
    for(int i = 0; i <= m; i++) edge[i] = i; // 初始化边序号
    sort(edge, edge+k, cmp);                // 给边排序

    int v = 0;
    for(int i = 0; i < k; i++)
    {
        int e = edge[i];
        int x = find( st[e] ), y = find( ed[e] );     //找到当前边两个端点所在的集合
        if(x != y) {  pre[y] = x; v++; }    //如果不在同一集合，合并
        if( v == n - m) {
            printf("%.2f\n", cost[e]) ;
            break;
        }
    }
    return ans;
}

double sqrtt(int x, int y, int xx, int yy)  {
    return sqrt( (x-xx) * ( x- xx) + (y-yy) * (y-yy) );
}

int main() {
    int t;  scanf("%d", &t);
    while( t-- )   {

        scanf("%d %d", &m, &n);
        repp(i, 1, n)
            scanf("%d %d", &x[i], &y[i]);

        k = 0;
        repp(i, 1, n)
            repp(j, i+1, n)
                st[k] = i, ed[k] = j,
                cost[k] = sqrtt(x[i],y[i],x[j],y[j]), k++;

        Kruskal();
    }
}

