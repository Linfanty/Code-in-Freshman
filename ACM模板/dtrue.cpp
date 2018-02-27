//dfs
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool found;
void DFS(unsigned __int64 t ,int n,int k)
 {
     if(found)
         return ;//如果已经发现了答案就没搜的必要了
     if(t%n==0)
     {//发现答案，输出，标记变量该true
         printf("%I64u\n",t);
         found=true;
         return ;
     }
     if(k==19)//到第19层，回溯
         return ;
/*
%llu unsigned 19位 20 位取不满用19位 
做题遇到范围是2^63，取模2^64的这种题目。遇到这种限制条件时就要想到用unsigned long long类型          
输出结果： 
9223372036854775807 9223372036854775807 
-9223372036854775808 9223372036854775808 
18446744073709551615 
*/  
     DFS(t*10,n,k+1);    //搜索×10
     DFS(t*10+1,n,k+1);    //搜索×10+1
 }
 int main()
 {
     int n;
     while(cin>>n,n)
     {
         found=false;//标记变量，当为true代表搜到了题意第一的m
         DFS(1,n,0);    //从1开始搜n的倍数，第三个参数代表搜的层数，当到第19层时返回（因为第20层64位整数存不下）
     }
     return 0;
 }
