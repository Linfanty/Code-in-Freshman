#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int n, x[maxn], y[maxn];
vector<int> data[maxn];
int node[maxn][500];
bool active[maxn];
int yinzi[maxn];
bool isyinzi[maxn];
int sz;

void init1()
{
    sz = 0;
    memset(isyinzi, true, sizeof(isyinzi));

    rep(i, 1, maxn)
    {
        if( isyinzi[i] )
            for(int j = 2*i; j <= maxn; j += i)
            {
                node[ j ][ ++node[ j ][0]  ]= i;
                isyinzi[i] = 0;
            }
    }
/*
    rep(i, 1, maxn)
        node[ i ][ ++node[ i ][0]  ]= i;

    rep(i,0,30)
        cout << node[10000][i] << ' ';
*/
}


//1 2 4 5 8 10 16 20 25 40 50 80 100
//125 200 250 400 500 625 1000 1250 2000 2500 5000 10000

/*
void query1(int ii, int xx, int yy)
{
    rep(j, ii-yy, ii-1)
    {
         rep(q, 1, node[ x[j] ][0])

    }
}
*/


void query(int ii, int xx, int yy)
{
    rep(j, ii-yy, ii-1) //2 - 3
    {
        rep(q, 1, node[ x[j] ][0])  // 1
        {
            rep(k, 1, node[xx][0])  // 1
            {
                if(  node[ x[j] ][q] % node[xx][k]  == 0)
                    active[ node[xx][k] ] = 0;
            }

        }
    }
    int sum = 0;
    rep(j, 1, xx)
        if( active[j] )
            sum++;

    cout << sum  << endl;
}

void init()
{
    init1();
    cin >> n;
    rep(w, 1, n)
    {
        cin >> x[w] >> y[w];
        mem( active );
        rep(i, 1, node[ x[w] ][0])
            active[i] = 1;
        /*
        int fina = x[w]*sqrt( x[w]);
        rep(i, 1,  fina)
        {
            if( x[w]%i == 0 )
            {
                node[ x[w] ][ ++node[ x[w] ][0]  ]= i;
                active[i] = 1;
            }
        }
        node[ x[w] ][ ++node[ x[w] ][0]  ] = x[w];
        active[ x[w] ] = 1;

        */

        /*
        rep(i, 0, 23)
            cout << node[ x[w] ][i] << ' ';
            cout << endl;
        */
        query(w, x[w], y[w]);
    }
}




int main()
{
    init();
}
