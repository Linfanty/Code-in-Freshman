#include <bits/stdc++.h>
#define INF 0x7fffffff
#define maxn 1001000
#define eps 1e-6
#define pi acos(-1.0)
#define e 2.718281828459
#define mod (int)1e9 + 7;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;

int t, n, k, vis[maxn]; // ���ʱ��
map<string, int> mp;//string ת�� int
vector<int> g[maxn];//�ڽӱ� ��ͼ

string c, s[maxn];

void dfs(int u) // dfs ͼ�ı�������
{
    vis[u] =  1; // ����ѷ���

    for(int i = 0;i < g[u].size(); i++)  // i �� 0 �� g[u].size()
    {
        int v = g[u][i]; // v = g[u][i]  ��� ���ѵ��ڽӽ�� �ѷ���
        if( vis[v])  // ���ѷ��� �����������һ���ڵ���
            continue;
        dfs( v ); // ����
    }
}

void init()
{
    mp.clear();// mp����
    for(int i = 1; i <= n; i++)
        g[i].clear(); // vector gͼ ����

    memset(vis, 0, sizeof(vis) );// vis ��Ƿ�����������
}

int main()
{IO;
    cin >> t;
    while( t-- )
    {
        cin >> n >> k;
        init();


        for(int i = 1; i <= n; i++)
        {
            cin >> s[i];
            mp[ s[i] ] = i;  // string �� int ��Ŷ�Ӧ

            int num;
            cin >> num;

            while(num--)
            {
                cin >> c;
                int& pos = mp[c]; // pos Ϊint��� string�Ķ�Ӧ
                if( pos!= i )  // �������� �� �� pos����ͼ��
                    g[i].push_back(pos);
                //cout << pos << ' ' << i << endl;
            }
        }


        while( k-- )
        {
            cin >> c;
            if( !vis[ mp[c] ] )//δ���ʣ� ��dfs��mp[c]�����
                dfs( mp[c] );
        }

        for(int i = 1; i<=n; i++)
            if( vis[i] ) // �ѷ��ʣ� ����˳���������
                cout << s[i] << endl;

    }



}