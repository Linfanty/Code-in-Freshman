#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<stdio.h>
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 105;
using namespace std;

int n,k=1,flag;  

void dfs(ull m,int t)  
{  
	if(flag==0||t==19)  //���Ϊ19λ������ 
	return;
/*
%llu unsigned 19λ 20 λȡ������19λ 
����������Χ��2^63��ȡģ2^64��������Ŀ������������������ʱ��Ҫ�뵽��unsigned long long����          
�������� 
9223372036854775807 9223372036854775807 
-9223372036854775808 9223372036854775808 
18446744073709551615 
*/  
    if( m%n == 0)
	{cout<<m<<endl;  flag=0; return ;}

	dfs(m*10,t+1);
	dfs(m*10+1,t+1); 
} 
int main()
{
    while(scanf("%d",&n)!=EOF && n)
	{
		flag=1;
		//printf("%d\n",n);
      	dfs(1,0);
      //  printf("%d\n",m);
    }
    return 0;
}
