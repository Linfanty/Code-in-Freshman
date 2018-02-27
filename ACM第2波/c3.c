#include"iostream"
using namespace std;
int main()
{
int k,i,j,p,l=1;
long int a[2002],b[2002],m1,m2,n1,n2,x1,x[2002],y[2002],range[2002][3],distance1=0,distance2=0;
long int sum=0,min=1000000;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(x,0,sizeof(x));
memset(y,0,sizeof(y));
memset(range,0,sizeof(range));
cin>>k>>m1>>n1>>m2>>n2;
for(i=1;i<=k;i++)
cin>>x[i]>>y[i];
for(i=1;i<=k;i++)
{
distance1=(x[i]-m1)*(x[i]-m1);
distance2=(y[i]-n1)*(y[i]-n1);
range[i][1]=distance1+distance2;

distance1=(x[i]-m2)*(x[i]-m2);
distance2=(y[i]-n2)*(y[i]-n2);
range[i][2]=distance1+distance2;

}

sort(range,range+k);
/*
for(i=k;i>=1;i--)
for(j=1;j<=k;j++)
{

if(l==1&&sum<=min)
min=sum;
l=1;
}
*/
cout<<min;    
system("pause");
return 0;
}
