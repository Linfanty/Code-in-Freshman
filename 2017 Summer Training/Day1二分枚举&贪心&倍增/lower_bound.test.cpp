#include <stdio.h>
#include <iostream>
#include <algorithm>
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
const ll maxn = 4005;
ll a[maxn], b[maxn], c[maxn], d[maxn], e[maxn<<1];

int main()
{
    int n;

     int a[16] = {1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,6};

     /**sort()*/
     int pos1, pos2;
     while( cin >> n )
     {
         pos1 = lower_bound(a, a+16, n ) - a;// 大于等于
         pos2 = upper_bound(a, a+16, n ) - a;//大于
         cout << pos1 << ' ' << pos2 << endl;
     }
}
