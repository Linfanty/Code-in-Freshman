#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
using namespace std;
#define maxn 10005
#define ll long long
typedef pair<ll, ll> P;

set<P> se;
int main()
{
    int n, t = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        printf("Case %d:\n", t++);
        char s[20]; ll a, b;
        for(int i = 0; i < n; i++)
        {
            scanf("%s %lld %lld", s, &a, &b);
            if(s[0] == 'a')
                se.insert(P(a, b));
            else if(s[0] == 'r')
                se.erase(P(a, b));
            else
            {
                set<P>::iterator pos = lower_bound(se.begin(), se.end(), P(a, b));
                if(pos == se.end())
                    printf("-1\n");
                else
                {
                    printf("%lld %lld\n", (*pos).first, (*pos).second);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
