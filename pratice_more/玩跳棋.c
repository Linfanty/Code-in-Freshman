//ÍæÌøÆå
#include <stdio.h>
int main()
{  int x,y,t,m;
   scanf("%d%d",&x,&y);
   
   while(x!=0)
   {if(y>x)
   {t=y;y=x;x=t;}
   else x=x-y;
   m++;
   if(m>10000) 
   break;           
   }   
   
   if(m>10000)
   printf("N/A");
   else printf("%d",y);
   //system("pause");
    return 0;
} 
