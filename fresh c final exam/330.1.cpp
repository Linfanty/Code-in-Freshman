#include "stdio.h"
struct date 
{
    int year; 
    int month; 
    int day; 
}; 
/*�ж�����*/ 
int leap_year(int a)
{
    if(a%400==0||(a%4==0&&a%100!=0)) 
        return 1;
    else 
        return 0;
}
/*����һ���еĵڼ���*/ 

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
    printf("\n���������ڣ��� �� �գ�\n"); 
    scanf("%d%d%d",&a.year,&a.month,&a.day); 
    n=cal_day(a);
    printf("�����ڱ������ǵ�%d��\n",n);
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
  
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //����һ������  �������ÿ���µ�����   
  
    cout<<"�����������գ�����2012 12 12��"<<endl;  
  
    cin>>date.year>>date.month>>date.day;  
  
    for(i=1;i<date.month;i++)  //�������  
    {  
        days=days+a[i];  
    }  
  
    days=days+date.day;   
  
    if((((date.year%4==0)&&(date.year%100!=0))||(date.year%400==0))&&date.month>=3)  //������������ �·��ڶ���֮�� ������1  
    {  
        days=days+1;//daya+=1  
    }  
  
    cout<<date.month<<"��"<<date.day<<"����"<<date.year<<"���еĵ�"<<days<<"��"<<endl;  //�����  ������  
  
    return 0;  
}
*/
