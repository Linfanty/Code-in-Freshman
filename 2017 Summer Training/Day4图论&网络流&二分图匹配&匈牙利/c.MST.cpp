//最小生成树 MST
//生成树的最长边和最短边只差最小
/// 最小生成树的权是唯一的
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

struct node {
    int st, ed;//边的两个端点，权重
    int cost;
}edge[1001000];// 边序号

int k, x[110010], y[110010], pre[110010];//父节点
int n, m;       //n点， m边
int cmp(const node a, const node b) { return a.cost < b.cost ; }        //间接排序比较函数
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //并查集的find

void init()   {
    repp(i, 0, n)   pre[i] = i;
}

void kruskal() {
    int ii = 0, min1 = inf , flag = 0;
    rep(i, 0, m-n+2)   { /// 枚举最小边 求解最大边 更新最优解
        init();

        int v = 0;
        rep(j, ii, m)    {
            int x = find(edge[j].st), y = find(edge[j].ed);
            /// cout << x << ' ' << y << endl;
            if( x != y) { pre[x] = y; v++;}
            if( v == n - 1) {
                flag = 1;;
                ii++;
                if( edge[j].cost - edge[i].cost < min1 ) //生成树的最长边和最短边只差最小
                    min1 = edge[j].cost - edge[i].cost;
                if(min1 == 0) break; //如果是0，那么已经是最小的了
                break;
            }
        }
    }
    if( flag )
        printf("%d\n", min1);
    else  printf("-1\n");
}


int main() {
    while(  scanf("%d %d", &n, &m)!=EOF && n)   {
        rep(i, 0, m)
             scanf("%d %d %d", &edge[i].st,
                   &edge[i].ed, &edge[i].cost);
        sort(edge, edge+m, cmp);
        kruskal();
    }
}

