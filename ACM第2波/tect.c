#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 
//using namespace std;
int main()
{
char c[50];
int i;
memset(c,0,sizeof(c));
for(i=0;i<50;i++)     
printf("%c",c[i]);

system("pause");
return 0;
}
/*x1=0,x2=0,y1=0,y2=0,sum=0;
scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
long long int a=0,b=0;
a=abs(x2-x1);
b=abs(y2-y1);
if(x1==x2&&y1==y2)
printf("0");
else if(a>=b)

     printf("%lld",a);

else 
*/
