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
���⣺��N���ˣ�M����Ʒ��ÿ���˺���Ʒ����x��y����ֵ��
����M����Ʒ�������N���ˣ�
Ҫ����Ʒ��x��yֵ��Ҫ���ڵ����˵�x��yֵ�ſ��Էָ�����ˣ�
�������ķ��������о����-1��


˼·�����˰�xֵ�ɴ�С����
ÿ�ν�ʣ���thing[x]>=human[x]����Ʒ�ӽ�set��
�����ҳ�thing[y] >= human[y]����Ʒ����������Ϳ��Ա�֤���Ž��ˡ�
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
        //�� v.y ��Ѱ�ұ� u.y ��� ��ӽ����Ǹ�id
        //cout << it->first << ' ';
        //cout << it->second << endl;

        if( it == s.end() )
            flag = 1, break;
        //it-> ���ص���s�� �� v. id
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



