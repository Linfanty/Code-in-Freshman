#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a) memset(a, false, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
#define maxn 40
const int N = 2e5 + 10;
using namespace std;

int w, h, l, n;
char s[15][15];
bool vit[4][15][15];
int dir[2][4] = {0,1,0,-1,1,0,-1,0};
map<ll, int>mp;

struct Node
{
    int x[4], y[4], step;
}st;

bool check( int x, int y)
{
    if(  x < 1 || y < 1 || x > w || y > h  )
        return false;
    return true;
}

int bfs()
{
    queue<Node> q;
    st.step = 0;
    q.push(st);
    mem(vit);

    rep(i, 0, 3)
        vit[i][st.x[i]][st.y[i]]  = 1;
    while( !q.empty())
    {
        Node h = q.front();
        q.pop();
        if( h.step > l)
            continue;

        if( s[h.x[0]][h.y[0]] == 'X' )//1号走到了X
        {
            //cout << "h.step" << h.step;
            return h.step;
        }

        rep(i, 0, n-1)
        {
            int xx = h.x[i] , yy = h.y[i];
            rep(j, 0, 3)
            {
                int xi = xx + dir[0][j];
                int yi = yy + dir[1][j];
                int ff = 1;

                while( check(xi, yi) && s[xi][yi] !='W' )
                {
                    ff = 1;
                    rep(k, 0, n-1)//n个点
                    {
                        if( xi == h.x[k] && yi == h.y[k] )
                        {
                            ff = 0;
                            break;
                        }
                    }
                    if( ff == 0)
                        break;
                    xi += dir[0][j];
                    yi += dir[1][j];
                }
                xi -= dir[0][j];
                yi -= dir[1][j];

                if( xi == xx && yi == yy)
                    continue;

                ll sum = 0;
                rep(k, 0, n-1)  // 状态压缩
                {
                    if( k == i)
                    {
                        sum *= 10;
                        sum += xi;
                        sum *= 10;
                        sum += yi;
                    }
                    else
                    {
                        sum *= 10;
                        sum += h.x[k];
                        sum *= 10;
                        sum += h.y[k];
                    }

                }
                if( mp[sum] )
                    continue;
                mp[sum] = 1;
                //cout <<xi <<' ' << yi << endl;

                Node node ;
                rep(k, 0, n-1)
                {
                    node.x[k] = h.x[k];
                    node.y[k] = h.y[k];
                }
                node.x[i] = xi;
                node.y[i] = yi;
                node.step = h.step+1;
                //cout << i << ' ' << xi << ' ' << yi << ' '<< !i << ' ' << h.x[!i] << ' ' << h.y[!i] <<endl;
                q.push(node);
            }
        }
    }
    return -1;
}

int main()
{//IO;
    cin >> n >> h >> w >> l;
        rep(i, 1, w){
            rep(j, 1, h){
                cin >> s[i][j];
                    if( s[i][j] >= '1' && s[i][j] <= '4' )
                        st.x[ s[i][j] -'1' ] =  i, st.y[  s[i][j] -'1'] = j;
            }
        }

        int aa = bfs();

        if( aa == -1)
            cout << "NO SOLUTION" <<endl;
        else cout << aa << endl;
}
