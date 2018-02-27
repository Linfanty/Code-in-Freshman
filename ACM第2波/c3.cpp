#include<iostream>
#include<algorithm>
#include<cstring>
/*Sortt函数的第三个参数可以用这样的语句告诉程序你所采用的排序原则

less<数据类型>()//从小到大排序

greater<数据类型>()//从大到小排序
sort(a,a+10,greater<int>());
字符排序sort(a,a+10,greater<char>());
*/
using namespace std;
int main()
{
int k,i,j,p,l=1;
long int a[2002],b[2002],m1,m2,n1,n2,x1,x[2002],y[2002],range[3][2003],distance1=0,distance2=0;
long int sum=0,min=1000000;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(x,0,sizeof(x));
memset(y,0,sizeof(y));
memset(range,0,sizeof(range));
cin>>k>>m1>>n1>>m2>>n2;
for(i=0;i<k;i++)
cin>>x[i]>>y[i];
for(i=0;i<k;i++)
{
distance1=(x[i]-m1)*(x[i]-m1);
distance2=(y[i]-n1)*(y[i]-n1);
range[1][i]=distance1+distance2;

distance1=(x[i]-m2)*(x[i]-m2);
distance2=(y[i]-n2)*(y[i]-n2);
range[2][i]=distance1+distance2;
} 
sort(range[1],range[1]+k,greater<int>());//range[1]+k+1
for(j=0;j<k;j++)
cout<<range[1][j]<<' '; 
cout<<endl;
for(j=0;j<k;j++)
cout<<range[2][j]<<' '; 
  
system("pause");
return 0;
}
