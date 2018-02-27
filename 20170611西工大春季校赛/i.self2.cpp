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

string s;
vector<int> ans[maxn];
int t, q[maxn];

void outPut(int p)
{
    if( ans[p].size() == 0) // ��û�м����ĵݹ������ ��ֱ�����
        cout << s[p];
    else
    {
        cout << 'x';
        rep(i, 0, 3)
        {
            int v = (i+2) % 4;//�������3 4 1 2 �� 2 3 0 1
            outPut( ans[p][v] );//�������3 4 1 2 �� 2 3 0 1
        }
    }
}

int solve()
{
    int top = 0;
    rep(i, 0, s.size()-1)
    {
        if( top && ans[ q[top-1]/******/ ].size() == 4)
            top--; // �˳���ǰ�ݹ�Ĳ���

        if( s[i] == 'x')
        {
            if ( top )
                ans[ q[top-1]/******/ ].push_back(i);
            q[ top++ ] = i;  //��ǵݹ����
        }
        else
            if( top )
                ans[ q[top-1]/******/ ].push_back(i);
    }
    outPut(0);
    cout << endl;
}

int main()
{
    cin >> t;
    int w = 0;
    while( t-- )
    {
        rep(i, 0, maxn-1)
            ans[i].clear();
        cin >> s;
        cout << "Case #" << ++w << ":" << endl;
        solve();
    }
}
