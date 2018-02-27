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
int f[10000005];

int ff(ll n)
{
    f[1] = 1, f[2] = 1;
    int i, j, s = 0;
    for(i = 3; i <= n; i++)
    {
        f[i] = ((f[i-1]%7*a%7)%7 + (f[i-2]%7*b%7)%7 )%7;
        for(j = 2; j < i; j++)
        {
            if( f[i-1] == f[j-1] &&f[i] == f[j])
            {
                s = i-j;
                break;
            }
        }
        if( s > 0)
            break;
    }

    if( s > 0)
        f[n]=f[(n-j)%s+j];

    if( n == 1 || n == 2)
        cout << 1 << endl;
    else cout << f[ n ] << endl;
}

int main()
{IO;
    while( cin >> a >> b >> n )
    {
        if( a == 0)
            break;
        ff(n);
    }
}
