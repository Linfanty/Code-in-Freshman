#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 200005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

struct Node{
    int e;
    vector<int> v;
} sq[maxn];

int vis[maxn];
int main()
{
    int n, m;
    int a, b;
    cin >> n >> m;
    rep(i, 1, m)
    {
         cin >> a >> b;
         sq[a].v.push_back(b);
         sq[b].v.push_back(a);
         sq[a].e++, sq[b].e++;
    }
    int mi = 1e9, minode;
    for(int i = 1; i <= n; i++)
    {
        if(mi > sq[i].e)
        {
            mi =  sq[i].e;
            minode = i;
        }
    }
    memset(vis, 0, sizeof vis);
    vis[minode] = 1;

    for(int i = 0; i < sq[minode].v.size(); i++)
        vis[sq[minode].v[i]] = 1;

    if(vis[1])
        printf("%d", 0);
    else
        printf("%d", 1);
    for(int i = 2; i <= n; i++)
        if(vis[i])
        printf(" %d", 0);
    else
        printf(" %d", 1);
}
