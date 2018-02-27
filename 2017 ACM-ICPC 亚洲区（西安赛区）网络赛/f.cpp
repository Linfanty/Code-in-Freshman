#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <climits>
#include <bitset>
#include <ctime>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define maxn 1000005
#define inf 0x3f3f3f3f

const ll mod = 998244353;

ll quick_pow(ll t, ll n) { //ÆÕÍ¨¿ìËÙÃÝ
	ll ans = 1;
    while(n) {
        if(n & 1) ans = (ans * t) % mod;
        t = (t * t) % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
	ll n, m;
	while(~scanf("%lld%lld", &n, &m)) {
		if(m > n) {
			puts("0");
			continue;
		}
		if((n & 1) ^ (m & 1)) {
			puts("0");
			continue;
		}
		if(m == 0) {
			printf("%lld\n", mod - 1);
			continue;
		}
		ll ans = 1;
		for(ll i = n - m + 2; i <= n + m - 2; i += 2) {
			ans *= i;
			ans %= mod;
		}
		ans = ans * n % mod;
		ll k = 1;
		for(ll i = 1; i <= m; i++) {
			k = k * i % mod;
		}
		ll x = quick_pow(k, mod - 2);
		ans = ans * x % mod;
		if(((n - m) / 2) & 1) ans = (mod - ans) % mod;
		printf("%lld\n", ans);
	}
}
