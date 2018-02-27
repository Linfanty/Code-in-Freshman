#include "stdio.h"
struct date 
{
    int year; 
    int month; 
    int day; 
}; 
/*判断闰年*/ 
int leap_year(int a)
{
    if(a%400==0||(a%4==0&&a%100!=0)) 
        return 1;
    else 
        return 0;
}
/*计算一年中的第几天*/ 

int cal_day(struct date a) 
{

    int sum=0,b[]={31,28,31,30,31,30,31,31,30,31,30,31} ;

    for(int i=0;i<a.month-1;i++) 

        sum+=b[i]; 

    if(a.month>2)

        sum=sum+a.day+leap_year(a.year); 

    else

        sum=sum+a.day;

    return sum; 

} 
int main()
{
    struct date a;
    int n;
    printf("\n请输入日期（年 月 日）\n"); 
    scanf("%d%d%d",&a.year,&a.month,&a.day); 
    n=cal_day(a);
    printf("该日在本年中是第%d天\n",n);
    return 0;
}


