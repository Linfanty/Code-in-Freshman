#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define lson l, (l + r >> 1), rt << 1
#define rson (l + r >> 1) + 1, r, rt << 1 | 1
using namespace std;
const int N = 205, INF = 0x3f3f3f3f;
int n, w = 0, cnt[N << 2]; //根节点维护的是[l, r+1]的区间
double sum[N << 2], all[N];

struct Seg {//  存储线段信息
    double l, r, h;
    int d;
    Seg() {}
    Seg(double l, double r, double h, int d): l(l), r(r), h(h), d(d) {}
    bool operator< (const Seg& rhs) const {return h < rhs.h;}
} a[N];

void pushup(int l, int r, int rt)
{
    if(cnt[rt]) sum[rt] = all[r + 1] - all[l];
    else if(l == r) sum[rt] = 0; //leaves have no sons
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int L, int R, int v, int l, int r, int rt)
{
    if(L > r || R < l) return;
    if(L <= l && r <= R) {
        cnt[rt] += v;
        pushup(l, r, rt);
        return;
    }
    update(L, R, v, lson);
    update(L, R, v, rson);
    pushup(l, r, rt);
}

int main() {
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

            a[i] = Seg(x1, x2, y1, 1);
            a[i + n] = Seg(x1, x2, y2, -1);

            all[i] = x1;
            all[i + n] = x2;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n);
        sort(all + 1, all + 1 + n);
        int m = unique(all + 1, all + 1 + n) - all - 1;

        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
        double ans = 0;

        for(int i = 1; i < n; ++i) {
            int l = lower_bound(all + 1, all + 1 + m, a[i].l) - all;
            int r = lower_bound(all + 1, all + 1 + m, a[i].r) - all;

            if(l < r) update(l, r - 1, a[i].d, 1, m, 1);
//cout <<l << ' '<< r <<' ' << sum[1]<< endl;
            ans += sum0[1] * (a[i + 1].h - a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++w, ans);
    }
    return 0;
}
