#include <stdio.h>
#include <bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;

int main()
{
    string x, y, s;
    cin >> x >> y;
    int len = x.size();
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum = sum * 10 + abs(x[i] - y[i]);
    }
    cout << sum;
}
