#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
typedef long long ll;  
ll t,ans,n,m,k,d,x[30],y[30];  
ll lx,rx,ly,ry,xc;  
int c[30];  
ll C(ll a,ll b)
{  
    ll ans=1,c=a-b;  
    if(a==0)return 0;  
    while(a!=c){  
        ans=ans*a;  
        a--;  
    }  
    while(b!=0){  
        ans=ans/b;  
        b--;  
    }  
    return ans;  
}  

int solve(int a)
{  
    lx=n+2;rx=0;  
    ly=m+2;ry=0;  
    d=0;  
    for(int i=0;i<k;i++)  
        if(a&(1<<i)){ 
        //cout << a << ' ' << (1<<i) << ' ' << (a&(1<<i)) << endl;
            if(x[i+1]<lx)lx=x[i+1];  
            if(x[i+1]>rx)rx=x[i+1];  
            if(y[i+1]<ly)ly=y[i+1];  
            if(y[i+1]>ry)ry=y[i+1];  
            d++;  
        }  
    //cout << lx << ly << rx << ry <<endl;
    ll ans1=0,ans2=0;  
    if(lx==rx)
        ans1=n+(lx-1)*(n-rx);  
    else ans1=(lx)*(n-rx+1);  
    
	if(ly==ry)ans2=m+(ly-1)*(m-ry);  
    	else ans2=(ly)*(m-ry+1);  
 	xc = ans1 * ans2;
    //cout << ans1 << ' ' << ans2 << endl;
	if(d%2==1)ans-=xc;  
    	else ans+=xc;  
}  

int main(){  
    scanf("%I64d",&t);  
    c[0]=1;  
    for(int i=1;i<=21;i++)c[i]=c[i-1]*2;  
    while(t--)
	{  
        scanf("%I64d%I64d%I64d",&n,&m,&k);  
        for(int i=1;i<=k;i++)
			scanf("%I64d%I64d",&x[i],&y[i]); 
			 
        ans = C(n+1,2) * C(m+1,2);
		  
        for(int i=1;i<=c[k]-1;i++)
			solve(i);  
			
        printf("%I64d\n",ans);  
    }  
    return 0;  
}  
