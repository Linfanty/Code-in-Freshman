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
    double r, R, h;
    scanf("%lf %lf %lf", &r, &R, &h);
    if( h <= 2*r)
    {
        printf("%.12lf\n", h/2);
        return 0;
    }
    double b = 2.0 * h * R * R - 2.0 * h * R * r;
    double a = h * h;
    double c = -1.0 * R * R * h * h;
    double x = b*b - 4.0*a*c;
    double xx = sqrt(x);
    double xxx = (-1.0 * b + xx) / (2.0 * a);
    //cout << x <<' ' << xx << ' ' << xxx << endl;
    printf("%.12lf\n", xxx);
}
