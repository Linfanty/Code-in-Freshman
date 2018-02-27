# include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
struct node
{
    int x, y, id;
    bool operator <(const node&a)const
    {
        return x > a.x;
    }
}u[N], v[N];
set<pair<int,int> >s;
int ans[N];
int main()
{
    int n, m, x, y;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        scanf("%d%d",&u[i].x,&u[i].y),u[i].id = i;
    scanf("%d",&m);
    for(int i=0; i<m; ++i)
        scanf("%d%d",&v[i].x,&v[i].y),v[i].id = i;
    sort(v, v+m);
    sort(u, u+n);
    int j=0;
    for(int i=0; i<n; ++i)
    {
        for(;v[j].x >= u[i].x; ++j)
            s.insert(make_pair(v[j].y, v[j].id));
        auto p = s.lower_bound(make_pair(u[i].y,0));
        if(p == s.end())
            return 0*puts("-1");
        ans[u[i].id] = p->second;
        s.erase(p);
    }
    for(int i=0; i<n; ++i)
        printf("%d%c",ans[i]+1,i==n-1?'\n':' ');
    return 0;
}

