#include<bits/stdc++.h>
using namespace std;
vector<int>save[222222];
int maxdeep[222222],deep[222222],fa[222222];
/*分析：由于这是一个树，所以1节点到x节点的路径就只有一条，
那么追击者只能从1开始去追x,那么x有两种方向，一种是向着1跑，
看看有什么岔路口可以走，二是背离x跑，一直跑到树的最深处。
那么，如果我们能够计算以每个加点为根的树的最大深度，那么这个问题就解决了。

x所在树的深度已经求出，那么就看一下向着x方向走的路径有没有岔路口，
使得以这个岔路口为树根的树的深度比之前的大，算出最大值*2就是我们要的答案。
*/
void dfs(int now,int f,int d)
{
    deep[now]=maxdeep[now]=d;
    fa[now]=f;
   // printf("%d %d\n",now,fa[now]);
    int k=save[now].size();
    for(int i=0; i<k; i++)
    {
        int temp=save[now][i];
        if(temp!=f)
        {
            dfs(temp,now,d+1);
            maxdeep[now]=max(maxdeep[now],maxdeep[temp]);
        }
    }

}
int main()
{
    int n,x;

    while(scanf("%d%d",&n,&x)!=EOF)
    {
    memset(fa,0,sizeof(fa));
        for(int i=0; i<n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            save[u].push_back(v);
            save[v].push_back(u);

        }
        dfs(1,1,0);
        int ans=2*maxdeep[x];
        for(int i=0,k=x; i<deep[x]; i++,k=fa[k])
        {
            if(i<deep[k])
            {
                ans=max(2*maxdeep[k],ans);
            }
            else
                break;
        }
        printf("%d\n",ans);
    }

}
