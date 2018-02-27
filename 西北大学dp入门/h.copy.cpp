#include<iostream>
#include<cstdio>
/*
˼·�������������С�����˳��
��nΪ����ʱ����һ��������Ϊ1����ʱf(n)=f(n-1)��

��nΪż��ʱ��������������ۣ�
����һ����Ϊ1����f(n)=f(n-1)��
����һ������Ϊ������������������Ϊ������
���һ��������2����������f(n/2)��

���ԣ�f(n)=f(n-1)+f(n/2)
*/
const int mod = 1e9;  
const int maxn = 1000001;  
    
int f[maxn];  
    
int main()  
{  
    int n, i;  
    f[1] = 1, f[2] = 2;  
    for (i = 3; i < maxn; ++i)  
        f[i] = (i & 1 ? f[i - 1] : (f[i - 2] + f[i >> 1]) % mod) ;  
    while (~scanf("%d", &n))  
        printf("%d\n", f[n]);  
    return 0;  
}
/*
using namespace std;  
 int n,num[1000001],t[10];  
 int main()  
 {  
      int i;  
      while(scanf("%d",&n)!=EOF)  
      {  
           num[1]=1;  
           num[2]=2;  
           for (i=3;i<=n;i++)  
           {  
                if(i%2==1)  num[i]=num[i-1];  
                if(i%2==0)  num[i]=(num[i-1]+num[i/2])%1000000000;  
            }  
           printf ("%d\n",num[n]);  
  
      }  
      return 0;  
}  

*/
