#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

ll n, m;
int flag;

bool check(int noww)
{
    if( noww <= n && noww >= 1)
        return true;
    else return false;
}

bool dfs(int now, int step)
{
    //cout << now << ' ' << m << endl;
    if(now == m)
    {
            flag = 1;
            return true;
    }

    if( check(now))
    {
        //cout << now << ' ' << m << endl;
        dfs(now+step*2-1, step+1);
        dfs(now-step*2+1, step+1);
        //cout << now << ' ' <<  step << endl;
    }
    return false;
}

int main()
{
    while( cin >> n >> m)
    {
        flag = 0;

        if( n == 0)
            break;
        if( n>= 50)
        {
            cout << "Let me try!" << endl;
            continue;
        }

        dfs(1, 2);
        if( flag == 0)
         cout << "Don't make fun of me!"<<endl;
         else cout << "Let me try!" << endl;
    }

}
