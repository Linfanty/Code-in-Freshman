#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

int dp[30][30];
int ans[] = {0,0,0,4,6,0,0,
12,
40,
0,
0,
171,
410,
0,
0,
1896,
5160,
0,
0,
32757,
59984,
0,
0,
431095,
822229,
0};

int cnt = 0;

void dabiao(int n)
{
    if( n > 24) return ;
    /*
    for(int p = 1; p <= 25; p++)
    {

        for(int i = 1; i <= p; i ++)
        {
            for(int j = 1; j <= i; j++)
                dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];

        }
    }
    */
    for(int i = 0; i <=1; i++)  // 每一位 非0即1 第一遍都为0 第二次遍历换成1
    {
        dp[1][n] = i;
        cnt += i;

        for(int j = 2; j <= n; j++)
        {
            dp[j][n-j+1] = dp[j-1][n-j+1] ^ dp[j-1][n-j+2];
            cnt += dp[j][n-j+1];
        }
        if( cnt*2 == n*(n+1)/2 )
            ans[n]++;

        dabiao(n+1);
        //恢复全局变量
        //回溯部分
        cnt -= i;

        for(int j = 2; j <= n; j++)
        {
            dp[j][n-j+1] = dp[j-1][n-j+1] ^ dp[j-1][n-j+2];
            cnt -= dp[j][n-j+1];
        }

    }
}

int main()
{
    dabiao(24);
    cout << ans[24];
    int x;
    while( cin >> x)
    {//for(int i = 1; i <= 25; i++)
        if( x == 0)
            break;
        cout << x << ' ' <<  ans[x] << endl;
    }
}

