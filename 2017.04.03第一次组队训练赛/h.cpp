#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define maxn 200005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define N 100+5
using namespace std;

int n,m;
char g[N][N];
int dir[4][2]={1,0,0,1,-1,0,0,-1};

void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		
        if(nx>=0 && nx<n && ny>=0 && ny<m && (g[nx][ny]=='L' || g[nx][ny] == 'C' ))
        {
            g[nx][ny]='W'; 
            dfs(nx,ny);
        }
    }
}

int main()
{
	//fin;
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);
        
		//for(int i=0;i<n;i++)
        //    cout<<g[i];
            
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]=='L')
                {
                    g[i][j]='W';
                    dfs(i,j);     //每一遍dfs后，ans就++。
                    ans++;
                }
            }
        }
        printf("%d\n",ans);

    return 0;
}
