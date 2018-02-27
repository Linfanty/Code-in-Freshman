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
有n个函数，每个函数的调用可能要用到其他一些函数，
现在要用k个函数，问哪些函数是必须的
-------->
n只球队，每只球队可能会和其他队伍进行比赛，
问你最终有哪只球队没有他们的比赛

实际上就是给你n个元素，其中一些元素在一个集合中，
求那些单元素的集合，考虑对球队名称先映射编号，
然后对每个球队进行dfs和标记，
最终没被标记的就是答案
-------->
对于这个关系图,每次需要x函数就从x开始dfs
把所有能够走到的点全部标记，
已经标记的点就不用走了，
最后所有被标记的点就是所需的函数

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
            //名字 = 编号

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
            if( vis[i] ) // 已访问
            //从 i = 0 开始 保持顺序
                cout << name[i] << endl;
        }
    }
}




