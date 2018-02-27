#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 10005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int a[maxn], b[maxn];

struct Node
{
  int x, y;
}node[maxn];

bool cmp(Node a, Node b)
{
    /*
    if( (b.y - b.x) > 0 )
        return (b.y - b.x) > (a.y - a.x);
    else if((b.y - b.x) < 0 )
            return (a.y - a.x) > (b.y - b.x);
    else if( a.x != a.y )
        return a > b ;
    else return b.x > a.x;
    */
    if( b.y != a.y )
        return b.y < a.y;
    else return b.x < a.x;
}

int main()
{
    int n;
    cin >> n;
    rep(i,0,n-1)
        cin >> node[i].x >> node[i].y;
    sort(node, node+n, cmp);

    //rep(i, 0, n-1)
       // cout << node[i].x <<' ' << node[i].y << endl;

    int cnt = 1;
    int sum = 0;
    rep(i, 0, n-1)
    {
        sum = max(sum, sum + node[i].x);
        cnt = cnt + node[i].y;
        cnt--;
        //cout << sum << ' ' <<cnt << endl;
        if(cnt <= 0)
            break;
    }
    cout << sum << endl;
}
