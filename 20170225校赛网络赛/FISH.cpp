//FISH STACK
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
    int fsize, fdir, n;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) != EOF)
    {
        while(!s.empty()) s.pop();
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &fsize, &fdir);
            if(fdir == 0)
            {
                while(!s.empty())
                {
                    ans--;
                    if(s.top() < fsize) s.pop();
                    else break;
                }
            }
            else s.push(fsize);
        }
        printf("%d\n", ans);
    }
    return 0;
}
