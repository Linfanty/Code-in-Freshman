#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
const int N = 1e6 + 5;
using namespace std;

int num[N];

int main()
{
    //freopen("deposits.in", "r", stdin);
    //freopen("deposits.out", "w", stdout);
    int n, m, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
         scanf("%d", &a);
         int mid = sqrt(a);
         //printf("%d", mid);
         for(int j = 1; j <= mid; j++)
            if(a % j == 0)
                num[j]++, num[a / j]++;
        if(mid * mid == a)
            num[mid]--;
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", num[i]);
    ll sum = 0;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        sum += num[b];
    }
    printf("%I64d", sum);
}
