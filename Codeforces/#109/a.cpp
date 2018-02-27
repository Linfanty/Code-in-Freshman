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

int main()
{
    int n;
    int a;

    cin >> n;
    cin >> a;
    int max1 = a;
    int min1 = a;
    int cnt = 0;

    rep(i, 2, n)
    {
        cin >> a;
        if( a > max1 || a < min1 )
            cnt ++;
        max1 = max(a, max1);
        min1 = min(a, min1);

    }
    cout << cnt << endl;
}
