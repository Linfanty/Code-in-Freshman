//��С������ MST
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
    int st, ed;//�ߵ������˵㣬Ȩ��
    double cost;
}edge[1001000];// �����

int k, x[110010], y[110010], pre[110010];//���ڵ�
int n, m;       //n�㣬 m��
int cmp(const node a, const node b) { return a.cost < b.cost ; }        //�������ȽϺ���
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //���鼯��find

void kruskal()  {

    int v = 0;

    rep(i, 0, k) {
        int fx = find(edge[i].st), fy = find(edge[i].ed);//�ҵ���ǰ�������˵����ڵļ���
        if( fx!= fy) { pre[fx] = fy; v++;}//�������ͬһ���ϣ��ϲ�

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
            pre[i] = i;//��ʼ�����鼯

        scanf("%d %d", &m, &n);
        repp(i, 1, n)
            scanf("%d %d", &x[i], &y[i]);

        k = 0;

        repp(i, 1, n)
            repp(j, i+1, n)
                edge[k].st = i, edge[k].ed = j,
                edge[k].cost = sqrtt(x[i],y[i],x[j],y[j]), k++;//��ʼ�������
        sort(edge, edge+k, cmp); //��������

        kruskal();
    }
}
