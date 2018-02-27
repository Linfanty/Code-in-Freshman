#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
#define maxn 40
const int N = 2e5 + 10;
using namespace std;

int main()
{
    ll n;
    while ( scanf("%lld", &n) !=EOF)
    {
        if( n%3 == 0)
            printf("No\n");
        else  printf("Yes\n");
    }
    return 0;
}
