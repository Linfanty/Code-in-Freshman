#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll poww(ll a, ll b, ll p)//mod p
{
    ll ans = 1;
    while( b )
    {
        if( b&1 != 0)
        {
            ans *= a;
            ans %= p;
        }
        a = a%p * a%p;
        b >>= 1%p;
    }
    return ans;
}

int main()  {
    //char s[100010];
    string s;
    ll mod = 1000000007;
    ll sum, len, m = 1000000007   - 1;
    while( cin >> s )   {
        len = s.size();
        sum = 0;
        for(int i = 0; i < len; i++)
            sum = sum * 10 + (s[i]-'0'), sum = sum % m;
        /// 求 2^（n-1）%（1e9+7）
/// （n-1）对(MOD-1)取余 设余数为K 因为2^（MOD-1）%MOD =1
/// 题目即求2^K %MOD
        cout << poww(2, sum-1, mod) << endl;
    }
}




