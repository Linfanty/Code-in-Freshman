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

#define MAX 1001000

int k, x[110010], y[110010];
int n, m;       //n�㣬 m��
int st[MAX], ed[MAX], cost[MAX];     //�ߵ������˵㣬Ȩ��
int pre[MAX], edge[MAX];             //���ڵ㣬 �����

int cmp(const int a, const int b) { return  cost[a] < cost[b]; }        //�������ȽϺ���
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]);}    //���鼯��find

int Kruskal()
{
    int ans = 0;
    for(int i = 0; i <= n; i++) pre[i] = i; // ��ʼ�����鼯
    for(int i = 0; i <= m; i++) edge[i] = i; // ��ʼ�������
    sort(edge, edge+k, cmp);                // ��������

    int v = 0;
    for(int i = 0; i < k; i++)
    {
        int e = edge[i];
        int x = find( st[e] ), y = find( ed[e] );     //�ҵ���ǰ�������˵����ڵļ���
        if(x != y) {  pre[y] = x; v++; }    //�������ͬһ���ϣ��ϲ�
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

