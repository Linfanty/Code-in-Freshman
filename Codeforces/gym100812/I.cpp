#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
const int maxn = 1000005;

ll num[maxn];

//http://blog.csdn.net/qq_31759205/article/details/52224203


typedef long long LL;
LL a[1005], sum[1005], dp[1005];
int main() {
    int n;
    LL d, c;
    // freopen("in.txt","r",stdin);
    while(~scanf("%d%I64d%I64d", &n, &d, &c)) {
        for(int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            sum[i] = sum[i - 1] + a[i]; //ǰi���ͻ�ʱ���ǰ׺�� 2 7 13
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        //����dp,�͵���i������ʱ,���ǵ�i����ǰi-1����������,ȡ������С�����
        //����ǰǰi-1�����������Ѿ�������,��ôdp[i]=min(dp[j]+cost);(cost��j+1,i]һ����ʱ��Ļ���)
        //����[j+1,i]��ÿ����Ʒx,�仨��cost=(a[i]-a[x])*c,��ô�ۼ���������((i-j)*a[i]-(sum[i]-sum[j]))*c
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + ((i - j) * a[i] - (sum[i] - sum[j])) * c + d);
//printf("%d: %I64d %d %d %d \n",i, dp[i],  (i - j) * a[i] ,   (sum[i] - sum[j]) ,(sum[i] - sum[j])*c) ;
            }
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
