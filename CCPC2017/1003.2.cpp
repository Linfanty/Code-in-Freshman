#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int pre[4005];
int flag;

int fd(int x) {
    return pre[x] == x ? x : pre[x] = fd(pre[x]);
}

int join(int x, int y)
{
    int fx = fd(x);
    int fy = fd(y);
    // cout << fx << ' ' << fy << endl;
    if( fx == fy)
        flag = 1;
    else pre[y] = x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        int n, a;
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i)
            pre[i] = i;

        flag = 0;

        for(int i = 1; i < n; ++i )
        {
            for(int j = i+1; j <= n; ++j)
            {
                scanf("%d", &a);

                if( flag == 1)
                    continue;
                if( a == 1)
                    join(i, j);

            }
        }

        if( flag == 1)
            cout << "Bad Team!" << endl;
        else cout << "Great Team!" << endl;
    }
}
