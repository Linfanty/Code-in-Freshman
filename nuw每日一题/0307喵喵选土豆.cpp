/*
我们假设用01来表示每一个编号的土豆取还是不取，于是：对于每一个取土豆的方式，都有唯一的二进制串与之对应，如取1,3,4,7号土豆，对应串为1001101（从右向左编号），而这个串对应的美观值是1 * 3^0 + 0 * 3^1 + 1 * 3^2 + 1 * 3^3 +0 * 3^4 + 0 * 3^5 + 1 * 3^6 ，事实上就是这个串的当成三进制展开的值。而由于这些01串当成二进制和当成三进制的大小关系是相同的，所以，重量第k大的方案对应的的01串就是k的二进制表示，而对于一个了01串，它所对应的重量就是这个串按照三进制展开的值，于是本题解法为：将k所对应的二进制串当成三进制串转为十进制。
*/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
void deal(ll x)
{
    ll ans = 0;
    ll k = 1ll;
    while(x){
        ans += (x & 1ll) * k;
        k *= 3ll;
        x = x >> 1;
    }
    cout << ans << endl;
}
int main()
{IO;
    ll T;
    cin >> T;
    for(int i = 1; i <= T; i ++){
        cout << "case " << i << ": ";
        ll n;
        cin >> n;
        deal(n);
    }
    return 0;
}
