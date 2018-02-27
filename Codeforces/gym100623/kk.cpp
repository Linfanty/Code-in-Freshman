#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
#define maxn 40
const int N = 2e5 + 10;
using namespace std;

int num[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        num[a] = 1;
    }
    vector<int> ans;
    for(int i = 1; m; i++)
    {
        if(!num[i])
            ans.push_back(i), m--, num[i] = 1;
        else
        {
            for(int j = 1; j < i; j++)
            	if(num[j] == 1 && !num[j + i])
	                num[j + i] = 2;
        }
    }
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}
