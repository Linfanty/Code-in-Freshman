#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int getSG(int x) {
    if(x == 0)
        return 0;
    if(x % 8 == 0)
        return x - 1;
    if(x % 8 == 7)
        return x + 1;
    return x;
}

int a[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ans ^= getSG(a[i]);/// ***
        }
        if(!ans)
            puts("Second player wins.");
        else
            puts("First player wins.");
    }
}
