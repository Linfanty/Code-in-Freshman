#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int main()
{
    string s;
    while( cin >> s)
    {
        int cnt = 0;
        if( s[0] == '#')
            break;
        int len = s.size();
        rep(i, 0, len-1)
        {
            if( s[i] == '1')
                cnt++;
        }
        if(s[len-1] == 'e' && cnt%2==0)
            s[len-1] = '0';
        else if(s[len-1] == 'e' && cnt%2==1)
            s[len-1] = '1';
        else if(s[len-1] == 'o' && cnt%2==0)
            s[len-1] = '1';
        else if(s[len-1] == 'o' && cnt%2==1)
            s[len-1] = '0';

        cout << s << endl;

    }

}
