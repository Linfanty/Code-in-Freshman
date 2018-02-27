#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
const int manx = 10005;
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

struct node
{
    string name;
    int st, ed, num;
    bool
    //string pe[105];
}node[maxn];

string ss;
set<string> s;

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
            cin >> node[i].name >> node[i].st >> node[i].ed >> node[i].num;
            rep(j, 1, node[i].num)
            {
                cin >> ss;
                s.insert( ss );
            }
        }

        set<string> :: iterator it;

        for(it = s.begin(); it != s.end(); it++ )
        {
            rep(k, 1, node[j].num )
            {
                if(node[i].)
                if( (node[i].st <=  node[j].ed && node[i].st >= node[j].st) || (node[i].ed <=  node[j].ed && node[i].ed >= node[j].st)   )
                {
                    node[i].
                }
            }

        }

    }
}
