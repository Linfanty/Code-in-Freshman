#include"iostream"
using namespace std;
int main()
{
int k,i,j,p,l=1;
long int a[2002],b[2002],m1,m2,n1,n2,x1,x[2002],y[2002],range1[2002],range2[2002],distance1=0,distance2=0;
long int sum=0,min=1000000;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(x,0,sizeof(x));
memset(y,0,sizeof(y));
memset(range1,0,sizeof(range1));
memset(range2,0,sizeof(range2));
cin>>k>>m1>>n1>>m2>>n2;
for(i=1;i<=k;i++)
cin>>x[i]>>y[i];
for(i=1;i<=k;i++)
{
distance1=(x[i]-m1)*(x[i]-m1);
distance2=(y[i]-n1)*(y[i]-n1);
range1[i]=distance1+distance2;

}
sort(range1,range1+k);
for(i=1;i<=k;i++)
{
distance1=(x[i]-m2)*(x[i]-m2);
distance2=(y[i]-n2)*(y[i]-n2);
range2[i]=distance1+distance2;
}
sort(range2,range2+k);
for(i=k;i>=1;i--)
for(j=1;j<=k;j++)
{
sum=range1[i]+range2[j];
/*if(sum==0)
break;
     for(p=1;p<=k;p++)
    {if(range2[p]<=range1[p])
        {//(range1[p]>range1[i]&&range2[p]>range2[j])||(range1[p]>range2[j]&&range2[p]>range1[i]))
         if(range2[p]>range2[j])
        l=1;
        }
       else if(range1[p]>range1[i]||range1[p]>range2[j])
       l=1;
    }
    if(l==1)
    {l=0;
    continue;
    }
*/
for(p=1;p<=k;p++)
    {
     if(range1[p]>range1[i]&&range2[k-p+1]>range2[k-i+1])
    {l=0;
    break;}
    }
if(l==1&&sum<=min)
min=sum;
l=1;
}
cout<<min;    
system("pause");
return 0;
}
