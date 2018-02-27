#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
#define scd(a) scanf("%d", &a)
#define scab(a,b) scanf("%d%d",&a, &b)
#define prd(a) printf("%d\n", a)
#define prab(a,b) printf("%d %d\n", a, b)

using namespace std;
const int maxn = 1000005;

int n, m, q;
int a[maxn], b[maxn];

int main()
{
    while( scab(n,m) != EOF  )
    {
        mem(b, 0);
        int yu = 0, huo = inf, xo = 0;

        for(int i = 1; i <= n; ++i)
        {
            scd( a[i] );
            yu = yu & a[i];
            huo = huo | a[i];
            xo = xo ^ a[i];

            for(int j = 0; a[i]; ++j)
                a[i] >>= 1, b[j] += a[i] % 2;
        }

        while( m-- )
        {
            scd( q );

        }
    }
}
