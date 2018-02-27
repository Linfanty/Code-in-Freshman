#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i <= b; ++i)
#define per(i,a,b) for(ll i = a; i >= b; --i)
#define max3(a,b,c) max(a,max(b, c))
int dp[100005][15];

int main()  {
    int x, t, n;
    while( scanf("%d", &n) && n )
    {
        memset(dp, 0, sizeof(dp));
        int max_time = 0;

        rep(i, 0, n-1){
            scanf("%d %d", &x, &t );
            dp[t][x+1]++ ;
            max_time = max(max_time, t);

        }

        per(i, max_time, 0) /// ������ʱ��������ǰ����
            rep(j, 1, 11) /// �����ڵ�����(����1m)����ԭ�ز�����ȡһ�����ֵ
                dp[i][j] += max3(dp[i+1][j-1],
                        dp[i+1][j], dp[i+1][j+1] ), cout << i << ' ' << j << ' ' << dp[i][j] << endl;

        /// �����ۼӵ�tΪ0Ϊֹ
        printf("%d\n", dp[0][6] );
/// ��������ʱ��ҲӦ�����6�Ǹ�λ��(�൱��5)
    }

}
