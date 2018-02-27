#include<stdio.h>
#include<string.h>
int main()
{
int n,i,j=0;
int c[105];
int before,after;
memset(c,0,sizeof(c));    
scanf("%d",&n);
for(i=0;i<n;i++)
                {scanf("%s %d %d",c,&before,&after);
                if(before>=2400&&(before<after))          
                    {printf("YES");
                    j++;
                    break;}   
                }    
if(j==0) 
printf("NO");
    
   
system("pause");    
return 0;    
}
