//SPFA+аз╫с╠М
//http://blog.csdn.net/murmured/article/details/18568657
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=10005;
const int MAXM=40000+10;
const int INF=1000000;
int n = MAXN,m,dis[MAXN],head[MAXN],len;
bool vis[MAXN];

struct edge
{
    int to,val,next;
}e[MAXM];

void add(int from,int to,int  val)
{
    e[len].to=to;
    e[len].val=val;
    e[len].next=head[from];
    head[from]=len++;
}
void spfa(int s)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        dis[i]=INF;    

    queue<int> q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        vis[cur]=false;
        for(int i=head[cur];i!=-1;i=e[i].next)
        {
            int id=e[i].to;
            if(dis[id] > dis[cur]+e[i].val)
            {
                dis[id] = dis[cur] + e[i].val;
                if(!vis[id])
                {
                    vis[id]=true;
                    q.push(id);
                }
            }
        }
    }
}
int main()
{
	int t;
	scanf("%d", &t);
    while( t-- )
	{
		scanf("%d",&m);
        len=0;
        memset(head,-1,sizeof(head));

        for(int i=0;i<m;i++)
        {
            int from,to,val;
            scanf("%d%d%d",&from,&to,&val);
            add(from,to,val);
            add(to,from,val);
        }


        int s,t;
        scanf("%d%d",&s,&t);
        
        spfa(s);
        
        printf("%d\n",dis[t] * 2);
        
    }
    return 0;

}
