// #include<bits/stdc++.h>
// using namespace std;

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int INF  = 0x3f3f3f3f;
const int maxn = 1000008;
const int Mod  = 1e9 + 7;

#define ll       long long
#define mem(x,y) memset(x,y,sizeof(x))
#define IO       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

inline ll gcd(ll a, ll b)                       { return a % b == 0 ? b : gcd(b, a % b);}
inline ll lcm(ll a, ll b)                       { return a * b / gcd(a, b);}
inline ll quick_pow(ll x, int k)                { ll ans = 1; while (k) { if (k & 1) ans = (ans * x) % Mod;  x = x * x % Mod;  k >>= 1; } return ans;}
inline ll extend_gcd(ll a, ll b, ll &x, ll &y)  {if (b == 0) {x = 1, y = 0; return a;} ll t = extend_gcd(b, a % b, y, x); y -= a / b * x; return t;}

int isprime[maxn], num[maxn], x[8][maxn], cnt[8] = {0};
void init() {
    for (int i = 2; i < maxn; i++) {
        if (isprime[i] == 0) {
            for (int j = i; j < maxn; j += i)
                isprime[j] = 1, num[j]++;
        }
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j <= 7; j++)
            x[j][i] = x[j][i - 1];
        x[num[i]][i]++;
    }
}
int main() {
    init();
    IO;

    int T, a, b, e[8] = {0};
    cin >> T;
    while (T--) {
        cin >> a >> b;
        mem(e, 0);
        int ans = 1;
        for (int i = 7; i >= 1; i--) {
            e[i] = x[i][b] - x[i][a - 1];
            if (e[i] > 1) ans = max(ans, i);
        }
        if (e[6] && e[3]) ans = max(3, ans);
        if (e[4] && e[2]) ans = max(2, ans);
        cout << ans << endl;
    }

}
