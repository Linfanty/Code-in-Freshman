#include <cstdio>
int const MAX = 30000 + 5;
int fa[MAX];

void UF_set(int n)
{
    for(int i = 0; i < n; i++)
        fa[i] = i;
}

int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 == 0)
        fa[r2] = r1;
    else if(r2 == 0)
        fa[r1] = r2;
    else
        fa[r1] = r2;
}

int main()
{
    int n, m, ans;
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        ans = 0;
        UF_set(n);
        for(int i = 0; i < m; i++)
        {
            int get, fir, k;
            scanf("%d %d", &k, &fir);
            for(int j = 1; j < k; j++)
            {
                scanf("%d", &get);
                Union(get, fir);
            }
        }
        for(int i = 0; i < n; i++)
            if(Find(i) == 0)
                ans++;
        printf("%d\n", ans);
    }
}
