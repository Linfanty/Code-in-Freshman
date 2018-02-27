#include <iostream>
#include <cstdio>
#include <cmath>
//#include <algorithm>
#include <string>
#include <cstring>
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
#define scd(a) scanf("%lld", &a);
#define scab(a,b) scanf("%d %d", &a, &b);
#define prd(a) printf("%f\n", a);
#define prab(a,b) printf("%d %d\n", a, b);

using namespace std;
const int maxn = 10005;

ll n, mid = 0;
ll da[15] = {0,3,26,255,3124,46655,823542,16777215,
387420488,
9999999999,285311670610,8916100448255,
302875106592252,11112006825558015,437893890380859374};


int main()
{
    while( scanf("%lld", &n) !=EOF)
    {
        int pos = lower_bound(da, da + 15, n) - da;
        printf("%d\n",  pos);
    }


    //for(int i = 1; i < 20; i++)
    //    prd( pow(i,i) );

/*
    for(int j = 1; j < 30000; ++j)
    {
        ll cnt = 0;
        for(int i = 1; i <= 30000; ++i)
        {
            if( pow(i,i) <= j )
                cnt++;
            else break;
        }

        if( cnt != mid)
        {
            mid = cnt;
            prd(j);
        }
        //prd(cnt);
    }
*/
}


