#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;

int n, len, val[30], tol = 0, firstvit[30], cnt = 0, flag[30], ans = 0;
int ch[300];
string s[30];

ll total(string ss){
    ll sum = 0;
    rep(i, 0, ss.size()-1)
        sum = sum * 10 + val[  ss[i] - 'A' ];
    return sum;
}

void dfs(int num, int depth){

    if( firstvit[ ch[depth] ] && num == 0 )
        return;
    val[  ch[depth] ] = num;

    if( depth == tol - 1){
        ll summ = 0;
        rep(j, 1, n-1)
            summ += total(s[j]);
        if( summ == total(s[n]) )
        {
            //cout << summ <<endl;
            ans++;
        }
        return;
    }

    rep(j, 0, 9){
        if( flag[j] == 1)
            continue;
        flag[j] = 1;
        dfs(j, depth+1);
        flag[j] = 0;
    }
}

int main(){
    cin >> n;
    memset(flag, 0, sizeof(flag));
    memset(firstvit, 0, sizeof(firstvit));
    rep(i, 1, n){
        cin >> s[i];   len = s[i].size();

        firstvit [ s[i][0] - 'A' ] = 1;
        rep(j, 0, len-1)
            ch[cnt++] = s[i][j] -'A';
    }
    sort(ch, ch+cnt);
    tol = unique(ch, ch + cnt) - ch;//0 2 4 6 14 15 17 18 19 22

    rep(i, 0, 9){
        flag[i] = 1;
        dfs(i, 0);
        flag[i] = 0;
    }
    cout << ans << endl;
}
