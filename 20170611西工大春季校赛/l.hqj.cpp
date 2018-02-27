#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,sizeof(a),b)
#define FIN freopen("in.txt","r",stdin)
#define pb push_back
typedef long long LL;
typedef pair<int, int> PIR;

const int MAXN = 1e4+5;

int T, q[MAXN];
string s;
vector <int> ans[MAXN];

void outPut (int p)
{
    if (ans[p].size() == 0) cout << s[p];
    else
        {
        cout << "x";
        for (int i = 0; i < 4; ++i) {
            int v = (i+2)%4;
            outPut(ans[p][v]);
        }
    }
    return ;
}

int main ()
{
    //FIN;
    cin >> T;
    int w_w = 0;

    while (T--)
        {
        for (int i = 0; i < MAXN; ++i) ans[i].clear();
        cin >> s;
        cout << "Case #" << ++w_w << ":" << endl;


        int top = 0;
        for (int i = 0; i < s.size(); ++i)
            {
            if (top && ans[q[top-1]].size() == 4) top--;

            if (s[i] == 'x') {
                if (top) ans[q[top-1]].pb(i);
                q[top++] = i;
            }

            else {
                if (top) ans[q[top-1]].pb(i);
            }
        }
        outPut(0);
        cout << endl;
    }
    return 0;
}
