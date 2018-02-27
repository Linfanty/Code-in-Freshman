#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define maxn 1005
#define mem(a, b) memset(a, b, sizeof(a))

struct Node {
    int x, y;
    bool flag;
} node[maxn];

double cnt(Node a, Node b) {
	cout<<"AAAAA";
	//cout << "qwe"<< sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));

}

int f[maxn];

int n,d;

int Find(int x) {
    return f[x] == x ? x : f[x] = Find(f[x]);
}

void operate(int x) {
    node[x].flag = true;
    int fx = Find(x);
    for (int i = 1; i <= n; i++){
    		
		cout <<"wty";
		
		cnt(node[i], node[x]);
		
        if (node[i].flag && i != x && cnt(node[i], node[x]) <= d) {
        	//cout << "aaaaa" ;
            int fi = Find(i);
            f[fi] = fx;
        }
    }
}

int main() {
    while (~scanf("%d%d", &n, &d)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &node[i].x, &node[i].y);
            node[i].flag = false;
            f[i] = i;
        }

        char c;
        while (cin >> c) {
            if (c == 'O') {
                int x;
                scanf("%d", &x);
                operate(x);
            } else {
                int a, b;
                scanf("%d%d", &a, &b);
                int fa = Find(a);
                int fb = Find(b);
                printf("%d %d\n",fa,fb);
                if (fa == fb) printf("SUCCESS\n");
                else printf("FAIL\n");
            }
        }
    }
}
