#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
char a[N], b[N], c[N], d[N];

int num[30][30];

int main()
{
    //freopen("enchanted.in", "r", stdin);
    //freopen("enchanted.out", "w", stdout);

    scanf("%s %s %s %s", a, b, c, d);
    int n = strlen(a);
    rep(i, 1, n){
        int x = a[i-1] - 'A' , y = b[n-i+1-1] - 'A';
        num[x][y]++;
    }
    int ok = 1;
    rep(i, 1, n){
        int x = c[i-1] - 'A' , y = d[n-i+1-1] - 'A';
            if( !num[x][y] ){
                ok = 0;
                break;
            }
        num[x][y]--;
    }

    if(ok) printf("Yes\n");
    else  printf("No\n");

    return 0;
}
