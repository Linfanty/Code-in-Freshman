#include<stdio.h>
#include<string.h>
int main()
{
//memset(c,0,sizeof(c));    
long int n,k=0;
  
scanf("%ld",&n);

if(n%5==0)
printf("%ld",n/5);
else printf("%ld",((long int)n/5)+1);
    
    
    
    
system("pause");    
return 0;    
}
