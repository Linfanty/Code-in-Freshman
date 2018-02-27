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

void judge(string& s)
{
    int i = 0;
    while( s[i] && s[i] < '2')
        ++i;
    while( s[i] )
        s[i++] = '1';
}

int dfs(string s)
{
    judge(s);
    int ans = 0;
    for(int i = 0; s[i]; ++i)
        ans = ans * 2 + s[i] - '0';
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << dfs(s);
}
