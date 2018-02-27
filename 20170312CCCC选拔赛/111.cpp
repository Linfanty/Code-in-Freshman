#include <stdio.h>
#define N 100
struct Rational
{
    int n;
    int d;
};
int gcd(int m, int n)
{
    int r;
    if (m == 0 && n == 0)
        return 0;
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    while (1)
    {
        r = m % n;
        if (r == 0)
            break;
        m = n;
        n = r;
    }
    return n;
}
int main(void)
{
    struct Rational ra[N], r;
    int i, n, g;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d/%d", &ra[i].n, &ra[i].d);
    r.n = 0;
    r.d = 1;
    for (i = 0; i < n; ++i)
    {
        r.n = r.n * ra[i].d + r.d * ra[i].n;
        r.d = r.d * ra[i].d;
    }
    r.d *= n;   /*ƽ��ֵ */
    g = gcd(r.n, r.d);
    if (g != 0)
    {
        r.n /= g;
        r.d /= g;
    }
    if (r.n == 0)
        printf("%d\n", r.n);
    else if (r.d == 1)
        printf("%d\n", r.n);
    else
        printf("%d/%d\n", r.n, r.d);
    return 0;
}

