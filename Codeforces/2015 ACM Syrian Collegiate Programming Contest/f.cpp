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
{
    int t;
    cin >> t;
    string s;
    rep(i, 1, t)
    {
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        cin >> s;
        rep(j, 0, 6)
        {
            if( s[j] == 'A' )
                a++;
            else if( s[j] == 'B' )
                b++;
            else if( s[j] == 'C' )
                c++;
            else if( s[j] == 'D' )
                d++;
            else if( s[j] == 'E' )
                e++;
        }

        int flag = 0;
        if( a == 0 )
            flag = 1;
        else

        if( b == 0 )

        if( c == 0 && !( a != 0 && b != 0) )
            flag = 1;
        else
        {
            a--;
            b--;
        }


        if( d == 0 && !( a != 0 && c != 0 ) )
            flag = 1;
        else
        {
            a--;
            c--;
        }

        if( e == 0 &&  !( a != 0 && d != 0) &&  !( b != 0 && c != 0) )
            flag = 1;
        /*else
        {
            a--;
            b--;
            e++;
        }*/
        //|| !( b == 0 && c == 0 ) )|| !( b == 0 && c == 0 ) )

        //else if( e == 0 &&  !( b != 0 && c != 0)  )
        //    flag = 1;
        /*
        else
        {
            b--;
            c--;
            e++;
        }*/


        if( flag == 1)
            cout << "NO" <<endl;
        else cout << "YES" <<endl;

    }
}
