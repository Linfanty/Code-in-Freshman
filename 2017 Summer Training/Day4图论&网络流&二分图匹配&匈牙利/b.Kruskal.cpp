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

#define MAX 550

struct node {
    int st, ed;//边的两个端点，权重
    double cost;
}edge[1001000];// 边序号

int k, x[110010], y[110010], pre[110010];//父节点
int n, m;       //n点， m边
int cmp(const node a, const node b) { return a.cost < b.cost ; }        //间接排序比较函数
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //并查集的find

void kruskal()  {

    int v = 0;

    rep(i, 0, k) {
        int fx = find(edge[i].st), fy = find(edge[i].ed);//找到当前边两个端点所在的集合
        if( fx!= fy) { pre[fx] = fy; v++;}//如果不在同一集合，合并

        if( v == n - m) {
            printf("%.2f\n", edge[i].cost) ;
            break;
        }
    }
}

double sqrtt(int x, int y, int xx, int yy)  {
    return sqrt( (x-xx) * ( x- xx) + (y-yy) * (y-yy) );
}

int main() {
    int t;  scanf("%d", &t);
    while( t-- )   {
        rep(i, 0, 1100)
            pre[i] = i;//初始化并查集

        scanf("%d %d", &m, &n);
        repp(i, 1, n)
            scanf("%d %d", &x[i], &y[i]);

        k = 0;

        repp(i, 1, n)
            repp(j, i+1, n)
                edge[k].st = i, edge[k].ed = j,
                edge[k].cost = sqrtt(x[i],y[i],x[j],y[j]), k++;//初始化边序号
        sort(edge, edge+k, cmp); //给边排序

        kruskal();
    }
}
