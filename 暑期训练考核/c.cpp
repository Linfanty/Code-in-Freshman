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
#define scd(a) scanf("%d",&a);
#define prd(a) printf("%d\n", a);

using namespace std;
const int maxn = 100005;

int n, m;
int hi[maxn];

bool check(int mid)
{
    int hi_score = 0, ho_score = 0, ho = 0;

    for(int i = 0; i < n; ++i)
    {
        ho = ho + mid;
        if( ho <= hi[i])
            ++hi_score, ho = 0;
        else
            ++ho_score, ho = ho - hi[i];
    }
    if( ho_score > hi_score )
        return true;
    else return false;
}

int main()
{
    while( scanf("%d %d",&n, &m) != EOF)
    {
        int ans = 0, low = 0, high = m+1;
        for(int i = 0; i < n; ++i)
            scd(hi[i]);

        while( low <= high)
        {
            int mid = (low + high) >> 1;
            if( check(mid) )
            {
                ans = mid ;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        prd(ans);
    }
}
