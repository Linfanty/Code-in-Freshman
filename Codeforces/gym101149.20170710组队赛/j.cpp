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

int a[maxn];
int main()
{
    int n;
    cin >> n;
    rep(i, 1, n)
        cin >> a[i];

        ll sum = 0;
    a[0] = 0;
    rep(i, 1, n)
    {
        if(a[i] > a[i-1])
            sum += a[i] - a[i-1];
    }
    cout << sum << endl;
}
