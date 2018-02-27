#include <bits/stdc++.h>
#define INF 0x7fffffff
#define maxn 1001000
#define eps 1e-6
#define pi acos(-1.0)
#define e 2.718281828459
#define mod (int)1e9 + 7;
using namespace std;
typedef long long ll;
/*
��n��������ÿ�������ĵ��ÿ���Ҫ�õ�����һЩ������
����Ҫ��k������������Щ�����Ǳ����
-------->
nֻ��ӣ�ÿֻ��ӿ��ܻ������������б�����
������������ֻ���û�����ǵı���

ʵ���Ͼ��Ǹ���n��Ԫ�أ�����һЩԪ����һ�������У�
����Щ��Ԫ�صļ��ϣ����Ƕ����������ӳ���ţ�
Ȼ���ÿ����ӽ���dfs�ͱ�ǣ�
����û����ǵľ��Ǵ�
-------->
���������ϵͼ,ÿ����Ҫx�����ʹ�x��ʼdfs
�������ܹ��ߵ��ĵ�ȫ����ǣ�
�Ѿ���ǵĵ�Ͳ������ˣ�
������б���ǵĵ��������ĺ���

*/
int head[maxn], next[maxn], to[maxn], vis[maxn], cnt;
map<string, int> mp;
string name[maxn], teamname;

void addedge(int u, int v)
{
    next[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

void dfs(int u)
{
    if( vis[u] )
        return;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = next[i])
    {
        int v = to[i];
        if( !vis[v] )
            dfs(v);
    }
}

int main()
{
    int t, n, k;
    cin >> t;
    while( t-- )
    {
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));

        mp.clear();
        cnt = 0;
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> name[i] >> num;
            mp[ name[i] ] = i;
            //���� = ���

            for(int j = 0; j < num; j++)
            {
                cin >> teamname;
                addedge(i, mp[teamname] );
            }
        }

        for(int i = 0; i < k; i++)
        {
            cin >> teamname;
            dfs( mp[teamname] );
        }

        for(int i = 0; i< n; i++)
        {
            if( vis[i] ) // �ѷ���
            //�� i = 0 ��ʼ ����˳��
                cout << name[i] << endl;
        }
    }
}



