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
#define maxn 10000005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int n = 0, m;

int dir[4][2]={1,0,0,1,-1,0,0,-1};
string s[55];
int s2 = 0, s1 = 0, s3 = 0, s4 = 0;
void dfs(int x,int y)
{
	s1++;
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		
        if(nx>=0 && nx<n && ny>=0 && ny<m && (s[nx][ny]=='*' ))
        {
        	s2++;
            s[nx][ny]='#'; 
            dfs(nx,ny);
        }
        s3 ++;
    }
    s4 ++;
}

int main()
{
	fin;
	while( getline ( cin, s[n]) )
		++n;
		
	m = s[0].size();
	     
    int ans=0;
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='*')
            {
                s[i][j]='#';
            	dfs(i,j);     //每一遍dfs后，ans就++。
                ans++;
            }
        }
    }
    
    printf("%d\n",ans);
	printf("%d %d %d %d\n",s1,s2,s3,s4);
    return 0;
	
}




