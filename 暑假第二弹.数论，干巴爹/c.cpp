#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

//2,147,483,647
ll n;
const int N=4e6+10;
//˼·����f(n) = gcd(1, n) + gcd(2, n) + ... + gcd(n - 1, n).
//�����Ļ����Ϳ��Եõ�����ʽS(n) = f(2) + f(3) + ... + f(n) ==> S(n) = S(n - 1) + f(n);.

//��g(n, i)����ʾ����gcd(x, n) = i�ĸ���������f(n) = sum{i * g(n, i)}
//��ô��g(n, i),gcd(x, n) = i���������Ϊgcd(x / i, n / i) = 1,
//���ֻҪ���ŷ������phi(n / i)���Ϳ��Եõ���x / i���ʵĸ������Ӷ����gcd(x , n) = i�ĸ���

int phi[N];
ll f[N];

void getphi()
{
    for(int i=1;i<N;i++)
        phi[i]=i;

    for(int i=2;i<N;i++)
    {
        if(phi[i]==i)
            for(int j=i;j<N;j+=i)
                phi[j]=phi[j]-phi[j]/i;

        for(int j=1;j*i<N;j++)
            f[j*i]+=j*phi[i];

        //for(int j = i*2; j<N; j+=i)
        //    f[j] += phi[j / i]* i;
    }
}

int main()
{

    getphi();
    //rep(i, 1, 20)
    //    cout <<  phi[i] << ' ';
    while( cin >> n)
    {
        if( n == 0)
            break;
        ll g = 0;

        rep(i, 1, n)
            g += f[i];

        //rep(i, 1, n)
        //    cout << f[i] << ' ';

        cout << g << endl;

    }
}
