#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int fun(int x[], int N)
{
    int t = 0;
    if (N == 1) t = x[1];
    else if (N == 2) t = x[2];
    else if (N == 3) t = x[1] + x[2] + x[3];
    else {
        if (x[1] + x[N - 1] < 2 * x[2])
            t = x[N] + x[1] + x[N - 1] + x[1];
        else t = x[2] + x[1] + x[N] + x[2];
        t += fun(x, N - 2);
    }
    return t;
}
int main()
{
    int t, n;
    int x[10005];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        sort(x + 1, x + n + 1);
        cout << fun(x, n) << endl;
    }
    return 0;
}
