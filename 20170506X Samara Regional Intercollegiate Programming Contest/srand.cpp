#include <bits/stdc++.h>

int main()
{
    freopen("in.txt", "w", stdout);
    int  a,b,c,d,e;
    srand((unsigned int) time(NULL));
    for(int i = 0; i<= 10000 ;i++)
    {
        a = rand() % 10000;
        b = rand() % 10000;
        c = rand() % 10000;
        d = rand() % 10000;
        e = rand() % 10000;
        printf("%d %d %d %d %d\n", a, b, c ,d, e);
    }
}
