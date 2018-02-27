#include<iostream>
#include<cstdio>
#define rep(i,a,b) for(ll i = a; i<b ;++i)
typedef long long ll;
using namespace std;

int t, n, m;
int main() {
    int i, j;
    scanf("%d", &t);
    while(t--) {
        int temp;
        scanf("%d%d", &n, &m);

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
                scanf("%d", &temp);

        if(temp == 1)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}
