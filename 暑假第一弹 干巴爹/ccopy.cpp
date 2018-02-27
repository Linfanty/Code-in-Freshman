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


int bfs(int x)  // 先算时间 tA[i] <= tB[] max(2tA[i])
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

int dfs(int x) //再求最后结束节点
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
