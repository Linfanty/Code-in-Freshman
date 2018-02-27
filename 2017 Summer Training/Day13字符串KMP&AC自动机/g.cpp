#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
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

void kmp(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        int tmp = i - next[i-1]; /// 可循环的循环节每一节的个数 是否可以被整除
        if( tmp == 0) /// 可以整除 说明有循环节
            continue;
        if( i % tmp == 0 && i / tmp > 1)
            printf("%d %d\n", i,i/ tmp); /// 可以被划分为几个部分
    }
}

char p[1000005];

int main()
{
    int w = 1, t;
    while( scanf("%d", &t)!= EOF && t )
    {
        scanf("%s", p);
        makeNext(p);
        printf("Test case #%d\n",w++);
        kmp(strlen(p));
        printf("\n");
    }
    return 0;
}

