#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define   freopen("holes.in", "r", stdin);
#define   freopen("holes.out", "w", stdout);
typedef long long ll;
const int N = 2e5 + 5;
const int manx = 1005;
using namespace std;

int n, m;
int a[] = {1,0,0,0,1,0,1,0,2,1};

int main()
{
    freopen("holes.in", "r", stdin);
    freopen("holes.out", "w", stdout);

    int n;
    while(cin >> n)
    {
        if( n == 1)
            cout << 0 <<endl;
        else if( n == 0)
            cout << 1 << endl;
        else if( n%2 == 0)
        {
            rep(i,1,n/2)
            cout << 8;
            cout <<endl;
        }
        else
        {
            cout << 4;
            rep(i,1,n/2)
                cout << 8;
            cout << endl;
        }
    }
}

