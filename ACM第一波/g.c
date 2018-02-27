#include<stdio.h>
#include<string.h>
int main()
{
int n,a,b,k=0,num;
int i=0,j=0;
int c[205];
memset(c,0,sizeof(c));
scanf("%d %d %d",&n,&a,&b);
      if (n==1&&b!=0)
      printf("1");
      else if(b>0)
          {          
          for(i=1;i<=204;i++)
              { 
                c[i]=i-k*n;
                if (i%n==0)
                k++;
                
              }
          for(i=1;i<=b;i++)
              {a++;
              num=c[a];
                           
              }
              printf("%d",num);              
          }
else if(b<0)
       {          
          for(i=1;i<=n;i++)
              { 
                c[i]=i-k*n;
                if (i%n==0)
                k++;
                
              }
              b=-b;
          for(i=1;i<=b;i++)
              {            if(a==1)
                           {num=c[n];
                           a=n;
                           continue;}
                           else 
                           {a--;
                           num=c[a];
                           }
              }
              printf("%d",num);              
          }
      else 
      printf("%d",a);
system("pause");    
return 0;    
}
