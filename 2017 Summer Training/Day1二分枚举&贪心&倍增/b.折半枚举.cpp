#include <stdio.h>
#include <iostream>
#include <algorithm>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;

int n;
ll a[40];
pair<ll, int> res;//最优解,(和的绝对值，元素个数)
map<ll, int> dp;//和 → 元素个数

ll abs(ll x) {
    return x > 0 ? x : (-x);
}

int main()
{
    while( cin >> n && n)
    {
        rep(i, 0, n)
            cin >> a[i];
        res = make_pair(abs(a[0]), 1);
        int n2 = n / 2;

        //枚举前半部分
        rep(i, 0, (i<<n2))
        {
            ll sum = 0, num = 0;
            rep(j, 0, n2)
            {
                if( (i>>j) & 1 )
                {
                    sum += a[j];
                    num++;
                }
            }
            if( num == 0)
                continue;
            //更新最优解


        }


    }
}
