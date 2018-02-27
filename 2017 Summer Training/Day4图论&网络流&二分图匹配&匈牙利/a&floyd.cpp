#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdpio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 65;
#define N 1005
int n;
int m;
float a[N][N];
float dp[N][N], ans;
int i, j, k, s, t;

void floyd(){

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=a[i][j];

	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(dp[i][j]<dp[i][k]*dp[k][j])
					dp[i][j]=dp[i][k]*dp[k][j]; ///
}

int main() {

    while(scanf("%d",&n)!=EOF) {

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%f",&a[i][j]);

        floyd();
        scanf("%d",&m);

        for(i=0;i<m;i++) {
            scanf("%d%d",&s,&t);
            ans = dp[s-1][t-1];

            if(ans==0)
                printf("What a pity!\n");
            else
                printf("%.3f\n",ans);
        }
    }
}
