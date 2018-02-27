#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1) 
const int N = 2e5 + 5;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
int dp[N][30];
int n,m;
int a[N];
//dp[i][j] = max( dp[i][j-1], dp[i+2^(j-1)][j-1])

void rmq_init()
{
    int nn = int(log((double)n)/log(2.0));
    //for(int i = 1; i <=n; i++) dp[i][0] = a[i];
    for(int j = 1; j <= nn; j++)
        for(int i = 1; i+(1<<(j-1))-1 <= n; i++)
            dp[i][j] = max( dp[i][j-1], dp[i+(1<<(j-1))][j-1]);  
}

int rmq(int l, int r)
{
    int k = int(log((double)(r-l+1))/log(2.0));
    //int k = log2(l - r + 1);
    //int k = 0;
    //while((1<<(k+1)) <= r-l+1 )    k++;
    return max(dp[l][k], dp[r-(1<<k) + 1][k] );
}

bool check( int len, int t)//n/mid 一次选的人数, mid 要选多少人 
{
    int sum = 0;
    for(int i = 1; i <= t; i++)
    {
        sum += rmq((i-1)*len + 1, i*len);
        if(sum > m)
            return true;
    }
    return false;
}

int main()
{//IO;
    //多组输入输出不能用cincout 用scanf printf
while( scanf("%d %d", &n, &m)!=EOF )
{ 
    if(n == -1 || m == -1)
        break;

    // m 最低能量值
    int sum = 0;
    int max1 = 0;
    for(int i = 1; i <= n ; i++)
    {
         scanf("%d", &dp[i][0]);
         sum += dp[i][0];
         if(dp[i][0] > max1)
            max1 = dp[i][0];
    }   
    
    if( max1 > m)
    {
        printf("1\n");
        continue;   
    }
    if( sum <= m)
    {
        printf("-1\n");
        continue;
    }
    
    rmq_init();
    int l = 1;
    int r = n;
    int ans = 0;

    while( l <= r)
    {
        int mid = (l+r) >> 1;
        if( check(n/mid, mid))
        {
            //check(5/4,4);
        //n/mid 一次选的人数, mid 要选多少人 
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d\n",ans);
        //scanf("%d %d", &a, &b);
        //printf("%d\n",rmq(a,b));

    }   
    return 0;
}