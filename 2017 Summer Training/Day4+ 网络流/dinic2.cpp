/* filename :network_flow_Dinic.cpp
 * author :AntiheroChen
 * Description :It's a Dinic solution for the network flow prblem.
 * Complexity :O(V^2*E) always below this.
 * Version :1.00
 * History :
 * 1)2012/02/29 first release.
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn=1000+5, bign=1000000000;
int M, n, m, source, sink, c[maxn][maxn], cnt[maxn];


/* The arc of the flow network.*/
struct Pool
{
    int next, t, c;
} edge[maxn*maxn<<1];


/* The point of the flow network.*/
struct Point
{
    int son, cur, pre, lim, d;
} a[maxn];


/* Prepare for the algorithm.*/
void initialize()
{
    M=1;
    memset(c, 0, sizeof (c));
    memset(a, 0, sizeof (a));
    memset(cnt, 0, sizeof (cnt));
}


/* Add an arc to the flow network.*/
void add(int x, int y, int z)
{
    edge[++M].t=y;
    edge[M].c=z;
    edge[M].next=a[x].son;//�൱��pool��head����
    a[x].son=M;
}


/* Read the data and make it the right format.*/
void input()
{
    scanf("%*s%*d%d%d%d%d", &n, &m, &source, &sink);
    initialize();
    int x, y, z;
    while (m--)
        scanf("%d%d%d", &x, &y, &z), c[x][y]+=z;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (c[i][j])add(i, j, c[i][j]),
                add(j, i, c[j][i]),
                    c[j][i]=0;
}


int que[maxn], fi, la;
bool vis[maxn];


/* Build the hierarchical graph for the algorithm*/
bool build()
{
    memset(vis, 0, sizeof (vis));
    que[fi=la=0]=sink;//reverse
    a[sink].d=0, a[sink].cur=a[sink].son, vis[sink]=true;
    while (fi<=la)
    {
        int v=que[fi++];
        for (int now=a[v].son, u; u=edge[now].t, now; now=edge[now].next)
            if (edge[now^1].c&&!vis[u])//BFS���ֲ�,�����EK��ͬ
            {//����BFS�Ļ�,��Ȼ���õĻ��ǶԲ��,�������
                a[u].d=a[v].d+1;//Խ��ǰ��Ž���
                a[u].cur=a[u].son;//curָ��ͷ
                vis[u]=true;//�ѱ���
                que[++la]=u;//���
            }
        if (vis[source])return true;//���ͼ��ǰ�Ѿ���չ��ԭ��
    }
    return false;
}


/*Use the Dinic algorithm to calculate the max flow.*/
int MaxFlow()
{
    int u, v, now, ret=0;
    while (build())
    {
        a[u=source].lim=bign;
        while (true)
        {
            for (now=a[u].cur; v=edge[now].t, now; now=edge[now].next)//cur�Ż�
                if (edge[now].c&&a[u].d==a[v].d+1)break;//�ҵ���һ���ӽڵ����ڲ��ͼ
            if (now)
            {
                a[u].cur=edge[now].next;//��һ�δ���һ���ߵ���һ���߿�ʼdfs
                a[v].pre=now;//ָ��v�ıߵ�ָ��
                a[v].lim=min(a[u].lim, edge[now].c);///���µ��˴�Ϊֹ��������
                if ((u=v)==sink)//����Ѿ��ҵ���һ������·(�ߵ��˾�ͷ)
                ///ע������ط����ж����, ��u����, �����ж�Ϊ���ʱ��ص����������һ��!
                {//��������
                    do
                    {
                        edge[a[u].pre].c-=a[sink].lim;
                        edge[a[u].pre^1].c+=a[sink].lim;//�������Edmonds-Karp��һ����,����
                        u=edge[a[u].pre^1].t;//��ǰ��~!
                    } while (u!=source);
                    ret+=a[sink].lim;//�������֮���ۼ����ҵ�����
                }//����(û�ߵ���ͷ)��������DFS
            }
            else//û���ӽڵ����ڲ��ͼ
            {
                if (u==source)break;//�Ѿ��˵���Դ,�����ҵ������,�㷨����
                a[u].cur=now;//=0,�˽ڵ㱻����,�Ӵ���Ȼ
                u=edge[a[u].pre^1].t;//���ݷ�����ҵ�ǰ��~!
            }
        }
    }
    return ret;
}


int main()
{
    int total;
    scanf("%d", &total);
    while (total--)
    {
        input();
        printf("%d\n", MaxFlow());
    }
    return 0;
}

