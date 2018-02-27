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







/*

#include "stdafx.h"  
#include<iostream>  
using namespace std;  
struct   
{  
    int year;  
  
    int month;  
  
    int day;  
}date;  
int main()  
{  
    int days,i;  
  
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //定义一个数组  用来存放每个月的天数   
  
    cout<<"请输入年月日，比如2012 12 12："<<endl;  
  
    cin>>date.year>>date.month>>date.day;  
  
    for(i=1;i<date.month;i++)  //天数相加  
    {  
        days=days+a[i];  
    }  
  
    days=days+date.day;   
  
    if((((date.year%4==0)&&(date.year%100!=0))||(date.year%400==0))&&date.month>=3)  //若是闰年的情况 月份在二月之后 天数加1  
    {  
        days=days+1;//daya+=1  
    }  
  
    cout<<date.month<<"月"<<date.day<<"月是"<<date.year<<"年中的第"<<days<<"天"<<endl;  //输出月  天数。  
  
    return 0;  
}
*/
