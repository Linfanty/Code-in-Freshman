//��С������ MST
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
int n, m;       //n�㣬 m��
int u[MAX], v[MAX], w[MAX];     //�ߵ������˵㣬Ȩ��
int p[MAX], r[MAX];             //���ڵ㣬 �����
int cmp(const int a, const int b) { return w[a] < w[b]; }        //�������ȽϺ���
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}    //���鼯��find

int Kruskal()
{
    int ans = 0;
    for(int i = 0; i < n; i++) p[i] = i; //��ʼ�����鼯
    for(int i = 0; i < m; i++) r[i] = i; //��ʼ�������
    sort(r, r+m, cmp);                      //��������

    for(int i = 0; i < m; i++)
    {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);     //�ҵ���ǰ�������˵����ڵļ���
        if(x != y) { ans += w[e]; p[y] = x;}    //�������ͬһ���ϣ��ϲ�
    }
    return ans;
}
