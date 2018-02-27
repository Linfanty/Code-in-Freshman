#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#define inf 0x3f3f3f3f
#define maxn 100005
//const int N = 2e5 + 5;
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define N 400
#define maxn 100100
using namespace std;
int t, x;
int mod = 10000000007;

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

int solve(int low)
{
    for(int i = 1; i <= 1e18; ++i)
    {
        cout << 1 << endl << 4 << endl << 1 << endl;

        for(int j = i ; j <= 1e18; ++j)
        {
            low = low * 4;
            cout << low << endl;
            cnt++;

            solve(low);
        }
    }
}

int main ()
{
    //FIN;
    solve(4);
    return 0;
}
