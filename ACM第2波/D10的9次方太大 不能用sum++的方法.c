#include<stdio.h>
#include<string.h>
int main()
{
long long int x1=0,x2=0,y1=0,y2=0,sum=0;
scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
if(x1==x2&&y1==y2)
printf("0");

while(x1!=x2||y1!=y2)
{
if(x2-x1>=1&&y2-y1>=1)
    {
    x1++;
    y1++;
    sum++;}
if(x2-x1>=1&&y1-y2>=1)
    {
    x1++;
    y1--;
    sum++;}
if(x1-x2>=1&&y1-y2>=1)
    {
    x1--;
    y1--;
    sum++;}
if(x1-x2>=1&&y2-y1>=1)
    {
    x1--;
    y1++;
    sum++;}
if(x2-x1>=1&&y1==y2)
{
x1++;
sum++;                   
}
if(x1-x2>=1&&y1==y2)
{
x1--;
sum++;                   
}
if(y2-y1>=1&&x1==x2)
{
y1++;
sum++;                   
}
if(y1-y2>=1&&x1==x2)
{
y1--;
sum++;                   
}

if(  (x2-x1==1&&y2==y1) || (x1-x2==1&&y2==y1) || (y2-y1==1&&x2==x1)|| (y1-y2==1&&x2==x1)  )
{
sum++;
break;
}
    
}
printf("%lld",sum);   
system("pause");
return 0;
}
