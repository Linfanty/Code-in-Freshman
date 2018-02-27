#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
char c[]={'A','H','I','M','O','T','U','V','W','X','Y'};
char s[maxn];

int T,k,n,a[111];

void solve()
{
    ll temp=0;
    int flag=0;

    for(int i = n-1 ; i >= 0; i--)
    {
        // (1 ≤ S ≤ 103).
        temp = 11ll/*LL*/ * temp + 10 - a[ s[i] ];
        cout << "temp: "<< temp << endl;
        if( temp >= k)
        {
            flag = 1;
            break;
        }
    }

    if( !flag  )
    {
        k -= temp + 1;
        cout << "k: "<< k << endl;
        n++;

        for(int i = 0; i < n; i++)
            s[i]='A';
        //如果k比这个差值大就先补成|s|+1个A
        solve();
    }
    else//如果不够那就从最低位开始进位即可
    {
        int up = 0;
        for(int i = 0; i < n; i++)
        {
            up += a[ s[i] ] + k % 11;
            s[i] = c[ up%11 ];
            //cout << "up: " << up <<" up%11 :"<< up%11 << " s[i]: " << s[i] ;
            up /= 11, k /= 11;
            //cout << " up: " << up << " k: " << k << endl;
        }
        for(int i = n-1; i >=0; i--)
            printf("%c",s[i]);

        printf("\n");
    }
}

int main()
{
    for(int i=0;i<11;i++)
        a[ c[i] ] = i;
        /*
        c[i] i
        A 0
        H 1
        I 2
        M 3
        O 4
        T 5
        U 6
        V 7
        W 8
        X 9
        Y 10
        */

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&k,s);

        n = strlen(s);
        for(int i=0,j=n-1; i<j; i++,j--)
            swap(s[i],s[j]);  // 翻转s

        solve();
    }
    return 0;
}
