#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define FIN freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;

int main()
{
    FIN;
    freopen("out1.txt", "w", stdout);
    ll a, b, c;
    ll n, m;
    while(cin >> a >> b >>c >>n >>m)
    {ll aa = a + c;
    ll bb = b + c;
//cout <<aa << ' ' << bb << endl;
    //if(n >= a && m >= b)
//cout << min(n,m) <<endl;

    if( a + b + c <= min(n,m) || (aa <= n && bb <= m) )
        cout << a + b + c <<endl;

    else  if( aa > n && bb > m)  // WA 2738 4028 1359 4097 4762
        {
            if(aa>n&&bb>m) cout <<min(n,m)<<endl;
            //else if(aa==n|| bb==m) cout << max(n,m) <<endl;
            //else cout << min(n,m) <<endl;
        }
    else if( a > n && b < m && bb <= m )
        cout << n <<endl;
    else if( a > n && b < m && bb > m )
        cout << m <<endl;

    else  if( a < n && b > m && aa <= n)
        cout << m <<endl;
    else  if( a < n && b > m && aa > n)
        cout << n <<endl;

    //else if(      aa > n && bb < m)
    //   cout << aa <<endl; //a < n && b < m &&
    else if(  aa > n && bb < m)
        cout << n <<endl;

    else if(        aa < m && bb > m)
        cout << m <<endl;

    else  if( aa >= a || bb >= b)
        cout << min(n,m) <<endl;


    //else
    }
}
