#include<bits/stdc++.h>  
using namespace std;  
typedef long long LL;  
  
LL b[300005],a[300005];  
int t,T,n,k;  
  
  
int judge(int m) //检验m个冰淇淋能否做出来  
{  
    for(int i=0;i<m;i++)  
        a[i]=b[i];  
    int p=m;  
    for(int i=m;i<m*k;i++)  
    {  
        while(b[p]<a[i-m]*2 && p<n) p++;  
        if(p==n) return 0;  
        a[i]=b[p];  
        p++;  
    }  
    return 1;  
}  
  
int Bisection(int l,int r)  //二分答案  
{  
    while(l<r)  
    {  
        int mid=(l+r+1)/2;  
        if(judge(mid)) l=mid;  
        else r=mid-1;  
    }  
    return l;  
}  
  
int main()  
{  
    scanf("%d",&T);  
    for(t=1;t<=T;t++)  
    {  
        scanf("%d%d",&n,&k);  
        for(int i=0;i<n;i++) scanf("%lld",&b[i]);  
        sort(b,b+n);  
        printf("Case #%d: %d\n",t,Bisection(0,n/k));  
    }  
    return 0;  
}  