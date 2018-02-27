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
    int tree[maxn *33][30], val[maxn *33], tol, isEnd[maxn];
    void init() 
    { memset(tree[0], 0);   
        memset(val, 0);
        //memset(isEnd , 0 , sizeof(isEnd));
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
        }
        val[u] = 1; //唯一的变化点 终止点
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
    //freopen("in.txt","r",stdin);
    init(); 
    string line[100005];
    int i = 0;
    while( getline(cin, line[i]))
    {
        add(line[i]);
        i++;
    }
    int n = i ;
    //cout  << n;
    for(int j = 0; j < n ; j++)
    {
        int len = line[j].size();
        //cout << line[j] <<"xxxx";
        for(int i = 1; i < len; i++)
        {
            //cout << line[j].substr(0,i) << ' ' <<line[j].substr(i,len-i) << endl;
            //ABCD
            if( query( line[j].substr(0,i) ) == 1  && query( line[j].substr(i,len-i)) == 1 )
            {
                cout << line[j] << endl;
                break;
            }
        }
        
    }
    //cout <<  query("b") << ' ' << query("c") << ' ' << query("bc");
    //b : 2  c :1
    //b
    //bc
    //c
}