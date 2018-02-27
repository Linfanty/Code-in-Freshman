#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define maxn 50005
#define memset(a,b) memset(a,b,sizeof(a))
const int N = 100005;
using namespace std;

//struct trie
// {
int ans;
    int tree[maxn *30][3], val[maxn *30], tol;

    void init()
    { memset(tree[0], 0);
        memset(val, 0);
        tol = 1;
        ans = 0;
    }

    void add(string s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); ++i )
        {
            int v = s[i] -'0';
            if( !tree[u][v])
            {
                memset(tree[tol], 0);
                tree[u][v] = tol++;
            }
            u = tree[u][v];
            val[u]+=(i+1);
            ans = max(ans, val[u]);
        }
    }

    int query(string s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int v = s[i] - 'a';
            if( !tree[u][v])
                return 0;
            u = tree[u][v];
        }
        return val[u];
    }
 //}trie;

 int main()
 {
    int t;
    cin >> t;
while( t-- )
{
    init();
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        add(s);
    }
    //cout << val[0] << val[1] <<val[2] << val[3] << val[4] <<endl;
    //0 1 2 3 4 5 6 7 8 9 10 11 12 ...
    //没有不变， 有的话乘以二
        cout << ans << endl;

}
    return 0;
}
