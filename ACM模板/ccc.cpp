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
typedef long long LL;

const int N = 100000+5;
struct Node{
    int num, cnt;
    Node(int _num, int _cnt){
        num = _num;
        cnt = _cnt;
    }
};

int n, k;
bool vis[N*2];
void bfs(){
    queue <Node> Q;
    memset(vis, false, sizeof(vis));

    Q.push(Node(n, 0));
    while(!Q.empty()){
        Node h = Q.front();
        Q.pop();
        int numm = h.num, ct = h.cnt;

        if(numm == k){
            cout << ct << endl;
            return ;
        }
        if(vis[numm])   continue;
        vis[numm] = true;

        if(numm >= 1){          //数据范围内，【否则越界】
            Q.push(Node(numm-1, ct+1));
        }
        if(numm < k){           //大于k做了无用功
            Q.push(Node(numm+1, ct+1));
            Q.push(Node(numm*2, ct+1));
        }
    }
}
int main()
{
    while(cin >> n >> k){
        bfs();
    }
    return 0;
}
