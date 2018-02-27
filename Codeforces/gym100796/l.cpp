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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cn = 0, nt = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == ':' && s[i + 1] == ')')
            cn++;
        else if(s[i] == '(' && s[i + 1] == ':')
            cn++;
        else if(s[i] == ':' && s[i + 1] == '(')
            nt++;
        else if(s[i] == ')' && s[i + 1] == ':')
            nt++;
    }
    if(cn > nt)
        cout <<"HAPPY";
    else if(cn == nt)
        cout << "BORED";
    else
        cout << "SAD";
}
