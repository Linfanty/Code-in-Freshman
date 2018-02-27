//Ìú¹ì 
#include<stdio.h>
//const int MAXN=50;
int n; 
int main()
{
    while(scanf("%d",&n)==1)
    {
    int target[1010],stack[1010],top=0;
    int A=1,B=1,i;
    for(i=1;i<=n;i++)
      scanf("%d",&target[i]);
    int ok=1;  
    while(B<=n)
               {if(A==target[B])
               {A++;B++;}
               
               else if(top&&stack[top]==target[B])
               {top--;B++;}
               
               else if(A<=n) 
               stack[++top]=A++;
               
               else{ok=0;break;}
               }
     printf("%s",ok?"Yes":"No") ;   
    }    
 
 system("pause");
 return 0;
}

