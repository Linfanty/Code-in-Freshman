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
1������dp���趨dp��i����2��������dp��i����0����ʾdp����iλ����ǰ��ĸ�����Сд��ĸ����С���ѣ�����dp��i����1����ʾdp����iλ����ǰ��ĸ����˴�д��ĸ����С���ѡ�


2����ô�����Ƴ���״̬ת�Ʒ��̣�
if����ǰ��ĸΪСд��ĸ��

dp��i����0��=min��dp��i-1����0����dp��i-1����1������

dp��i����1��=dp��i-1����1��+1��

else������ǰ��ĸΪ��д��ĸ��

dp��i����0��=min��dp��i-1����0����dp��i-1����1����+1��

dp��i����1��=dp��i-1����1����

�����ս�Ϊmin��dp��n-1����0����dp��n-1����1������

