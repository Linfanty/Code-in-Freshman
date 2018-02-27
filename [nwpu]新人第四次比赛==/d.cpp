#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
const int maxn = 10;
using namespace std;


int main()
{
	char a[1000],b[1000],c[1000];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int n,n1;
	scanf("%s ",a);
	scanf("%s",b);
	
	int i,j;
	for(i=0;i<maxn;i++)
		printf("%c %c\n",a[i],b[i]);	
	for(i=0;i<maxn;i++)
	{
		c[i]=a[i]+b[i]-'0';
		if(c[i]-'0'>=10)
		{
			c[i+1]=(c[i]-'0')/10+'0';
			c[i]=c[i]-10;	
		}
		
	}
	for(j=maxn;j>=0;j--)
		if(c[j]) break;  //忽略f[]数组的前导0  4
	for(i=j;i>=0;i--)
			printf("%c",c[i]);	
	return 0;
}
