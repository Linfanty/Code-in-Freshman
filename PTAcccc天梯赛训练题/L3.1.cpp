#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;
typedef long long LL; 
const int Inf = 0X3f3f3f3f;
const int Max = 1100;
const double p = 10e-9;

int main()
{
	int i, k, j;
	int n, m, y, a, b, u, v;
	int x;
	double sum = 1000.0;
	scanf("%d %d", &n, &m);
	double s = 0.0;
	while(sum > p)
	{
		s += sum/(9.8*n);
		sum = sum*(1.0*(100-m)/100);
	}
	printf("%.3lf\n", s*200);
	return 0;
}

int main()
{
    double m, p, e = 1000;
    double h, g = 9.8, ans;
    const int n = 10000;
    scanf("%lf %lf", &m, &p);
    ans = 0;
    while(e > 0.000000001)//ªÚ’ﬂwhile(n--)
    {
        h = e*100/(m*g);
        ans += h*2;
        e = e*(1-p*0.01);
    }
    printf("%.3f\n", ans);
    return 0;
}
