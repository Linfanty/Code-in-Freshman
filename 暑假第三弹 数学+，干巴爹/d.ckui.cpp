#include <bits/stdc++.h>
#define _xx ios_base::sync_with_sdtio(0);cin.tie(0);
#define INFS 0x3fffffff
#define INFB 0x3fffffffffffffff
#define printf pf
#define scanf sf
using namespace std;
typedef long long ll;
ll orx[25][2];
ll ans;
ll n, m, k;
ll xx1, yy1, xx2, yy2;
bool flag;
void dfs(int pos, int w) {
    if(pos >= k) {
        if(!flag) {
            flag = true;
            return;
        }
        ans = ans + w*(xx1*yy1)*(n - xx2 + 1)*(m - yy2 + 1);
        return;
    }
    ll t1 = xx1, t2 = xx2, t3 = yy1, t4 = yy2;
    dfs(pos + 1, w);
    xx1 = min(xx1, orx[pos][0]);
    yy1 = min(yy1, orx[pos][1]);
    xx2 = max(xx2, orx[pos][0]);
    yy2 = max(yy2, orx[pos][1]);
    dfs(pos + 1, -w);
    xx1 = t1, xx2 = t2, yy1 = t3, yy2 = t4;
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) cin >> orx[i][0] >> orx[i][1];
        ans = n*(n + 1)*m*(m + 1)/4;
        flag = false;
        xx1 = INFB;
        yy1 = INFB;
        xx2 = -1;
        yy2 = -1;
        dfs(0, 1);
        cout << ans << endl;

    }

    return 0;
}
