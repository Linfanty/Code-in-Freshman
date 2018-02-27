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
	if(flag==0||t==19)  //最大为19位的数字 
	return;
/*
%llu unsigned 19位 20 位取不满用19位 
做题遇到范围是2^63，取模2^64的这种题目。遇到这种限制条件时就要想到用unsigned long long类型          
输出结果： 
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
