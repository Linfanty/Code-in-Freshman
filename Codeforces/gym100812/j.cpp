#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 200005;

vector<int> ve;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        ve.push_back(num);
    }
    sort(ve.begin(), ve.end());
    while(n && n <= ve.back())
    {
        ve.pop_back();
        n--;
    }
    printf("%d\n", n);

    return 0;
}
