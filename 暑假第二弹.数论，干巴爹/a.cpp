#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
const int  maxn =  20000005;
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,true,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;

bool isprime[maxn];
ll mark[maxn], prime[maxn], cnt = 1, cc = 1;

void foo()
{
    mem(isprime);
    prime[0] = 0;
    prime[1] = 2;

    for(ll i = 2; i < maxn; i++)
    {
        if( isprime[i])
        {
            //cout << i << ' ';
            prime[cnt] = i;//cnt返回小于n的素数的个数
            if( prime[cnt] - prime[cnt-1] == 2)
                mark[cc++] = prime[cnt];
            cnt++;
        }

        for(ll j = 1; j <= cnt; j++) //j < cnt
        {
             if( i*prime[j] >= maxn ) break;
             isprime[ i*prime[j] ] = false;//找到的素数的倍数不访问
             if( i%prime[j] == 0 ) break;//关键
             //prime数组 中的素数是递增的,当 i 能整除 prime[j]，那么 i*prime[j+1]
             //这个合数肯定被 prime[j] 乘以某个数筛掉
             //prime[j]必定是prime[j]*i的最小因子

        }
    }
}


ll n;
int main()
{
    foo();

    while( cin >> n)
    {
        if(n == 1)
            cout <<"(3, 5)"<<endl;
        else
        cout <<'(' << mark[n+1] - 2 <<", "<< mark[n+1] <<')'<< endl;
    }
    /*
(3, 5)
(5, 7)
(11, 13)
(17, 19)
    */


}
