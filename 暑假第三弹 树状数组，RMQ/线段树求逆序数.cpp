#include <cstdio>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 5555;
int a[maxn];

struct Tree{
    int value;
}tree[maxn << 2];

void pushup(int rt){
     tree[rt].value = tree[rt<<1].value + tree[rt<<2|1].value;
}

void build(int l, int r,int rt) {
    tree[rt].value = 0;
    if( l == r)
        return;
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    //pushup(rt) 这题初始化0 没必要这步了
}

void update(int p, int l, int r, int rt) {//p表示要进行操作的人是第几个
    if( l == r) {
        tree[rt].value = 1;
        return;
    }
    int m = (l+r) >> 1;
    if( p <= m) update(p, lson);
    else update(p, rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) {
        return tree[rt].value;
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L , R , lson);  //找到最底部
    if (R > m) ret += query(L , R , rson);
    return ret;
}

int main(){
    int sum, n, ans, i;
    while( scanf("%d", &n) != EOF){
        sum = 0;
        build(0, n-1, 1);

        for(i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            update(a[i],0,n-1,1);
            sum += query(a[i]+1,n-1,0,n-1,1);
    //因为刚刚输的是a[i],那我们从(a[i]+1,n-1)找
        }
        ans = sum;//先让ans为初始顺序的值
        for(i = 1;i < n;i++){
            sum = sum + (n - 1 - a[i]) - a[i];//重点步骤注意理解

            ans = ans<sum?ans:sum;
        }
        printf("%d\n",ans);
    }
}


