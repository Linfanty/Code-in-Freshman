#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
#define INFS 0xfffffff
#define INFB 0xfffffffffffffff
using namespace std;
typedef long long ll;
string s;
int prea[100005], preb[100005];
int main()
{
    int n, k;
    while(cin >> n >> k >> s)
    {
        memset(prea, 0, sizeof prea);
        memset(preb, 0, sizeof preb);
        for(int i = 0; i < n; i++)
            prea[i + 1] = prea[i] + (s[i] == 'a'), preb[i + 1] = preb[i] + (s[i] == 'b');
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int ta = upper_bound(prea + 1, prea + n + 1, prea[i - 1] + k) - prea - i, tb =  upper_bound(preb + 1, preb + n + 1, preb[i - 1] + k) - preb - i;
            ans = max(ans, max(ta, tb));
        }
        cout << ans << endl;
    }
    return 0;
}
