#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long forg(long long m, long long &x, long long n, long long &y)
{
    long long x1, y1, x0, y0;
    x0 = y1 = 1;
    x1 = y0 = 0;
    long long r = (m % n + n) % n;
    long long q = (m - r) / n;
    while(r)
    {
        x = x0 - q * x1;
        y = y0 - q * y1;
        x0 = x1;
        y0 = y1;
        x1 = x;
        y1 = y;
        m = n;
        n = r;
        r = m % n;
        q = (m - r) / n;
    }
    return n;
}

int main()
{
    long long x, y, m, n, l;
    long long a, b;
    while(scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l) != EOF)
    {
        long long M = forg(n - m, a, l, b);
        if((x - y) % M || (m == n))
        {
            printf("Impossible\n");
            continue;
        }
        else
        {
            long long s = l / M;
            a = a * ((x - y) / M);
            a = (a % s + s) % s;
            printf("%lld\n", a);
        }
    }
    return 0;
}

