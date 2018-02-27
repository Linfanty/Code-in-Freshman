//��С������ MST
//����������ߺ���̱�ֻ����С
/// ��С��������Ȩ��Ψһ��
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
    int st, ed;//�ߵ������˵㣬Ȩ��
    int cost;
}edge[1001000];// �����

int k, x[110010], y[110010], pre[110010];//���ڵ�
int n, m;       //n�㣬 m��
int cmp(const node a, const node b) { return a.cost < b.cost ; }        //�������ȽϺ���
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //���鼯��find

void init()   {
    repp(i, 0, n)   pre[i] = i;
}

void kruskal() {
    int ii = 0, min1 = inf , flag = 0;
    rep(i, 0, m-n+2)   { /// ö����С�� ������� �������Ž�
        init();

        int v = 0;
        rep(j, ii, m)    {
            int x = find(edge[j].st), y = find(edge[j].ed);
            /// cout << x << ' ' << y << endl;
            if( x != y) { pre[x] = y; v++;}
            if( v == n - 1) {
                flag = 1;;
                ii++;
                if( edge[j].cost - edge[i].cost < min1 ) //����������ߺ���̱�ֻ����С
                    min1 = edge[j].cost - edge[i].cost;
                if(min1 == 0) break; //�����0����ô�Ѿ�����С����
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

