/*思路分析
动态规划求出以每个人结尾的左边和右边的最大队列长度
枚举每个人为“中心点”，计算出满足题目要求的队列长度，记录最大值
我们用left[i]表示从左边起到第i个人结束的最长上升队列的人数，那么得到最优解的结构：left[i] = max{max(left[k] + 1), 1} 0<=k<=i-1 && a[k] < a[i]
同样的，用right[i]表示从右边起到第i个人结束的最大上升队列的人数，得到：right[i] = max{max(right[k] + 1), 1} i + 1 <= k <= n - 1 && a[k] < a[i]
有点类似0-1背包问题，关键是总结出最优解的结构
*/
#include <stdio.h>
#include <stdlib.h>
 
int a[101]; // 初始序列
int left_incr[101]; // 从左向右的最长序列
int right_incr[101];    // 从右向左的最长序列
 
 
 
int compare(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
 
    return *a - *b;
}
 
 
int main()
{
    int i, j, n, count;
 
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
 
        left_incr[0] = 1;
        for (i = 1; i < n; i ++) {
            left_incr[i] = 1;
            for (j = 0; j < i; j ++) {
                if (a[i] > a[j]) {
                    left_incr[i] = (left_incr[i] > left_incr[j] + 1) ? left_incr[i] : left_incr[j] + 1;
                }
            }           
        }
 
        right_incr[n - 1] = 1;
        for (i = n - 2; i >= 0; i --) {
            right_incr[i] = 1;
            for (j = n - 1; j > i; j --) {
                if (a[i] > a[j]) {
                    right_incr[i] = (right_incr[i] > right_incr[j] + 1) ? right_incr[i] : right_incr[j] + 1;
                }
            }
        }
        
        for (i = count = 0; i < n; i ++) {
            if (left_incr[i] + right_incr[i] - 1 > count) {
                count = left_incr[i] + right_incr[i] - 1;
                printf("%d\n",a[i]);
               // printf("%d %d\n",left_incr[i],right_incr[i]);
            }
        }
 
        printf("%d\n", n - count);
    }
     system("pause");
    return 0;
}
 
/**************************************************************
    Problem: 1131
    User: wangzhengyi
    Language: C
    Result: Accepted
    Time:740 ms
    Memory:916 kb
****************************************************************/
