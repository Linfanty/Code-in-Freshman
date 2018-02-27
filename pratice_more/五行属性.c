//ÎåĞĞÊôĞÔ 
#include <stdio.h>
#define max(a,b) a>b?a:b
int main()
{   int a[11][31],b[11][31],sum=0,sum1=0; 
    int i,j;
for(j=1;j<=10;j++)
    for(i=1;i<=30;i++)
    scanf("%d",&a[j][i]);
for(j=1;j<=10;j++)
    for(i=1;i<=30;i++) 
    {scanf("%d",&b[j][i]);                

sum=(a[j][i]*(100/b[j][i]));
sum1=sum+sum1; 
    }
 
 
 
    printf("%ld\n",sum1);
    system("pause");
    return 0;
} 
