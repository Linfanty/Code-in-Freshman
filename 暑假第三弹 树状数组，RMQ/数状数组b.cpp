#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define mem(a) memset(a, false, sizeof(a))
#define maxn 500005
ll tree[maxn], n;

struct Num{
    ll val, pos;
    bool operator < (const Num& x) const{
        return val < x.val;}
}a[maxn];

//lowbit(k)=lowbit(1010)=0010(2进制)
void add(ll k, ll num){//将第k的数加num
    while(k <= n){
        tree[k] += num;
        k += k&-k;
    }
}
ll query(ll k) {//查询1~k的区间和
    ll sum = 0;
    while(k){
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}


int main()
{
    while( cin >> n && n )
    {
        mem(tree);
        rep(i, 1, n)
            cin >> a[i].val, a[i].pos = i;

        /**
        9 1 0 5 4
        1 2 3 4 5
        ``````````````````````````````````````
        0 1 4 5 9 从小到大排序
        3 2 5 4 1 对应的编号pos
        从右到左，有x个数比ta大
        a[5].pos = 1,ans = 0  1 0 0 0 0
        a[4].pos = 4,ans = 1  1 0 0 1 0
        a[3].pos = 5,ans = 3  1 0 0 1 1
        a[2].pos = 2,ans = 4  1 1 0 1 1
        a[1].pos = 3,ans = 6  1 1 1 1 1
        */
        sort(a+1, a+n+1);
        //枚举每个数，然后查询这个数前面的区间值的总和
        ll ans = 0;
        //per(i, n, 1)错的
            //ans += query(a[i].pos), add(a[i].pos, 1);
            rep(i,1,n)//对的
                add(a[i].pos, 1), ans += query(n) - query(a[i].pos);
            // add(a[i].r,1);
            //ans+=sum(y)-sum(a[i].r);
        cout << ans <<endl;
    }
}

