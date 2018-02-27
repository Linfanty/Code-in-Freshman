/*
由于a[i],b[i],c[i]互不相同，故两支队伍之间有且只有一胜利者，
进而最终一场不赢的队伍至多一支，
对(a[i],b[i],c[i])排序，败者在前，
最后判断第一个队伍是否败于其他所有队伍即可
*/
#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
const int  maxn = 2e5 + 5;
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;

int n, m;
struct Node
{
    int a, b, c, id;
    //bool operator < (const Node &a )const

}p[maxn];

bool cmp(Node x, Node y)
{
    int num = 0;
    if(x.a > y.a ) num++;
    if(x.b > y.b ) num++;
    if(x.c > y.c ) num++;
    if(num >= 2) return 0; // 赢两场 排后面
    return 1; //输的
}

int main()
{IO;
    cin >> n;
    rep(i, 1, n)
       cin >> p[i].a >> p[i].b >> p[i].c, p[i].id = i;

    sort(p+1, p+n+1, cmp);

    int gg = 0;

    rep(i, 2, n)
        if( !cmp(p[1],p[i ] ) )
        {
            gg = 1;break;
        }

    if( gg )
        cout <<  0 <<endl;
    else cout << 1 << endl << p[1].id << endl;

}
