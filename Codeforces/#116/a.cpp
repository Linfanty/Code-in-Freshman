#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
#define INFS 0x3fffffff
#define INFB 0x3fffffffffffffff
using namespace std;
int len[205];
int fil[205][205];
int n, m;
int mem[40005];
int aim[205][205];
vector<pair<int, int> > ans;
int solve(int from, int to, int temp) {
    if(mem[to] == -1) {
        mem[to] = mem[from];
        fil[mem[from]/1000][mem[from]%1000] = to;
        ans.push_back(make_pair(from, to));
        mem[from] = -1;
        return from;
    }
    mem[temp] = mem[to];
    fil[mem[to]/1000][mem[to]%1000] = temp;
    mem[to] = -1;
    ans.push_back(make_pair(to, temp));
    mem[to] = mem[from];
    fil[mem[from]/1000][mem[from]%1000] = to;
    mem[from] = -1;
    ans.push_back(make_pair(from, to));
    if(temp == aim[mem[temp]/1000][mem[temp]%1000]) return from;
    return solve(temp, aim[mem[temp]/1000][mem[temp]%1000], from);
}
int main() {
_xx
    while(cin >> n >> m) {
        int t = 1;
        memset(mem, -1, sizeof mem);
        ans.clear();
        for(int i = 1; i <= m; i++) {
            cin >> len[i];
            for(int j = 1; j <= len[i]; j++) {
                cin >> fil[i][j];
                mem[fil[i][j]] = i*1000 + j;
                aim[i][j] = t++;
            }
        }
        int temp;
        for(int i = 1; i <= n; i++) {
            if(mem[i] == -1) {
                temp = i;
                break;
            }
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= len[i]; j++) {
                if(fil[i][j] == aim[i][j]) continue;
                temp = solve(fil[i][j], aim[i][j], temp);
            }
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}
