/*
����a[i],b[i],c[i]������ͬ������֧����֮������ֻ��һʤ���ߣ�
��������һ����Ӯ�Ķ�������һ֧��
��(a[i],b[i],c[i])���򣬰�����ǰ��
����жϵ�һ�������Ƿ�����������ж��鼴��
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
    if(num >= 2) return 0; // Ӯ���� �ź���
    return 1; //���
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
