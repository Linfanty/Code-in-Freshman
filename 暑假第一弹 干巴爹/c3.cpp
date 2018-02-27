#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N = 200000 + 100;
int n,x;

struct node
{
    int to,next;
}edge[N<<2];

int head[N<<2], f[N], mxdp[N], dep[N], cnt=0;

void add(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u,int pre,int deep)
{
    f[u]=pre;
    mxdp[u]=dep[u]=deep;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs(v,u,deep+1);
          mxdp[u]=max(mxdp[u],mxdp[v]);
    }
   // cout<<u<<":"<<mxdp[u]<<endl;
}
int u,v;
int main()
{
    memset(head,-1,sizeof(head));
    std::ios::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1,0);
    int ans=mxdp[x]*2;
    for(int i=0,k=x;i<dep[x];i++,k=f[k])
    {
        if(i<dep[k])
        {
            ans=max(ans,mxdp[k]*2);
        }
        else
        break;
    }
    cout<<ans<<endl;
}
