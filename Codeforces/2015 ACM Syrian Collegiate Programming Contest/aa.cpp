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
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int num;
        char s[2];
        ll sum = 0, up = 1e18 + 10;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %s", &num, s);
            if(s[0] == '+')
            {
                sum += num + 25; //寻求最大下届
            }
            else
            {
                up = min(up, sum + num + 25);//寻求最小上届
            }
        }
        printf("%I64d\n", up - sum); // 上 - 下
    }

    return 0;
}
