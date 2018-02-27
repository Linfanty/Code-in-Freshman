#include <stdio.h>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int L = 35;
const double inf = 1000000;
map<string,int> mat;
int n,m;
char str[105],s1[105],s2[105];
double trip[35][35],dis[35];

int SPFA(int src)
{
    queue<int> Q;
    int vis[35],i;
    int num[35];
    for(i = 1; i<=n; i++)
        vis[i] = dis[i] = num[i] = 0;
    while(!Q.empty())
        Q.pop();
    dis[src] = 1.0;
    vis[src] = 1;
    Q.push(src);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        vis[now] = 0;
        for(i = 1; i<=n; i++)
        {
            cout <<dis[src] << ' ' <<dis[i]<<endl;
            if(dis[now]*trip[now][i]>dis[i])
            {
                dis[i] = dis[now]*trip[now][i];
                if(dis[src]>1.0)
                    return 1;
                if(!vis[i])
                {
                    vis[i] = 1;
                    Q.push(i);
                }
            }
        }
    }
    return 0;
}

int main()
{
    int i,j,cas = 1;
    double w;
    while(~scanf("%d",&n),n)
    {
        mat.clear();
        for(i = 1; i<=n; i++)
            for(j = 1; j<=n; j++)
                trip[i][j] = (i==j)?1.0:0;
        for(i = 1; i<=n; i++)
        {
            scanf("%s",str);
            mat[str] = i;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%lf%s",s1,&w,s2);
            trip[mat[s1]][mat[s2]] = w;
        }
        int flag = 0;
        for(i = 1; i<=n; i++)
        {
            if(SPFA(i))
            {
                flag = 1;
                break;
            }
        }
        printf("Case %d: %s\n",cas++,flag?"Yes":"No");
    }

    return 0;
}
