#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1) 
#define maxn 100005
#define memset(a,b) memset(a,b,sizeof(a))  
const int N = 100005;
using namespace std;

//struct trie
// {
    int tree[maxn *33][30], val[maxn *33], tol;
    void init() 
    { memset(tree[0], 0);   
        memset(val, 0);
        tol = 1;
    }
    void add(string s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); ++i )
        {
            int v = s[i] -'a';
            if( !tree[u][v])
            {
                memset(tree[tol], 0);
                tree[u][v] = tol++;
            }
            u = tree[u][v];
            val[u]++;
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
    init();
    int n, m;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)   
    {
        cin >> s;
        add(s);
    }
    cin >> m;

    for(int i = 0; i < m ; i++)
    {
        cin >> s;
         cout << query(s) << endl;

    }
    return 0;
 }