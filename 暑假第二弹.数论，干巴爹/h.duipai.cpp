#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
int a, b;
ll n;
int f[100005];

int main()
{IO;
    while( cin >> a >> b >> n )
    {
        if( a == 0)
            break;
            f[1] = 1, f[2] = 1;

        rep(i, 3, n)
            f[i] = (f[i-1]*a + f[i-2]*b) %7;

        cout << (5*a + 3*b) << ' '<< (5*a + 3*b)%7 <<endl;
        cout << f[n] << endl;

    }
}
