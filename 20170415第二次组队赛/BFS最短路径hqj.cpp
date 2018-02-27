#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, int> PIR;
const int N = 505;

int n, m, G[N][N], dir[4][2] = {0,1,0,-1,1,0,-1,0};
string s;
bool vis[N][N];
struct Node{
    int x, y, cnt, len;
    Node(int _x, int _y, int _len, int _cnt){
        x = _x; y = _y; len = _len; cnt = _cnt;
    }
};
bool judge(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m || vis[x][y])   return false;
    return true;
}
void bfs(){
    queue <Node> Q;
    mem(vis, false);
    Q.push(Node(1, 1, G[1][1], 0));
    vis[1][1] = true;
    
	while(!Q.empty()){
        
		Node h = Q.front();
        
		Q.pop();
        //********
		int xx = h.x, yy = h.y, lenn = h.len, cntt = h.cnt;
        //********
        
		if(xx == n && yy == m){
            cout << cntt << endl;
            return ;
        }
        
        rep(i, 0, 3){
            int xi = xx+dir[i][0]*lenn, yi = yy+dir[i][1]*lenn;
            if(judge(xi, yi)){
                vis[xi][yi] = true;
                Q.push(Node(xi, yi, G[xi][yi], cntt+1));
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return ;
}
int main()
{IO;
    //FIN;
    while(cin >> n >> m){
        rep(i, 1, n){
            cin >> s;
            rep(j, 0, m-1)  G[i][j+1] = (s[j]-'0');
        }
        bfs();
    }
    return 0;
}
