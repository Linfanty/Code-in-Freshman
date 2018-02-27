#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
const int maxn = 10005;
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

struct Node
{
    int st, ed;
    string pe;
     bool operator < (const Node &a) const // 重载“<”操作符，自定义排序规则
    {
        //按score由大到小排序。如果要由小到大排序，使用“>”即可。
        return a.st < st;
    }
}node;

set <Node> s;

string ss;
string sss;
set<Node> :: iterator it;
int num, a, b;

int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        int n, cnt = 0;
        cin >> n;
        rep(i, 1, n)
        {
            cin >> ss >> node.st >> node.ed >> num ;
            rep(j, 1, num)
            {
                cin >> ss;
                node.pe = ss;
                it = s.begin();
//                if( s.find( ss ) != s.end() )
                {
                    //if( (*it).st < node.st &&  )
                    cout << (*it).st << ' ' <<  node.st << ' ';
                }
                s.insert( node );
            }
        }



        for(it = s.begin(); it != s.end(); it++ )
        {
            cout << (*it).st << endl;
        }

    }
}
