#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
#define INFB 0x3fffffffffffffff
using namespace std;
typedef long long ll;
struct Node {
    int c, r, id;
} node[123456];
bool operator < (const Node& t1, const Node& t2) {
    return t1.c < t2.c;
}
int n;
priority_queue<pair<int, int> > q;
vector<int> ans;
int main() {
_xx
    while(cin >> n) {
        ans.clear();
        for(int i = 1; i <= n; i++) {
            cin >> node[i].c >> node[i].r;
            node[i].id = i;
        }
        int nowr = 1, aimc = node[n].c;
        sort(node + 1, node + 1 + n);
        int pos = 1;
        while(!q.empty()) q.pop();
        while(nowr < aimc && pos <= n) {
            if(node[pos].c <= nowr) {
                q.push(make_pair(node[pos].r, node[pos].id));
                pos++;
            }
            else {
                if(q.empty()) break;
                pair<int, int> temp = q.top();
                q.pop();
                if(temp.first <= nowr) break;
                else {
                    nowr = temp.first;
                    ans.push_back(temp.second);
                }
            }
        }
        if(nowr < aimc) {
            cout << "No such luck" << endl;
        }
        else {
            ans.push_back(n);
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
