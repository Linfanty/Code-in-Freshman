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
         return ;//����Ѿ������˴𰸾�û�ѵı�Ҫ��
     if(t%n==0)
     {//���ִ𰸣��������Ǳ�����true
         printf("%I64u\n",t);
         found=true;
         return ;
     }
     if(k==19)//����19�㣬����
         return ;
/*
%llu unsigned 19λ 20 λȡ������19λ 
����������Χ��2^63��ȡģ2^64��������Ŀ������������������ʱ��Ҫ�뵽��unsigned long long����          
�������� 
9223372036854775807 9223372036854775807 
-9223372036854775808 9223372036854775808 
18446744073709551615 
*/  
     DFS(t*10,n,k+1);    //������10
     DFS(t*10+1,n,k+1);    //������10+1
 }
 int main()
 {
     int n;
     while(cin>>n,n)
     {
         found=false;//��Ǳ�������Ϊtrue�����ѵ��������һ��m
         DFS(1,n,0);    //��1��ʼ��n�ı��������������������ѵĲ�����������19��ʱ���أ���Ϊ��20��64λ�����治�£�
     }
     return 0;
 }
