#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

int nu[20][5] =
{
    {1, 1, 1, 1, 1},{2, 1, 1, 2, 0},{1, 2, 2, 1, 0},{2, 1, 2, 0, 1},{3, 1, 2, 1, 0},
    {2, 2, 3, 0, 0},{1, 3, 1, 0, 1},{2, 3, 1, 1, 0},{1, 4, 2, 0, 0},{2, 2, 0, 1, 1},
    {3, 2, 0, 2, 0},{2, 3, 1, 1, 0},{3, 2, 1, 0, 1},{2, 3, 0, 0, 1},{3, 0, 1, 1, 1},
    {4, 0, 1, 2, 0},{3, 1, 2, 1, 0},{4, 0, 2, 0, 1},{3, 2, 1, 0, 1},{4, 1, 0, 1, 1},
};
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        char s[10];
        scanf("%s", s);
        int num[10] = {0};
        int len = strlen(s);
        for(int i = 0; i < len; i++)
            num[s[i] - 'A']++;
        int ok = 0;
        for(int i = 0; i < 20; i++)
        {
            if(num[0] >= nu[i][0] && num[1] >= nu[i][1] && num[2] >= nu[i][2] && num[3] >= nu[i][3] && num[4] >= nu[i][4])
            {
                ok = 1;
                break;
            }
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
