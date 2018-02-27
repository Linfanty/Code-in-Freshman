#include<stdio.h>
int main()
{
int t,s,x;
int i,j=0;
scanf("%d %d %d",&t,&s,&x);
if(x==t)
printf("YES");
else if(x!=t&&((x-t)>0)&&(x-t)%s==0)
printf("YES");

else if( x!=t&&(((x-t)-1)>0)&&( ((x-t)-1) %s)==0)
printf("YES");


else printf("NO");
system("pause");    
return 0;    
}
