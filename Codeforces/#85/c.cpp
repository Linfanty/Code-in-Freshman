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

string s1, s2;
int t, q[maxn];
vector <int> ans[maxn];

//0不属于整数 分为 正整数 0 负整数
//http://images.tutorvista.com/cms/images/38/positive-integers1.jpg
int main()
{
    ll n, x, y;
    int flag = 0;
    cin >> n >> x >> y;
 //   if( y-n+1 == 0)
 //       flag = 1;
    ll sum = (y-n+1)*(y-n+1) + (n-1);

    if( sum >= x && n <= y)
    {

            cout << y-n+1 <<endl;
                rep(i, 1, n-1)
            cout << 1 << endl;

    }
    else cout << -1 <<endl;
}
