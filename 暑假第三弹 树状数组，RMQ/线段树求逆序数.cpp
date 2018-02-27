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
    //pushup(rt) �����ʼ��0 û��Ҫ�ⲽ��
}

void update(int p, int l, int r, int rt) {//p��ʾҪ���в��������ǵڼ���
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
    if (L <= m) ret += query(L , R , lson);  //�ҵ���ײ�
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
    //��Ϊ�ո������a[i],�����Ǵ�(a[i]+1,n-1)��
        }
        ans = sum;//����ansΪ��ʼ˳���ֵ
        for(i = 1;i < n;i++){
            sum = sum + (n - 1 - a[i]) - a[i];//�ص㲽��ע�����

            ans = ans<sum?ans:sum;
        }
        printf("%d\n",ans);
    }
}


