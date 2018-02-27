#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 1000000005;

int num[5005];

int solve(int l, int r, int k) {
        int Min = MAX;

        if (l == r) return 1;


        for (int i = l; i <= r; ++i) {
                Min = min(Min, num[i] - k);
        }
        cout<< Min << ' ' << k <<endl;


        int ans = 0;
        for(int i = l; i <= r; i++){
                if (num[i] - k > Min) {
                        int ll = i, rr = i + 1;

                        while (rr <= r && num[rr] - k > Min) ++rr;
                        --rr;

                        ans += solve(ll, rr, Min + k);
                        i = rr + 1;
                }
        }

        return min(r - l + 1, Min + ans);
}

int main() {

        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
                scanf("%d", &num[i]);

        printf("%d\n", solve(1, n, 0));

        return 0;
}
