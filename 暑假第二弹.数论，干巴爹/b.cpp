#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define inf 0x3f3f3f3f
const int maxn = 50005;
const int N  = 1000005;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

//2,147,483,647
ll l, u;
ll prime[maxn], pprime[1000005];
bool isprime[maxn];
ll cnt = 0, t, tmp;

void init()
{
    memset(isprime, 0, maxn);
    rep(i, 2, maxn)
    {
        if( !isprime[i] )
            prime[cnt++] = i;

        for(ll j = i; j <= maxn; j += i)
            isprime[j] = 1;
    }

}

void ininab()
{

}

int main()
{
    init();
    while( cin >> l >> u )
    {
        if( l < 2 ) l = 2;
        t = 0;
        memset(isprime, 1, maxn);

        for(ll i = 0; i < cnt &&
        prime[i] * prime[i] <= u; i++ )
        {
            ll tep = l/prime[i] * prime[i];
            if(tmp < l)
                tmp += prime[i];
            if(tmp == prime[i] )
                tmp += prime[i];
            for(ll j = tmp; j <= u; j+=prime[i])
                isprime[j-l] = 0;
        }

        for(ll i = 0; i < u-l; i++)
            if( isprime[i] )
                pprime[ t++ ] = i+l;

        ll p = 1, q = 1;
        if( t < 2)
            cout<<"There are no adjacent primes."<<endl;
        else
          {
               for(ll i = 1; i < t; i++)
               {
                    if(pprime[i] - pprime[i-1] < pprime[p] - pprime[p-1])
                         p = i;
                    if(pprime[i] - pprime[i-1] > pprime[q] - pprime[q-1])
                         q = i;
               }
               cout<<pprime[p-1]<<","<<pprime[p]<<" are closest, "<<pprime[q-1]<<","<<pprime[q]<<" are most distant."<<endl;
          }

    }
}
