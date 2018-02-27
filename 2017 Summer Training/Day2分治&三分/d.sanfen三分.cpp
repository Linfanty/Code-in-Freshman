#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 200100;

int n;
double a[maxn], b[maxn], eps = 1e-12;

double getmax()
{
    double ans = 0, sum = 0;
    repp(i, 1, n)
    {
        sum += b[i];
        if( sum < 0 )
            sum = 0;
        ans = max(ans, sum);
    }
    return ans;
}

double cal(double x)
{///绝对值最大问题
///先-x按区间段最大找一遍，再把数组去相反数找一次取max
    repp(i, 1, n)   b[i] = a[i] - x;
    double ans = getmax();

    repp(i, 1, n) b[i] = -b[i];
    ans = max(ans, getmax());
    return ans;
}

int main()
{
    cin >> n;
    repp(i, 1, n) cin >> a[i];

    double l = -10000.0, r = 10000.0, mid;
    rep(i, 0, 100) // 100为模板
    {
        double m1 = l + (r-l) / 3;
        double m2 = r - (r-l) / 3;
//cout<<m1<<' '<<m2<<' '<<cal(m1)<<' '<<cal(m2)<<endl;
        ///除了cal()函数要写， 其他为模板:
        if( cal(m1) < cal(m2) )
            r = m2;
        else l = m1;
    }
    printf("%.12f\n", cal(l));
}
