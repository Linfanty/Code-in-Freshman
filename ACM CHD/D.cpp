#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
int t,k,n,sum=0;
int i,j;
int a[100],b[100];
char ch;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
scanf("%d",&t);
   /*
    for(i=0;i<t;i++)
 {scanf("%d%d",&n[i],&k[i]);
 scanf("%c",&ch);
 }
 */
    for(i=0;i<t;i++)
    {
     scanf("%d%d",&n,&k);
     for(j=0;j<n;j++)
         {scanf("%c",&ch);
         b[ch-65]++;
         }
     sort(b,b+27,greater<int>());
     j=0;
     while(k>=b[j])
     {sum=sum+b[j]*b[j];
     k=k-b[j];
     j++;
     }
     sum+=k*k;
     for(j=0;j<26;j++)
     printf("%d ",b[j]);
printf("\n%d\n",sum);
     
    }   
  getchar();  
    system("pause");    
    return 0;    
}
