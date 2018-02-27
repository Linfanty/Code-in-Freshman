#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = (1<<16);
/*
	我们贪心的想一下，就可以发现，
	我能配对多少对袜子是和我的maxn和tol有关的。

     如果 tol/2 >= maxn,结果就是 tol/2, 
	 否则的话结果就是 tol-maxn；
	 具体可以多试几组数据画一画理解一下。
*/
int n;
LL x;

int main()
{IO;
    //FIN;
    cin >> n;
    LL tol = 0, maxn = 0;
    rep(i, 1, n)    { cin >> x; maxn = max(maxn, x); tol += x; }
    cout << (tol >= maxn*2 ? tol/2 : tol-maxn) << endl;
    return 0;
}
