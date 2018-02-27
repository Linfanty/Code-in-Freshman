#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

int main()
{
    int n, max1 = -inf, a;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a;
        max1 = max( max1, a);
    }
    cout << max1 <<endl;
}
