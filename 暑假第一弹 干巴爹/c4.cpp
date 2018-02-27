//http://blog.csdn.net/jerans/article/details/72887320

#include<bits/stdc++.h>
#define eps 1e-9
#define PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define MEM(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
vector<int>w[200005];
int n,x,book[200005],anss;
int dis1[200005],dis2[200005];
int bfs(int x)
{
    memset(book,0,sizeof(book));
    queue<int>q;
    q.push(x);
    book[x]=1;
    dis2[x]=0;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<w[now].size();i++)
        {
            if(book[w[now][i]])
            continue;
            book[w[now][i]]=1;
            dis2[w[now][i]]=dis2[now]+1;
            q.push(w[now][i]);
        }
    }
    return 0;
}
int dfs(int x)
{
    int ans=0;
    for(int i=0;i<w[x].size();i++)
    {
        if(book[w[x][i]])
        continue;
        dis1[w[x][i]]=dis1[x]+1;
        book[w[x][i]]=1;
        int now=dfs(w[x][i]);
        ans=max(ans,now);
    }
    if(dis2[x]<dis1[x])
    {
//      cout<<" "<<x<<endl;
        anss=max(anss,2*(ans+dis1[x]));
    }
    return ans+1;
}
int main()
{
    cin>>n>>x;
    int a,b;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        w[a].push_back(b);
        w[b].push_back(a);
    }
    anss=0;
    bfs(x);
//  for(int i=1;i<=n;i++)
//  cout<<dis2[i]<<" ";
    memset(book,0,sizeof(book));
    book[1]=1;
    dfs(1);
    cout<<anss<<endl;
 }

 /*
 题意：给你一颗树，1号节点是根节点，两个人做游戏，第一个人在初始在1号节点，第二个人初始在x号节点，没人轮流走，当相遇时游戏结束，其中第一个人希望走的步数越少越好，第二个人希望走的步数越多越好，第二个人先走。

先求一下1号和x号节点到每个节点的最短距离，bfs，dfs都可以实现。。。。因为是树
c
dis1【i】是1号节点到i号节点的最短距离

dis2【i】是x号节点到i号节点的最短距离

max【i】是指从这个点后能向下走的最长距离，可以后序遍历求

对于每个节点，如果dis1【i】>dis2【i】，则ans=max（ans，（dis1【i】+max【i】）*2）

其实这样做法复杂的点，不求max【i】也是可解的，对于每个节点，如果dis1【i】>dis2【i】，则ans=max（ans，dis1【i】*2）即可

可以举一棵树想一想
*/
