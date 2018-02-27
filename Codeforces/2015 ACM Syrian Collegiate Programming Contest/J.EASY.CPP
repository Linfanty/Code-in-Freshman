#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 111111
map<string,int>M;
int T,n,k,vis[maxn];
vector<int>g[maxn];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v])continue;
        dfs(v);
    }
}
char c[22],s[maxn][22];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        M.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]);
            M[s[i]]=i;
            int num;
            scanf("%d",&num);
            while(num--)
            {
                scanf("%s",c);
                int pos=M[c];
                if(pos!=i)g[i].push_back(pos);
            }
        }
        memset(vis,0,sizeof(vis));
        while(k--)
        {
            scanf("%s",c);
            if(!vis[M[c]])dfs(M[c]);
        }
        for(int i=1;i<=n;i++)
            if(vis[i])
                printf("%s\n",s[i]);
    }
    return 0;
}