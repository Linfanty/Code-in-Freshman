#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
const int  maxn = 2e5 + 5;
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;
/*
题意：有N个人，M件物品，每个人和物品都有x，y两个值，
将这M件物品分配给这N个人，
要求物品的x，y值均要大于等于人的x，y值才可以分给这个人，
输出分配的方案，不行就输出-1。


思路：将人按x值由大到小处理，
每次将剩余的thing[x]>=human[x]的物品扔进set，
二分找出thing[y] >= human[y]的物品分配给他，就可以保证最优解了。
*/
int n, m, x, y;
int ans[maxn];
set< pair<int,int> > s;

struct Node
{
    int x, y, id;
    bool operator < (const Node& a) const
    {
        return x > a.x;
    }
}u[maxn], v[maxn];

int main()
{IO;
    cin >> n;
    rep(i, 0, n-1)
        cin >> u[i].x >> u[i].y , u[i].id = i;
    cin >> m;
    rep(i, 0, m-1)
        cin >> v[i].x >> v[i].y , v[i].id = i;

    sort(v, v+m);
    sort(u, u+m);

    int j = 0, flag = 0;
    rep(i, 0, n-1)
    {
        for(; v[j].x >= u[i].x ; j++)
            s.insert( make_pair( v[j].y, v[j].id ) );

        set<pair<int, int > > :: iterator it;

        it = s.lower_bound( make_pair(u[i].y ,-1 ));
        //在 v.y 中寻找比 u.y 大的 最接近的那个id
        //cout << it->first << ' ';
        //cout << it->second << endl;

        if( it == s.end() )
            flag = 1, break;
        //it-> 返回的是s中 的 v. id
        ans[ u[i].id ] = it->second;
        s.erase( it );//delete it
    }

    if( flag == 1)
        cout << -1 << endl;
    else
    {
    rep(i, 0, n-1)
        cout << ans[i] + 1 << ' ';
    cout << endl;
    }


}



