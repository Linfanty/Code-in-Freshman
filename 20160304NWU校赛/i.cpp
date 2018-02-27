#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#define rep(i,a,b) for(int (i) = (a);(i) <= (b);++ (i))
#define per(i,a,b) for(int (i) = (a);(i) >= (b);-- (i))
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define mid ((l+r)>>1)
#define ls (id<<1)
#define rs ((id<<1)|1)
#define N 1000000+5
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f
typedef long long ll;
const ll mod = 1e8+7;
const ll eps = 1e-12;
using namespace std;

int T,a,b,k,sum[N],g[N];
bool isPrime[N];
vector <int> ans[20];
void fuc(){
    mem(isPrime, true);
    rep(i, 2, N-1){
        if(isPrime[i]){
            for(int j = i+i;j <= N-1;j += i){
                isPrime[j] = false;
                sum[j] += i;
            }
        }
    }
    rep(i, 2, N-1){
        if(isPrime[i])    g[i] = 1;
        else
            g[i] = g[sum[i]]+1;
        ans[g[i]].push_back(i);
    }
}
int main()
{IO;
    //FIN;
    //FOUT;
    fuc();
    while(cin >> a >> b >> k){
        if(k >= 13){
            cout << "0" << endl;
            continue;
        }
        int l = lower_bound(ans[k].begin(), ans[k].end(), a)-ans[k].begin();
        int r = upper_bound(ans[k].begin(), ans[k].end(), b)-ans[k].begin();
        cout << r-l << endl;
    }
    return 0;
}
