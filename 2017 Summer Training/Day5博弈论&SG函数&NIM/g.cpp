#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    ll a=n/k;
    if(a%2==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
