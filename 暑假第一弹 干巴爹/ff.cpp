#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

int n,m;

bool flag;

void dfs(int pos,int val)

{

  int temp = pos - val;

  if( temp == m ){flag=1;return;}



  if( temp >= 1 && temp <= n )dfs(temp,val+2);



  if( flag )return ;

  temp = pos + val;

  if( temp == m ){flag=1;return;}

  if( temp >= 1 && temp <= n )dfs( temp,val+2);

  if( flag )return ;

}

int main()

{

    while( cin>>n>>m && n)

    {

       if( n >= 50 ){printf("Let me try!\n");continue;}

       flag=0;

       dfs(0,1);

       if( flag )printf("Let me try!\n");

       else printf("Don't make fun of me!\n");

    }

}
