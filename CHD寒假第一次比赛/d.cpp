#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c),a+b+c)
    {
        a/=gcd(b,c);
        if(a&1)printf("NO\n");  //等效于a%2==0/1  
								//但是a%2的效率要低一些 没有&运算快
        else printf("%d\n",a-1);
    }
    return 0;
}
