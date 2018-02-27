#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = (1<<16);

int n, m;
LL a[20], b[20];
vector <LL> ans, ANS;
map <LL, bool> vis, VIS;

struct Node{
    int bt;
    LL val;
    bool operator < (const Node &r) const   { return val < r.val; }
}node[N];

bool judge(int i, int j){
    int a = node[i].bt, b = node[j].bt;
    if(a&b) return false;
    return true;
}

int main()
{IO;
    //FIN;
    cin >> n >> m;
    rep(i, 1, n)    cin >> a[i];
    rep(i, 1, m)    cin >> b[i];

    rep(i, 0, ((1<<m)-1)){
        int bit = i, p = 1;
        LL res = 0;
        while(bit){
            if(bit&1)   res += b[p];
            p++; bit >>= 1;
        }
        node[i].val = res;
        node[i].bt = i;
    }
    sort(node, node+(1<<m));
    int i = 0;
    while(i < (1<<m)){
        int j = i+1;
        if(vis[node[i].val])    { i++; continue; }
        while(j < (1<<m)){
            if(node[i].val != node[j].val)  break;
            if(judge(i, j)){
                if(!vis[node[i].val]) ans.pb(node[i].val);
                vis[node[i].val] = true;
            }
            j++;
        }
        i++;
    }
    //rep(i, 0, (int)ans.size()-1)    cout << ans[i] << " ";
    rep(i, 1, n){
        if(!VIS[a[i]])  ANS.pb(a[i]);
        VIS[a[i]] = true;
        rep(j, 0, (int)ans.size()-1){
            LL res = a[i]+ans[j]*2;
            if(!VIS[res]) ANS.pb(res);
            VIS[res] = true;
        }
    }
    sort(ANS.begin(), ANS.end());
    rep(i, 0, (int)ANS.size()-1)    cout << ANS[i] << endl;
    return 0;
}
