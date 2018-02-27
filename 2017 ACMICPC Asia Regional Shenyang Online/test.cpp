#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define inf 0x3f3f3f3f
#define maxn 100005
#define ll long long
//const int N = 2e5 + 5;
using namespace std;

int main()
{
    ll k, m;
    while( scanf("%lld %lld", &m, &k) != EOF )
    {
        printf("%lld\n", k*(m-k+1) );
    }

    return 0;
}
