#include <cstdio>
#include <iostream>

using namespace std;
int m[] = {23, 28, 33};
int a[3];

int exgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exgcd(b, a%b, x, y);
    int res = x;
    x = y;
    y = res - a/b*y;
    return gcd;
}

// 计算 x = a[i] mod m[i], 一共len个方程
int china(int a[], int m[], int len) {
    int M = 1;
    int ans = 0;
    for(int i = 0; i < len; i++) {
        M *= m[i];
    }
    for(int i = 0; i < len; i++) {
        int w = M/m[i];
        int x, y;
        exgcd(w, m[i], x, y);
        ans += w*x*a[i];
        ans %= M;
    }
    return ans;
}
//  ans + M*t > d
//  t > (d - ans)/M
int main() {
    int d, T = 0;
    while(cin >> a[0] >> a[1] >> a[2] >> d) {
        if(a[0] == -1 && a[1] == -1 && a[2] == -1 && d == -1) break;
        int ans = china(a, m, 3);
        int M = 23*28*33;
        int t;
        if(d - ans >= 0) t = (d - ans)/M + 1;
        else t = 0;
        ans = ans + M*t - d;
        cout << "Case " << ++T << ": the next triple peak occurs in " << ans << " days." << endl;

    }
    return 0;
}
