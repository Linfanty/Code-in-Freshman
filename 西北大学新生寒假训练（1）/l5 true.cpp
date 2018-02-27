#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

const int N = 505;

int degree[N], res[N];
bool map[N][N];
vector<int> a[N];
int n, m;

void Topo()
{
    int i, j, p;
    for(i = 1; i <= n; i++)
    {
        p = -1;
        for(j = 1; j <= n; j++)
        {
            if(degree[j] == 0)
            {
                degree[j]--;
                res[i] = p = j;
                break;
            }
        }
        for(j = 1; j <= n; j++)
        {
            if(map[p][j] == true)
            {
                map[p][j] = false;
                degree[j]--;
            }
        }
    }
}

void output()
{
    int i;
    printf("%d", res[1]);
    for(i = 2; i <= n; i++)
    {
        printf(" %d", res[i]);
    }
    printf("\n");
}

int main()
{
    int i, x, y;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(map, false, sizeof(map));
        memset(degree, 0, sizeof(degree));
        memset(res, 0, sizeof(res));
        for(i = 1; i <= n; i++) a[i].clear();
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d", &x, &y);
            if(map[x][y] == false)
            {
                map[x][y] = true;
                degree[y]++;
            }
        }
        Topo();
        output();
    }

    return 0;
}

