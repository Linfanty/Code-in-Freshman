#include <stdio.h>  
  
int main()  
{  
     int h, i, j, n;  
     scanf("%d", &n);  
     if(n==1||n==2)  
     {  
         printf("1\n1");  
     }  
     else if(n==3)  
     {  
         printf("2\n1 3");  
     }  
     else if(n==4)  
     {  
         printf("4\n2 4 1 3");  
     }  
     else  
     {  
          printf("%d\n1", n);  
          for(i=3;i<=n;i+=2)  
          {  
              printf(" %d", i);  
          }  
          for(i=2;i<=n;i+=2)  
          {  
              printf(" %d", i);  
          }  
     }  
     return 0;  
}
