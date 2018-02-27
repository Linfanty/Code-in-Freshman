#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define repp(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 200100;

ll a[maxn], n, m, sum[maxn];

int main()
{
     while(scanf("%I64d",&n)!=EOF)
     {
        repp(i, 1, n)
            scanf("%I64d",&a[i]);

        sort(a+1,a+1+n);
        sum[0]=0;
        repp(i, 1, n)
            sum[i]=sum[i-1]+a[i];
        ///求前缀和
        ///特殊情况1 2
        if(n==1 || n==2){
            printf("1\n");
            printf("%I64d\n",a[1]);continue;
        }

        ll l,r,d,m1,m2,t1,t2;
        ll mid=1,len=0,zong=0;
        ll zong1,mid1,len1;

        repp(i, 2, n-1)
        {
/////三分区间长度 ,i表示中位数位置,l和r表示len的长度范围
            l=1;
            r=min(i-1,n-i);

            /// 三分
            repp(j, 1, 100)
            {
                m1=(2*l+r)/3;
                m2=(l+2*r+2)/3;

                t1=sum[i]-sum[i-m1-1]+sum[n]-sum[n-m1];
                t2=sum[i]-sum[i-m2-1]+sum[n]-sum[n-m2];

                if(t1*(2*m2+1) < t2*(2*m1+1)) /// cal计算比较哪个更接近
                {
                    l=m1+1;  /// 左 = mid
                }
                else r=m2-1; /// 右 = midmid
            }

            zong1=sum[i]-sum[i-l-1]+sum[n]-sum[n-l]-(2*l+1)*a[i];
            len1=l;
            mid1=i;

            if(zong1*(2*len+1) > zong*(2*len1+1) )
            {
                zong=zong1;
                len=len1;
                mid=mid1;
            }
        }

        printf("%I64d\n",len*2+1);
        int flag=1;

        repp(i, mid-len, mid)
            if(flag)
                flag=0, printf("%I64d",a[i]);
            else
                printf(" %I64d",a[i]); ///mid - len 到 mid 都选

        repp(i, n-len+1, n) ///n - len + 1 到 n 都选
            printf(" %I64d",a[i]);

        printf("\n");
    }
}
