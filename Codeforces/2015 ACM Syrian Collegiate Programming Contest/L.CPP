#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int sum[100005];

void init()
{
    int co = 0;
    rep(i, 0, 100005)
    {

        int cnt = 0;
        int val = i;
        while( val != 0 )
        {
            if( val%2==1)
                cnt++;
            val /= 2;
        }

        if( cnt == 2 || cnt == 3 || cnt == 5
           || cnt == 7 || cnt == 11 || cnt == 13
           || cnt == 17 || cnt == 19 || cnt == 23
           || cnt == 27 || cnt == 29 || cnt == 31)
                co++;
        sum[i] = co;
    }

    //rep(i, 0, 100)
    //    cout << sum[i] << ' ';
}

int main()
{//IO;

    int t, l, r;
    init();
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d %d", &l, &r);

        printf("%d\n",sum[r] - sum[l-1]);
    }
    return 0;
}

/*


*/
