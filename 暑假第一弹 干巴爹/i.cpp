#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 1005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<=b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

int n, m;
int a[maxn][maxn];
int dxdy[2][4] = {0,1,0,-1,1,0,-1,0};
int x1, x2;
int y3, y2;
bool vit[maxn][maxn];

struct Node{
    int x, y;
    int di, howmany;
    Node(int xx, int yy, int ddi, int hhowmany)
    {
        x = xx; y = yy;
        di = ddi; howmany = hhowmany;
    }
};

bool check(int xx, int yy, int hh)
{
    if(xx == x2 && yy == y2 && hh <= 3)
        return true;
    else return false;
}

bool bianjie(int xx, int yy)
{
    if( xx < 1 || xx > n || yy < 1 || yy > m || vit[xx][yy])
        return false;
    else return true;

}

bool bfs(int x1,int y1, int x2, int y2)
{
    queue<Node> q;
    q.push(Node(x1, y1, -1, 0));
    memset(vit, false, sizeof(vit));
    vit[x1][y1] = true;

    while(!q.empty())
    {
        Node h = q.front();
        q.pop();

        int xx = h.x, yy = h.y, dd = h.di, hh = h.howmany;
        vit[xx][yy] = true;
        //cout << xx <<' ' << yy << ' ' << hh <<endl;

        if( check(xx, yy, hh) )
        {
            //cout << xx <<' ' << yy << ' ' << hh <<endl;
            return true;
        }

        if(hh > 3)  // //一定不符合，剪枝 剪枝！！！！！！！
            continue;

        rep(i, 0, 3)
        {//dxdy[2][4] = {0,1,0,-1       ,1,0,-1,0};
            int xi = xx + dxdy[0][i];
            int yi = yy + dxdy[1][i];
            //cout << xi << ' ' << yi << endl;

                    if( i != dd && check(xi, yi, hh+1) )
                    {
                        //cout << "1: " << xi <<' ' << yi << ' ' << hh+1 <<endl;
                        return true;
                        break;
                    }
                    else if(i == dd && check(xi, yi, hh))
                    {
                        //cout <<"2: " << xi <<' ' << yi << ' ' << hh <<endl;
                        return true;
                        break;
                    }

            if( bianjie(xi, yi) && a[xi][yi] == 0)
            {
                //cout << xi <<' ' << yi << ' ' << i << " yu "<< dd <<' ' << hh <<endl;
                //if( fei0 ) +1
                //if( shi0 ) no
                if( i != dd  )
                    q.push(Node(xi, yi, i, hh+1));
                else q.push(Node(xi, yi, i, hh));
            }
        }

    }
    return false;
}

int main()
{
    while( cin >> n >> m)
    {
        if( n == 0)
            break;
        rep(i, 1, n)
            rep(j, 1, m)
                cin >> a[i][j];


        int qq;
        cin >> qq;
        rep(i, 1, qq)
        {
            cin >> x1 >> y3 >> x2 >> y2;

            if (x1 == x2 && y3 == y2 )
                cout << "NO" << endl;
            else if( a[x2][y2] != 0 && a[x1][y3] != 0 && a[x1][y3] == a[x2][y2] && bfs(x1, y3, x2, y2) )
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }

    }
}
