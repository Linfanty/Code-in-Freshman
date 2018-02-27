#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
char a[100050];
int dp[100050][2];
int main()
{
    while(~scanf("%s",a))
    {
        int n=strlen(a);
        for(int i=0;i<n;i++)
        {
            if(islower(a[i]))
            {
                dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=dp[i-1][1]+1;
            }
            else
            {
                dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1;
                dp[i][1]=dp[i-1][1];
            }
        }
        printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
    }
}
/*
1、考虑dp，设定dp【i】【2】，其中dp【i】【0】表示dp到第i位，当前字母变成了小写字母的最小花费，其中dp【i】【1】表示dp到第i位，当前字母变成了大写字母的最小花费。


2、那么不难推出其状态转移方程：
if（当前字母为小写字母）

dp【i】【0】=min（dp【i-1】【0】，dp【i-1】【1】）；

dp【i】【1】=dp【i-1】【1】+1；

else（即当前字母为大写字母）

dp【i】【0】=min（dp【i-1】【0】，dp【i-1】【1】）+1；

dp【i】【1】=dp【i-1】【1】；

其最终解为min（dp【n-1】【0】，dp【n-1】【1】）；

