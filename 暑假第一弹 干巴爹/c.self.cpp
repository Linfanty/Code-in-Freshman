#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 200005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int n, x;
int a, b, ans;
int atime[maxn], btime[maxn];
bool vit[maxn];
vector<int> edge[maxn];

void bfsa()
{
    mem(vit);
    atime[1] = 0;
    queue<int> q;
    q.push(1);
    vit[1] = true;

    while( !q.empty() )
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < edge[now].size(); i++)
        {
            if( vit[ edge[now][i] ] )
                continue;

            vit[ edge[now][i] ] = true;        // cout << edge[now][i]  <<' ' <<  atime[now] <<endl;
            atime[ edge[now][i] ] = atime[now] + 1;
            q.push( edge[now][i]);
        }
    }
}

void bfsb()
{
    mem(vit);
    btime[x] = 0;
    queue<int> q;
    q.push(x);
    vit[x] = true;

    while( !q.empty() )
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < edge[now].size(); i++)
        {
            if( vit[ edge[now][i] ] )
                continue;

            vit[ edge[now][i] ] = true;
            btime[ edge[now][i] ] = btime[now] + 1;
            q.push( edge[now][i]);
        }
    }
}
/*
5 2
1 2
2 3
3 4
2 5

*/
/*
void dfs()
{
    mem(vit);
    vit[1] = true;
    int ans = 0;
    for(int i = 0; i < edge[x].size(); i++)
    {
        if( vit[ edge[now][i] ] )
                continue;

    }

}
*/
void print()
{
    rep(i, 1, n)
        cout << atime[i] << ' ';
    cout << endl;
    rep(i, 1, n)
        cout << btime[i] << ' ';
    cout << endl;
}
/*vector  二维数组
edge[1] 2
edge[2] 1 3 5
edge[3] 2 4
edge[4] 3
edge[5] 2
**/
void dfsinit()
{
    mem(vit);
    vit[1] = true;
    ans = 0;
}

void dfssum(int y)
{

    for(int i = 0; i < edge[y].size(); i++)
    {
        if( vit[ edge[y][i] ]) // edge[1][0] = 2 continue;
            continue;

        vit[ edge[y][i] ] = 1;

        if(  btime[ edge[y][i] ] < atime[ edge[y][i] ] )
        {
            ans = max( ans, 2 * atime[ edge[y][i] ]);
            ans = max( ans, 2 * btime[ edge[y][i] ] );
        }
        dfssum( edge[y][i] );
    }
}

/*
void dfssum()
{

    for(int i = 0; i < edge[y].size(); i++)
    {
        if( vit[ edge[x][i] ]) // edge[2][0] = 1 continue;
            continue;

        atime[ edge[x][i] ] = a[ x ] + 1;
        //atime[  edge[2][1] ] = atime[3] = a[x] = a[2] + 1
        //atime[  edge[2][2] ] = atime[5] = a[x] = a[2] + 1

        vit[ edge[x][i] ] = 1;

        if(  btime[ edge[now][i] ] < atime[ edge[now][i] ] )
        {
            //cout << btime[ edge[now][i] ]  << ' ' <<   atime[ edge[now][i] ] << endl;
            ans = max( ans, 2 * atime[ edge[now][i] ]);
            ans = max( ans, 2 * btime[ edge[now][i] ] );
        }
        dfssum( edge[x][i] );
    }
}
*/
void bfssum()
{
    mem(vit);
    vit[1] = true;
    ans = 0;
    queue<int> q;
    q.push(1);

    while( !q.empty() )
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < edge[now].size(); i++)
        {
            if( vit[ edge[now][i] ] )
                continue;

            if(  btime[ edge[now][i] ] < atime[ edge[now][i] ] )
            {
                //cout << btime[ edge[now][i] ]  << ' ' <<   atime[ edge[now][i] ] << endl;
                ans = max( ans, 2 * atime[ edge[now][i] ]);
                ans = max( ans, 2 * btime[ edge[now][i] ] );
            }
            vit[ edge[now][i] ] = true;
            q.push( edge[now][i]);
        }
    }
    cout <<  ans <<endl;
}

int main()
{
    cin >> n >> x;
    rep(i, 1, n-1)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    /*
    rep(i, 1, n)
    {//    cout << egde[i] << endl;
        copy(edge[i].begin(), edge[i].end(), ostream_iterator<int>(cout," "));
        cout << endl;
    }
    */
    bfsa();//求出1 到 i: atime
    bfsb();//求出x 到 i: btime
    //print();
    //bfssum();

    dfsinit();
    dfssum(1);
    cout << ans << endl;

}
/*
for(vector<StrId>::iterator j=t.begin();j!=t.end();j++)
cout<< (*j).str<< " " << (*j).inode<<endl;
*/
