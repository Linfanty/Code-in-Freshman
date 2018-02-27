#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 2000006
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

ll p;
int vit[maxn];
int sum[maxn];

int main()
{
    cin >> p;
    rep(i, 0, maxn-1)
    {
         vit[i] = -1;
         sum[i] = 0;
    }

    rep(i, 0, p-1)
    {
        vit[ (i%p*i%p) % p ]++ ;
        if( (i%p*i%p)%p != 0  )
            sum[ (i%p*i%p)%p ] = i;
    }

    if( vit[0] != -1)
            cout << sum[0];
    else cout << -1 ;

    rep(i, 1, p-1)
    {
        if( vit[i] != -1)
            cout <<  ' ' << sum[i] ;
        else cout << ' ' << -1 ;
    }


}
