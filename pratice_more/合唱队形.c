/*˼·����
��̬�滮�����ÿ���˽�β����ߺ��ұߵ������г���
ö��ÿ����Ϊ�����ĵ㡱�������������ĿҪ��Ķ��г��ȣ���¼���ֵ
������left[i]��ʾ������𵽵�i���˽�������������е���������ô�õ����Ž�Ľṹ��left[i] = max{max(left[k] + 1), 1} 0<=k<=i-1 && a[k] < a[i]
ͬ���ģ���right[i]��ʾ���ұ��𵽵�i���˽���������������е��������õ���right[i] = max{max(right[k] + 1), 1} i + 1 <= k <= n - 1 && a[k] < a[i]
�е�����0-1�������⣬�ؼ����ܽ�����Ž�Ľṹ
*/
#include <stdio.h>
#include <stdlib.h>
 
int a[101]; // ��ʼ����
int left_incr[101]; // �������ҵ������
int right_incr[101];    // ��������������
 
 
 
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
