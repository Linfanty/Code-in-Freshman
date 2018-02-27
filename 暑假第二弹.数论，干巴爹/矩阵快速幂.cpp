#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll poww(ll a, ll b, ll p)//mod p
{
    ll ans = 1;
    while( b )
    {
        if( b&1 != 0)
        {
            ans *= a;
            ans %= p;
        }
        a = a%p * a%p;
        b >>= 1%p;
    }
    return ans;
}

inline long long multi(long long x,long long y,long long mod)
{
long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
return tmp<0 ? tmp+mod : tmp;
}

int main()
{
    while(1)
    {
        ll x, y, p;
        cin >> x >> y >> p;
        cout << poww(x, y, p) << endl;
    }

}
