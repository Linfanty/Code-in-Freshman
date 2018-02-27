//报名系统
#include <stdio.h>
#define max(a,b) a>b?a:b
char s[10000001];
int main()
{   long int m,n=0,i=0,b=0,s1,sum=0,sum1=0; 


    scanf("%d",&m);
    scanf("%s",&s);                
    for(i=0;i<m;i++)
    {
    if(s[i]=='B')
    b++;
    else if(s[i]=='N')
    n++;
    else
    { 
    if(b>=n)
    {n++;
    sum++;}
    else 
    {b++;
    sum1++;}
    }
    
    
     } 
 
 
 
 
    printf("%d:%d\n",n,b);
    if(sum>sum1)
    printf("NanPai");
else if(sum1>sum)
    printf("bEIpAI");
else printf("sUiJi");

    //for(i=0;i<=m;i++)
    //printf("%c",s[i]);
    
    //system("pause");
    return 0;
} 
