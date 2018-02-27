//最小生成树 MST
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
int n, m;       //n点， m边
int u[MAX], v[MAX], w[MAX];     //边的两个端点，权重
int p[MAX], r[MAX];             //父节点， 边序号
int cmp(const int a, const int b) { return w[a] < w[b]; }        //间接排序比较函数
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}    //并查集的find

int Kruskal()
{
    int ans = 0;
    for(int i = 0; i < n; i++) p[i] = i; //初始化并查集
    for(int i = 0; i < m; i++) r[i] = i; //初始化边序号
    sort(r, r+m, cmp);                      //给边排序

    for(int i = 0; i < m; i++)
    {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);     //找到当前边两个端点所在的集合
        if(x != y) { ans += w[e]; p[y] = x;}    //如果不在同一集合，合并
    }
    return ans;
}
