 #include<cstdio>
  #include<iostream>
  #include<cstring>
  #include<string.h>
  using namespace std;

 #define MOD 1000000007

  long long quick_mod(long long a,long long b,long long m)//快速幂，复杂度log2n
 {
     long long ans=1;
     while(b)
     {
         if(b&1)
        {
             ans=(ans*a)%m;
             b--;
         }
         b/=2;
         a=a*a%m;
     }
     return ans;
 }

 int main()
 {

     char str[100010];
     long long sum;
     int len,i;
     long long M=MOD-1;
     while(scanf("%s",str)!=EOF)
     {
         len=strlen(str);
         sum=0;
         for(i=0;i<len;i++)
         {
             sum=sum*10+(str[i]-'0');
             sum=sum%M;//费马小定理
         }
         cout << sum <<endl;

        printf("%lld\n",quick_mod(2,(sum-1),MOD));//快速幂
     }
     return 0;
}
