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

int t, n, k, vis[maxn]; // 访问标记
map<string, int> mp;//string 转化 int
vector<int> g[maxn];//邻接表 存图

string c, s[maxn];

void dfs(int u) // dfs 图的遍历代码
{
    vis[u] =  1; // 标记已访问

    for(int i = 0;i < g[u].size(); i++)  // i 从 0 到 g[u].size()
    {
        int v = g[u][i]; // v = g[u][i]  标记 深搜的邻接结点 已访问
        if( vis[v])  // 若已访问 则继续遍历下一个节点结点
            continue;
        dfs( v ); // 深搜
    }
}

void init()
{
    mp.clear();// mp清零
    for(int i = 1; i <= n; i++)
        g[i].clear(); // vector g图 清零

    memset(vis, 0, sizeof(vis) );// vis 标记访问数组清零
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
            mp[ s[i] ] = i;  // string 与 int 编号对应

            int num;
            cin >> num;

            while(num--)
            {
                cin >> c;
                int& pos = mp[c]; // pos 为int编号 string的对应
                if( pos!= i )  // 若不存在 则 把 pos加入图中
                    g[i].push_back(pos);
                //cout << pos << ' ' << i << endl;
            }
        }


        while( k-- )
        {
            cin >> c;
            if( !vis[ mp[c] ] )//未访问， 则dfs（mp[c]）标号
                dfs( mp[c] );
        }

        for(int i = 1; i<=n; i++)
            if( vis[i] ) // 已访问， 则按照顺序输出即可
                cout << s[i] << endl;

    }



}
