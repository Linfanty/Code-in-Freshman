#include<stdio.h>
#include<string.h>
void print(int n,int a[],int cur)
{int i,j;
if(cur==n)//�߽� 
{for (i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");}
     
     else for(i=1;i<=n;i++)//��a[cur]������ 
     {int OK=1;
     for(j=0;j<cur;j++)
     {if(a[j]==i)
     OK=0;
     } 
     
     if(OK)//���i��a��0��~a��cur-1���г��֣�����ѡ 
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
