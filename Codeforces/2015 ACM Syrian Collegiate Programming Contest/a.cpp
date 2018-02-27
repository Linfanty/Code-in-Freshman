#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)



int main()
{IO;

    int t, n;   string s[230];
    int x, y;

    cin >> t;
    while( t-- )
    {
        cin >> n;
        rep(i, 1, 3)
            cin >> s[i];


    int max1 = 0;

    for(int p = 1; p <= n; p ++ )
    {
        int sum = 0;
        for(int k = 0; k <= 2; k ++ )
        {
             rep(i, 1, 3)
             {
                 if( s[i][ (p-1)*3 + k ] == '*')
                    sum ++;
             }
        }
        //cout << sum << ' ';
        max1 = max(max1, sum);
    }

        cout << max1 * 4<< endl;
    }

}
