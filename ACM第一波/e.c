#include<stdio.h>
#include<string.h>
int main()
{
int n,h,sum=0;
int i=0,j=0;
int c[1005];
memset(c,0,sizeof(c));
scanf("%d %d",&n,&h);
for(i=0;i<n;i++)
{
scanf("%d",&c[i]);
if(c[i]>h)
sum++;
sum++;

}


printf("%d",sum);
system("pause");    
return 0;    
}
