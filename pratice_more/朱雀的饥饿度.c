//ÖìÈ¸µÄ¼¢¶ö¶È
#include <stdio.h>
int main()
{   int s,n,i,j=1000,j1,p,k,count=0;
    scanf("%d",&s); 
    scanf("%d",&n); 
    int a,b[111],c[111];
    scanf("%d",&a);
           
           for(i=1;i<=a;i++)
           {
           scanf("%d",&k);
                         for(j1=1;j1<=k;j1++)
                        {scanf("%d %d",&b[j1],&c[j1]);
                        // count=c[1];
                         if(s>=10500)
                         break;
                          s=s+c[j1];

                                     if(c[j1]>count)
                                         {
                                         count=c[j1];
                                         j=b[j1];
                                         continue;
                                         }
                          if(c[j1]==count&&b[j1]<j)
                          j=b[j1];
                          }
           if(s>=10500)
           break;
           }     
     

      if(s<10500)
      printf("Wrong Data");
 else printf("%d\n%d",i,j);

   system("pause");
    return 0;
} 
