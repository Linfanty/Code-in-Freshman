#include  <bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
void online() {
    freopen("INTPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
}*/
ll p = 1e9 + 7;
ll poww(ll a, ll b)
{
	ll ans = 1, base = a;
	while( b!=0)
	{
		if( b&1 !=0)
		{
			ans *= base;
			ans = ans % p;
		}
		base = (base %p * base % p);
		b >>= 1%p;
	}
	return ans;
}
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    ll count = 0;
    for(int i = 0; i < len; i++)
    {
        if( s[i] == 'N' || s[i]=='S')
        {
            if( s[i+1] == 'W' || s[i+1]== 'E')
            {
                count ++ ;
                i++;
            }
        }
    }
    cout << poww(2,count) % p <<endl;
}
