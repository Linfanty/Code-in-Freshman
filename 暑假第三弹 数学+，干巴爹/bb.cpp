#include<stdio.h>  
#define LL __int64  
  
void exgcd(LL a,LL b,LL& d,LL& x,LL& y)  
{  
    if(!b){d=a;x=1;y=0;}  
    else  
    {  
        exgcd(b,a%b,d,y,x);  
        y-=x*(a/b);  
    }  
}  
LL gcd(LL a,LL b)  
{  
    if(!b){return a;}  
    gcd(b,a%b);  
}  
  
LL M[55000],A[55000];  
  
  
LL China(int r)  
{  
    LL dm,i,a,b,x,y,d;  
    LL c,c1,c2;  
    a=M[0];  
    c1=A[0];  
    for(i=1; i<r; i++)  
    {  
        b=M[i];  
        c2=A[i];  
        exgcd(a,b,d,x,y);  
        c=c2-c1;  
        if(c%d) return -1;//c一定是d的倍数，如果不是，则，肯定无解  
        dm=b/d;  
        x=((x*(c/d))%dm+dm)%dm;//保证x为最小正数//c/dm是余数，系数扩大余数被  
        c1=a*x+c1;  
        a=a*dm;  
    }  
    if(c1==0)//余数为0，说明M[]是等比数列。且余数都为0  
    {  
        c1=1;  
        for(i=0;i<r;i++)  
            c1=c1*M[i]/gcd(c1,M[i]);  
    }  
    return c1;  
}  
int main()  
{  
    int n;  
  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
        {  
            scanf("%I64d%I64d",&M[i],&A[i]);  
        }  
        if(n==1){ printf("%I64d\n",A[0]);continue;}  
        LL ans=China(n);  
        printf("%I64d\n",ans);  
  
    }  
    return 0;  
} 
