#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
#define maxn 10005
#define ll long long

struct Node
{
  char s[100];
  double a;
} node[100];
int main()
{
   int n;
   scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %lf", node[i].s, &node[i].a);
    }
    double m;
    scanf("%lf", &m);
    for(int i = 0; i < n; i++)
    {
        if(fabs(node[i].a) < 1e-15)
            printf("%s 0.00\n", node[i].s);
        else
            printf("%s %.2f\n", node[i].s, m * 100.0 / node[i].a);
    }
    return 0;
}
