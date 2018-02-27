#include <bits/stdc++.h>
#define lid (id << 1)
#define rid (id << 1 | 1)
const int N = 1005;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i = a; i<=b ;++i)
using namespace std;
int dp[N][1005], len;
int n,m;
char s[1005];

//dp[i][j] = max( dp[i][j-1], dp[i+2^(j-1)][j-1])
int MIN(int x, int y)
{
    return s[x] <= s[y] ? x : y;
}

void rmq_init()
{
    int nn = int(log((double)len)/log(2.0));

    for(int i = 0; i < len; i++) dp[i][0] = i; //初始化为i

    for(int j = 1; j <= nn; j++)
        for(int i = 0; i+(1<<(j-1))-1 <= len; i++)
            dp[i][j] = MIN( dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}

int rmq(int l, int r)
{
    int k = int(log((double)(r-l+1))/log(2.0));
    //int k = log2(l - r + 1);
    //int k = 0;
    //while((1<<(k+1)) <= r-l+1 )    k++;
    return MIN(dp[l][k], dp[r-(1<<k) + 1][k] );
}


int main()
{
    while( scanf("%s %d", s, &m)!=EOF )
    {
        len = strlen(s);
        rmq_init();
        m = len - m;

        int pos = 0, num = 0;
        char ans[1005];

        while( m-- ) // m == 0 : 计算完整个字符串
        {
            cout << pos << " dao " << len-m-1 <<"  ";
            pos = rmq(pos, len-m-1);
            cout << pos << endl
            //从A[1]、A[2]、……、A[n] n个数中选出n-m个数使最小
            //0 开始到m位置中最小
            //pos+1开始到m+1
            //pos+1开始到m+2
            //pos+1开始到m+3

            ans[num++] = s[pos++];
        }
        int i;
        for(i = 0; i < num; i++)
            if(ans[i] != '0')
                break;
        if( i == num)
            printf("0\n");
        else
        {
            while( i < num)
                printf("%c",ans[i++]);
            printf("\n");
        }
    }
    return 0;
}
