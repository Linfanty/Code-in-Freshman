#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define mem(a) memset(a, false, sizeof(a))
#define maxn 32005
ll tree[maxn], level[maxn], n;

//lowbit(k)=lowbit(1010)=0010(2进制)
void add(ll k, ll num){//将第k的数加num
    while(k <= maxn){
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
    int n, x, y, i;
    while( scanf("%d", &n) != EOF)
    {
        mem(tree), mem(level);
        rep(i, 1, n)
        {
            scanf("%d %d", &x, &y);
//忽略Y，只要统计小于本身X的star个数，就是level了
            level[ query(x+1) ] ++;
            add(x+1, 1);
        }
        rep(i, 1, n)
            printf("%d\n", level[i-1]);
    }

}

