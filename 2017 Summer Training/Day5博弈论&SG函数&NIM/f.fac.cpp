#include<iostream>
#include<cstdio>
#define rep(i,a,b) for(ll i = a; i<b ;++i)
typedef long long ll;
using namespace std;
ll f[55];

int main()
{
    f[0] = 0, f[1] = 1;
    rep(i, 2, 50)
        f[i] = f[i-1] + f[i-2];
    int n, flag;

    while(scanf("%d",&n) != EOF && n)
    {
        flag = 0;
        rep(i, 3, 50)// n>=2
        {
            if (n == f[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag) cout<<"Second win"<<endl;
        else cout<<"First win"<<endl;
    }
}
