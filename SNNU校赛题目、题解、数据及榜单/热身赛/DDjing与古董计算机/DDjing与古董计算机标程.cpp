#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    char s[15];
    scanf("%s",s);
    getchar();
    printf("Hello %s\n",s);
    char o;
    long long n,m;
    while(~scanf("%c %lld %lld",&o,&n,&m))
    {
        if(o=='M')
            printf("%lld\n",n*m);
        else if(o=='D')
            printf("%.2lf\n",(double)n/m);
    }
    return 0;
}
