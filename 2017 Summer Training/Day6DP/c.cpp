#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i < b; i++)
int a[10005];
int dp[10005];

int main()  {
    int n, st, ed, submax, left;
  /* start是最大子区间起点值，end为终点值
   submax是以array[i]为最右值的最大连续子区间的值
   left是这个子区间的起点值。*/
    while( scanf("%d", &n) && n )
    {
        rep(i, 0, n)
            scanf("%d", &a[i]);

        dp[0] = submax = a[0];
        st = ed = a[0];

        rep(i, 1, n)
        {
            if(a[i] > submax + a[i])
                submax = left = a[i];
            else submax = submax + a[i];

            if( dp[i-1] >= submax )
                dp[i] = dp[i-1];
            else
            {
                dp[i] = submax;
                st = left;
                ed = a[i];
            }
        }
        if( dp[n-1] < 0)
            dp[n-1] = 0, st = a[0], ed = a[n-1];
        printf("%d %d %d\n", dp[n-1], st, ed );

    }

}


