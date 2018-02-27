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

int n, m, a, b;

int main()
{IO;

    cin >> n >> a >> b;
    int i;
    for(i =a+1; i<=n;i++)
        if( n-i<=b) break;
    cout << n-i +1;



    if( a + b > n)
        cout << n - a;
    else if(a+b < n)
        cout << b + 1;
    else cout << b ;

}
