//dijkstra+优先队列    #include<cstdio>
    #include<cstring>
    #include<queue>
    using namespace std;
    const int MAXN=200+10;
    const int MAXM=40000+10;
    const int INF=1000000;
    int n,m,dis[MAXN],head[MAXN],len;
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
    struct point
    {
        int val,id;
        point(int id,int val):id(id),val(val){}
        bool operator <(const point &x)const{
            return val>x.val;
        }
    };
    void dijkstra(int s)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            dis[i]=INF;

        priority_queue<point> q;
        q.push(point(s,0));
        dis[s]=0;
        while(!q.empty())
        {
            int cur=q.top().id;
            q.pop();
            if(vis[cur]) continue;
            vis[cur]=true;
            for(int i=head[cur];i!=-1;i=e[i].next)
            {
                int id=e[i].to;
                if(!vis[id] && dis[cur]+e[i].val < dis[id])
                {
                    dis[id]=dis[cur]+e[i].val;
                    q.push(point(id,dis[id]));
                }
            }
        }
    }
    int main()
    {
        while(~scanf("%d%d",&n,&m))
        {
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
            dijkstra(s);
            if(dis[t]==INF)
                printf("-1\n");
            else
                printf("%d\n",dis[t]);
        }
        return 0;

    }
