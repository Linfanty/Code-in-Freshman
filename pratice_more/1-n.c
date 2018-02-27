#include<stdio.h>
#include<string.h>
void print(int n,int a[],int cur)
{int i,j;
if(cur==n)//边界 
{for (i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");}
     
     else for(i=1;i<=n;i++)//向a[cur]中填数 
     {int OK=1;
     for(j=0;j<cur;j++)
     {if(a[j]==i)
     OK=0;
     } 
     
     if(OK)//如果i在a【0】~a【cur-1】中出现，则不再选 
     {a[cur]=i;
     print(n,a,cur+1);
     }
 }

}
int main()
{int n=5,a[n];
print(n,a,0);
getchar();     
      }
