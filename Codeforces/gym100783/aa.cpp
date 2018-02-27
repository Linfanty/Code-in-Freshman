#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int N = 20;
int val[30], flag[10], vit[30], cnt = 0, tt = 0, n;
char ch[105];   string s[N];

ll add(string a){
    int len = a.length();
    ll sum = 0;
    for(int i = 0; i < len; i++)
        sum = sum * 10 + val[a[i] - 'A'];
    return sum;
}

void dfs(int t, int b) {
/// t 为 第b位 的 值  (0到9)
    if(vit[ch[b] - 'A'] &&  t == 0) /// b 为 首字母 且 赋值为 0
        return;

    int tmp = ch[b] - 'A';
    val[tmp] = t;

    if(b == tt - 1){ /// dfs 结束条件
        ll sum = 0;
        for(int i = 0; i < n - 1; i++)
            sum += add(s[i]);

        if(sum == add(s[n - 1])) {
            cout << sum << endl;
            cnt++;
        }
        return;
    }

    for(int i = 0; i <= 9; i++) /// 不重复
    {
        if(flag[i])
            continue;
        flag[i] = 1;
        dfs(i, b + 1);
        flag[i] = 0;
    }
}

int main()
{
    cin >> n;
    memset(flag, 0, sizeof(flag));
    memset(vit, 0, sizeof(vit));

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        int len = s[i].length();

        for(int j = 0; j < len; j++)
            ch[tt++] = s[i][j];
        vit[s[i][0] - 'A'] = 1;
    }

    sort(ch, ch + tt);
    tt = unique(ch, ch + tt) - ch;
    //cout << tt << endl;

    for(int i = 0; i <= 9; i++) {  /// a 的 值 为 i
        flag[i] = 1;
        dfs(i, 0);
        flag[i] = 0;
    }
    cout << cnt << endl;

    return 0;
}
