#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1) 
const int N = 1e6 + 5;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
int dp[N][22];
int n,m;
int a[N];
//dp[i][j] = max( dp[i][j-1], dp[i+2^(j-1)][j-1])

void rmq_init()
{
    int nn = int(log((double)n)/log(2.0));
    //for(int i = 1; i <=n; i++) dp[i][0] = a[i];
    for(int j = 1; j <= nn; j++)
        for(int i = 1; i+(1<<(j-1))-1 <= n; i++)
            dp[i][j] = min( dp[i][j-1], dp[i+(1<<(j-1))][j-1]);  
}

int rmq(int l, int r)
{
    int k = int(log((double)(r-l+1))/log(2.0));
    //int k = log2(l - r + 1);
    //int k = 0;
    //while((1<<(k+1)) <= r-l+1 )    k++;
    return min(dp[l][k], dp[r-(1<<k) + 1][k] );
}

int main()
{//IO;
    //多组输入输出不能用cincout 用scanf printf
    cin >> n; 
    for(int i = 1; i <= n ; i++)
        //cin >> dp[i][0];
        scanf("%d", &dp[i][0]);
    rmq_init();

    cin >> m;
    int a, b;
    for(int i = 1; i <= m ; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n",rmq(a,b));
        //cin >> a >> b;
        //cout << rmq(a,b) << endl;
    }
    
}