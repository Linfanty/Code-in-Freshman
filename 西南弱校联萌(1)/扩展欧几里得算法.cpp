#pragma comment(linker, "/STACK:36777216")

#include <bits/stdc++.h>
using namespace std;
#define LSON            id << 1 , l , mid
#define RSON            id << 1 | 1 , mid + 1 , r
#define ROOT            1 , 1 , n
#define CLR(x , y)      memset(x , y , sizeof(x))
#define LOWBIT(x)       x & (-x)
#define FORN(i , a , n)  for(int i = (a) ; i <= (n) ; ++i)
#define FORP(i , n , a)  for(int i = (n) ; i >= (a) ; --i)
#define CASE(x)        printf("Case %d: ", x)
#define SFD(x)      scanf("%lf" , &x)
#define SFC(x)      scanf(" %c" , &x)
#define SFS(x)      scanf(" %s" , x)
#define SFI(x)      scanf("%d" , &x)
#define SFL(x)      scanf("%lld" , &x)
#define SFI64(x)    scanf("%I64d" , &x)
#define PFF(x)         printf("%f" , x)
#define PFD(x)         printf("%lf" , x)
#define PFI(x)         printf("%d" , x)
#define PFC(x)         printf("%c" , x)
#define PFS(x)         printf("%s" , x)
#define PFI64(x)       printf("%I64d" , x)
#define PFL(x)         printf("%lld" , x)
#define SPACE          printf(" ")
#define PUT            puts("")
#define LPUP(i , j , k) for(int i = j ; i <= k ; ++i)
#define LPDW(i , j , k) for(int i = j ; i >= k ; --i)
#define PB(x)          push_back(x)
#define ALL(A)         A.begin(), A.end()
#define SZ(A)          int((A).size())
#define LBD(A, x)      (lower_bound(ALL(A), x) - A.begin())
#define UBD(A, x)      (upper_bound(ALL(A), x) - A.begin())
#define LOCAL
static const double PI = acos(-1.0);
static const double EPS = 1e-8;
static const int INF = 0X3fffffff;
typedef long long LL;
typedef double DB;
template<class T> inline
T read(T &x)
{
    x = 0;
    int f = 1 ; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == ' -') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

/************************Little Pea****************************/
LL a , b , c;
LL exgcd(LL a , LL b , LL& x , LL& y)
{
    if(!b)
    {
        x = 1 , y = 0;
        return a;
    }
    LL ans = exgcd(b , a % b , x , y);
    LL temp = x;
    x = y;
    y = temp - (a / b) * y;
    return ans;
}
LL x , y;
int main()
{

    while(~scanf("%lld%lld%lld" , &a , &b , &c))
    {
        bool flag = 0;
        if (a == 0 && b == 0)
        {
            if (c == 0)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        if (b > a)
        {
            flag = 1;
            swap(a , b);
        }
        LL g = exgcd(a , b , x , y);
        if (c % g)
        {
            printf("-1\n");
            continue;
        }
        if (flag)
        {
            swap(x , y);
            swap(a , b);
        }
        LL k = b / g;
        if (k == 0)
        {
            if (a * c < 0) printf("-1\n");
            else
                printf("%lld\n" , c / g);
            continue;
        }
        x = x * (c / g);
        k = abs(k);
        if (x >= 0)
        {
            x = x % k;
        }
        else
        {
            x = abs(x);
            x %= k;
            if (x)
                x = k-x;
        }
        printf("%lld\n" , x);

    }

}
