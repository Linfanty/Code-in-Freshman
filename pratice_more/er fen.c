#include<stdio.h>
int EF(int a[100],int x,int y,int v)
{int m;
while(x<y)
          {m=x+(y-x)/2;
          if(a[m]==v)
          return m;
          
          else if(a[m]>v)
          y=m;
          else x=m+1;
          
          }
    return -1;
    }
    
    
main()
{int i,n,m,a[1000];
FILE * in;
FILE * out;
in=fopen("in.txt","r");
out=fopen("out.txt","w");
fscanf(in,"%d",&a[0]);
n=a[0];
 for(i=0;i<n;i++)
 {fscanf(in,"%d",&a[i]);}  
EF(a,0,n,5); 
fprintf(out,"%d",m);
fclose(in);
fclose(out);    }
