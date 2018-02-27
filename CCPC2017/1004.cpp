#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int next[1000005] = {0};

/// "部分匹配值"就是"前缀"和"后缀"的最长的共有元素的长度
/// 移动位数 = 已匹配的字符数 - 对应的部分匹配值
void makeNext (const char p[])
{
    int q, k;// q:模版字符串下标；k:最大前后缀长度
    int m = strlen(p); // 模板字符串长度
    next[0] = 0; // 模板字符串的 第一个字符的最大的前后缀长度为0
    for(q = 1, k = 0; q < m ; ++q )
    {// 第二个字符开始 依次计算每一个字符对应的next值
        while ( k > 0 && p[q] != p[k] )
        // 递归求出 p[0] .. p[q] 的最大的相同前后缀 长度k
            k = next[k-1]; // 往前回溯
        if( p[q] == p[k] ) //如果相等，那么最大相同前后缀长度加1
            k++;
        next[q] = k;
       //cout << q << ' ' << k << endl;
    }
}

int kmp(char t[],char p[])
{
    int n = strlen(t), m = strlen(p);
    int cnt = 0;
    makeNext(p);
    for(int i = 0, q = 0; i < n; ++i)
    {
        while( q > 0 && p[q] != t[i])
            q = next[q-1];
        if( p[q] == t[i] )
            q++;
        if( q == m)
            cnt++;
         cout << i << ' ' << q <<' ' << cnt <<  endl;
    }
    return cnt;
}
/// sum = (sum+((1+j)*j/2)%mod)%mod;

char t[ 1000005 ], p[ 1000005], pp[1000005];
int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s", t);
        scanf("%s", p);
        int len = strlen(p);
        for(int i = 0; i < len/2 ; ++i)
            swap(p[i], p[len-1-i]);

        long long int sum = 0;
        for(int i = 1; i <= len ; i++)
        {
            memset(pp, 0, sizeof(pp));
            strncpy(pp, p + 0, i);

            int lenn = strlen(pp);
            for(int i = 0; i < lenn/2 ; ++i)
                swap(pp[i], pp[lenn-1-i]);

            //cout << pp << ' ' <<kmp(t,pp)<< endl;
            sum += i * kmp(t, pp);
            //cout << sum << ' ';
            sum %= 1000000007;
        }
        printf("%lld\n",sum);
        //printf("%d\n",kmp(t, p));
    }
    return 0;
}

