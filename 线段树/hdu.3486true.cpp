#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int maxn=200010;  
int dp[20][maxn];//dp[i][j]表示从第j个元素开始，连续的2^i个元素中的最大值  
int a[maxn],n,m;  
int lg[maxn];//lg[i]求表示2^t=i,lg[i]=floor(t);  
void init()  
{  
    int i,j,t;  
    lg[0]=-1;  
    for(i=1;i<maxn;i++)  
        lg[i]=lg[i/2]+1;  
    for(i=1;i<=n;i++)  
        dp[0][i]=a[i];  
    for(i=1;i<=lg[n];i++)  
    {  
        t=n+1-(1<<i);//注意dp[i][j]求得是[j,j+(1<<i)-1],所以要+1  
        for(j=1;j<=t;j++)  
            dp[i][j]=max(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);  
    }  
}  
int rmq(int l,int r)  
{  
    int t=lg[r-l+1];  
    return max(dp[t][l],dp[t][r-(1<<t)+1]);  
}  
int find(int x,int y)  
{  
    int i,ans=0;  
    for(i=1;i<=y;i++)  
    {  
        ans+=rmq((i-1)*x+1,i*x);  
        if(ans>m)return ans;  
    }  
    return ans;  
}  
/*int get_in() 
{ 
    int ans=0; 
    char ch; 
    while((ch=getchar())==' '||c=='\n'); 
    ans=ch-'0'; 
    while((c=getchar())<='9'&&c>='0') 
        ans=ans*10+ch-'0'; 
    return ans; 
}*/  
int main()  
{  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        if(n<0&&m<0)break;  
        int i,j,k,p=0,q=0;  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            if(a[i]>p)p=a[i];  
            q+=a[i];  
        }  
        if(p>m){printf("1\n");continue;}  
        if(q<=m){printf("-1\n");continue;}  
        init();  
        int l=1,r=n,mid,t;  
        int ans=0;  
        while(l<=r)  
        {  
            mid=(l+r)/2;  
            t=find(n/mid,mid);  
            if(t>m)  
            {  
                r=mid-1;  
                ans=mid;  
            }  
            else  
                l=mid+1;  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
