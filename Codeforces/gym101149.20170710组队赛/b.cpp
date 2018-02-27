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

int n;

struct Node
{
    ll a, b;
}node[maxn];

bool cmp(Node x, Node y)
{
    return (y.a - y.b) < (x.a - x.b);
}

int main()
{
    cin >> n;
    ll sum = 0;
    rep(i, 0, n-1)
    {
        cin >> node[i].a >> node[i].b;
    }
    sort(node, node + n, cmp);

    //rep(i, 0, n-1)
      // cout << node[i].a << ' ' << node[i].b <<endl;

    ll m = 0;
    rep(i, 0, n-1)
    {
        if(m < node[i].a)
        {
            sum += node[i].a - m;
            m = node[i].a - node[i].b;
        }
        else
            m -= node[i].b;
    }
    cout << sum << endl;

    return 0;
}
