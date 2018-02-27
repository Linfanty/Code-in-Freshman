#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int maxl[N][20], minl[N][20];
int n, m, a[N];

void init_RMQ()
{
    int l = int(log((double)n)/log(2.0));
    for (int j=1;j<=l;j++)
        for (int i=1; i + (1 << (j-1) ) - 1 <=n;++i)
            minl[i][j] = min(minl[i][j-1], minl[i + (1 << (j-1) )][j-1]);
}

void RMQ(int l, int r)
{
    int k = int(log((double)(r-l+1))/log(2.0));
    int a = min(minl[l][k], minl[r - (1<<k) + 1][k]);
    printf("%d\n",a);
}



int main()
{
    while (~scanf("%d", &n))  //n long m query
    {
        for (int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
            maxl[i][0] = minl[i][0] = a[i];
        }
        init_RMQ();
        int a, b;
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d %d", &a, &b);
            RMQ(a, b);
        }
    }
    return 0;
}