#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 10005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

string s;
int t, q[maxn];
vector <int> ans[maxn];

void outPut(int p)
{
    if( ans[p].size() == 0)
        cout << p << ' ' << s[p] ;
    else
    {
        cout << 'x';
        rep(i, 0, 3)
        {
            int v = (i+2)%4;
            outPut( ans[p][v] );
            // outPut( ans[0][2] = 3 )
            // outPut( ans[0][3] = 4 )
            // outPut( ans[0][0] = 1 )
            // outPut( ans[0][1] = 2 )
            /************************/
            // outPut( ans[0][2] = 3 x ) 输出 x

            // outPut( ans[3][2] = 6 b ) 输出 b
            // outPut( ans[3][3] = 7 w ) 输出 w
            // outPut( ans[3][0] = 4 w ) 输出 w
            // outPut( ans[3][1] = 5 b ) 输出 b

            // outPut( ans[0][3] = 8 b ) 输出 b
            // outPut( ans[0][0] = 1 b ) 输出 b
            // outPut( ans[0][1] = 2 w ) 输出 w
            // 结束！
        }
    }
}

void solve()
{
    int top = 0;
    rep(i, 0, s.size()-1)
    // xbwwb
    // xbwxwbbwb
    {
        if( top && ans[ q[top-1] ].size() == 4)
            top--;
            //top = 1 退栈

        if( s[i] == 'x')
        {
            if( top )
                ans[ q[top-1] ].push_back(i);
                /****************************/
                // ans[ q[0] ] ans[0][2] = 3 x

            q[ top++ ] = i;
            //q[0] = 0 top = 1
            /****************/
            //q[0] = 0 top = 1
            //q[1] = 3 top = 2

        }
        else
        {
            if( top )
                ans[ q[top-1] ].push_back(i);
                // ans[ q[0] ] ans[0][0] = 1
                // ans[ q[0] ] ans[0][1] = 2
                // ans[ q[0] ] ans[0][2] = 3
                // ans[ q[0] ] ans[0][3] = 4
                /**************************/
                // ans[ q[0] ] ans[0][0] = 1 b
                // ans[ q[0] ] ans[0][1] = 2 w

                // ans[ q[1] ] ans[3][0] = 4 w
                // ans[ q[1] ] ans[3][1] = 5 b
                // ans[ q[1] ] ans[3][2] = 6 b
                // ans[ q[1] ] ans[3][3] = 7 w
                //ans[ q[top-1] ].size() == 4 退栈

                // ans[ q[0] ] ans[0][3] = 8 b

        }
    }
    outPut(0);
    cout <<  endl;
}

void init()
{
    cin >> t;
    int w = 0;
    while( t-- )
    {
        rep(i, 0, maxn-1)
            ans[i].clear();
        cin >> s;
        cout << "Case #" << ++w << ":" << endl;
        solve();
    }
}

int main()
{
    init();
}
