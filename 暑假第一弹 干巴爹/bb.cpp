#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b ? 1 : -1;
}
int a[1002], c[10000];
int main()
{
#ifdef test
    freopen("in.txt", "r", stdin);
#endif
    int num;
    while(scanf("%d", &num) != EOF)
    {
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < num; i++)
            scanf("%d", &a[i]);
        if(num != 1)
        {
            qsort(a, num, sizeof(a[0]), cmp);
            for(int i = 0; i < num; i++)
            cout << a[i] << ' ';
            for(int j = num - 1; j > 1;)
            {
                if(a[j - 1] + a[0] > a[1] * 2) // �ж�����������δ����С�ĺʹ��ڴ�С�������Ļ����ߵ�һ�����
                {
                    c[cnt++] = a[0];
                    c[cnt++] = a[1];
                    
                    sum += a[1];
                    
                    c[cnt++] = a[0];
                    
                    sum += a[0];
                    
                    c[cnt++] = a[j - 1];
                    c[cnt++] = a[j];
                    
                    sum += a[j] + a[1];
                    
                    c[cnt++] = a[1];
                    
                    j -= 2;
                }
                else              // �����ߵڶ���
                {
                    c[cnt++] = a[0];
                    c[cnt++] = a[j--];
                    
                    sum += a[j + 1] + a[0];
                    
                    c[cnt++] = a[0];
                    cout << "sum000:" << sum <<endl;
                }
				cout << "sum001:" << sum <<endl;
            }
            cout << "sum:" << sum <<endl;
            c[cnt++] = a[0];
            c[cnt++] = a[1];
            sum += a[1];
            printf("%d\n",sum);
            for(int i = 0, j = 0; i < cnt; j++)
                if(j % 2)
                    printf("%d\n", c[i++]);
                else
                {
                    printf("%d %d\n", c[i], c[i + 1]);
                    i += 2;
                }
        }
        else // ע��ֻ��һ���˹��ŵ����Ҫ���⴦����Ϊ���WA�����黹�����˺ܶ�ʱ�䣬�о��ر��
            printf("%d\n%d\n", a[0], a[0]);
    }
    return 0;
}
