
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int save[300][300];

bool dfs(int n, int now)
{
    if( save[n][now] != -1)
        return save[n][now];

    for(int i = 1; i <= n; i++)
    {
        if( i <= now){
            if( i <= now )
                if( !dfs(2*i, now-i))
                    return save[n][now] = 1;
        }
        else break;
    }
    return save[n][now] = 0;
}

int main()
{
    // scanf("%d", &n);
    for(int j = 1; j < 30; j ++)
    {
        n = j;

        memset(save, -1, sizeof(save) );
        for(int i = 2; i <= n; i++)
        {
            //if( !dfs(n ,i ) )
            cout << dfs(i-1 ,i ) <<' ';

        }
        cout << endl;
    }
}
