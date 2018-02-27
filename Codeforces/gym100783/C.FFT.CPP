#include<bits/stdc++.h>

using namespace std;

const int N = 1200040;
const double pi = acos(-1.0);

int len;

struct Complex
{
    double r,i;
    Complex(double r=0,double i=0):r(r),i(i) {};
    Complex operator+(const Complex &rhs)
    {
        return Complex(r + rhs.r,i + rhs.i);
    }
    Complex operator-(const Complex &rhs)
    {
        return Complex(r - rhs.r,i - rhs.i);
    }
    Complex operator*(const Complex &rhs)
    {
        return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);
    }
} va[N],vb[N];

void rader(Complex F[],int len) //len = 2^M,reverse F[i] with  F[j] j为i二进制反转
{
    int j = len >> 1;
    for(int i = 1;i < len - 1;++i)
    {
        if(i < j) swap(F[i],F[j]);  // reverse
        int k = len>>1;
        while(j>=k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void FFT(Complex F[],int len,int t)
{
    rader(F,len);
    for(int h=2;h<=len;h<<=1)
    {
        Complex wn(cos(-t*2*pi/h),sin(-t*2*pi/h));
        for(int j=0;j<len;j+=h)
        {
            Complex E(1,0); //旋转因子
            for(int k=j;k<j+h/2;++k)
            {
                Complex u = F[k];
                Complex v = E*F[k+h/2];
                F[k] = u+v;
                F[k+h/2] = u-v;
                E=E*wn;
            }
        }
    }
    if(t==-1)   //IDFT
        for(int i=0;i<len;++i)
            F[i].r/=len;
}

void Conv(Complex a[],Complex b[],int len) //求卷积
{
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;++i) a[i] = a[i]*b[i];
    FFT(a,len,-1);
}
int n;
int a[N];
long long num[N],sum[N];

//给你n个数，然后再给你一个数k,问这个数是否就是那n个数中的一个，或
//者说这个数可以由这n个数中的两个构成（可以是自己*2）
void solve()
{
    memset(num,0,sizeof(num));memset(sum,0,sizeof(sum));memset(va,0,sizeof(va));memset(vb,0,sizeof(vb));
    // num sum va vb
    int Mx = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        Mx = max(Mx,a[i]);//算最大值
        num[a[i]]=1; // 标记num
    }

    Mx*=2;
    len=1;
    while(len<=Mx+1)len*=2;
    sort(a,a+n);

    for(int i=0;i<=len;i++)
    {
        va[i].r=num[i];
        va[i].i=0;
        vb[i].r=va[i].r;
        vb[i].i=0;
    }

    Conv(va,vb,len);
    for(int i=0;i<len;i++)
        num[i]+=(long long)(va[i].r+0.5);

    int cnt = 0;
    int q;scanf("%d",&q);

    while(q--){
        int bbb;
        scanf("%d",&bbb);
        if(num[bbb])cnt++;
    }
    printf("%d\n",cnt);
}
int main()
{
    while(scanf("%d",&n)!=EOF)solve();
    return 0;
}
