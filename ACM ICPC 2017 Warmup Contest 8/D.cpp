#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 10005
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define ll long long

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        if(a + b != 361)
            printf("Unknown\n");
        else if(a - 7.5 > b)
            printf("Black\n");
        else if(a - 7.5 <= b)
            printf("White\n");
    }

}
