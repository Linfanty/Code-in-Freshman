//bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define FIN freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;

const int N = 200000+5;
ll a[N];

struct Node{
    ll num, cnt;
    Node(int _num, int _cnt){
        num = _num;
        cnt = _cnt;
    }
};

ll n, k;

bool vis[N*2];

int bfs(){
    queue <Node> Q;
    memset(vis, false, sizeof(vis));

    Q.push(Node(n, 0));

    while(!Q.empty()){
        Node h = Q.front();
        Q.pop();
        int numm = h.num, ct = h.cnt;

        if(numm == k){
            //cout << ct << endl;
            return 1;
        }

        if(vis[numm])   continue;
        vis[numm] = true;

        for(ll i = 0 ; i < n ; i++)
            Q.push(Node(numm + a[i], ct+1));
        }
        return 0;
}

int main()
{
    cin >> n >> k;
    {
        for(ll i = 0 ; i < n ; i++)
        cin >> a[i] ;

        if(bfs())
        cout <<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
