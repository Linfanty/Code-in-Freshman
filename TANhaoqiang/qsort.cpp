#include"iostream"
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib> 

using namespace std;
int main()
{
int a[10],n,i;
cin>>n;
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(i=0;i<n;i++)
cout<<a[i]<<' ';    
system("pause");
return 0;
}
