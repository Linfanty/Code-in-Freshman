#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define max3(a,b,c) max(a,max(b, c))
#define max4(a,b,c,d) max(max(a,b), max(c, d))
const int MAXN = 1e6+7;
int n;
char s[MAXN];
//这是打表的代码
bool vis[MAXN];
int ans[MAXN];

void bfs()
{
    queue<int>q;
    q.push(1);
    int cnt = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[cnt++] = u;

        if(cnt >= 1000)break;

        if(u >= 6)
            if(!vis[u-6])
        {
            vis[u-6] = 1;
            q.push(u-6);
        }

        if(u*2 <= 1000000 && !vis[u*2] )
        {
            vis[u*2] = 1;
            q.push(u*2);
        }
    }

    printf("%d\n",cnt);
    sort(ans,ans+cnt);
    for(int i = 0; i < cnt; ++i)
    {
        printf("%d ",ans[i]);
        if(i%10 == 1)puts("");
    }
}
//

int main()
{
    //bfs();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int l = strlen(s);
        int sum = 0;
        int flag = 1;
        if(s[0] != 'M')flag = 0;
        if(flag)
            for(int i = 1; i < l; ++i)
            {
                if(s[i] == 'M')
                {
                    flag = 0;
                    break;
                }
                else if(s[i] == 'I')sum++;
                else sum += 3;
            }

        if(!flag)  puts("No");
        else
        {
            if(sum == 1)puts("Yes");
            else
            {
                if(sum & 1 || sum%6==0 )
                    puts("No");
                else puts("Yes");
            }
        }
    }
    return 0;
}
